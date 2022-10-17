/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:04:13 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/17 22:17:26 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
# define RBT_HPP

# include <algorithm>
# include <memory>
# include <cstddef>
# include <iomanip>
# include <utility>
# include <string>
# include <sstream>


template<class T>
struct	Node
{
	int		color;
	T		key;
	Node	*leftChild;
	Node	*rightChild;
	Node	*parent;
};

template<class T, class Allocator = std::allocator<Node<T> > >
class	red_black_tree
{
	private:

		Allocator	_alloc;
		Node<T>		*_root;
		Node<T>		*_nil;
		size_t		_size;

	public:

		red_black_tree()
		{
			_nil = _alloc.allocate(1);
			_nil->color = 0;
			_nil->leftChild = NULL;
			_nil->rightChild = NULL;
			_nil->parent = NULL;
			_root = _nil;
			_size = 0;
		};

		~red_black_tree()
		{
			while (_root != _nil && _root->leftChild != _nil)
				delete_node(rbt_min(_root));
			if (_root != _nil && _root->rightChild != _nil)
				_alloc.deallocate(_root->rightChild, 1);
			if (_root != _nil)
				_alloc.deallocate(_root, 1);
			_alloc.deallocate(_nil, 1);
		};

		Node<T> *getRoot() {
			return this->_root;
		};

		size_t	size()
		{
			return (_size);
		}

		Node<T> *rbt_search(Node<T> *node, int key)
		{
			if (node == _nil || key == node->key)
				return node;
			if (key < node->key)
				return rbt_search(node->leftChild, key);
			return rbt_search(node->rightChild, key);
		};

		Node<T> *searchTree(int k) {
			return rbt_search(this->_root, k);
		};

		void	left_rotate(Node<T> *x)
		{
			Node<T>	*y = x->rightChild;

			x->rightChild = y->leftChild;
			if (y->leftChild != _nil)
				y->leftChild->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				_root = y;
			else if (x == x->parent->leftChild)
				x->parent->leftChild = y;
			else
				x->parent->rightChild = y;
			y->leftChild = x;
			x->parent = y;
		};

		void	right_rotate(Node<T> *x)
		{
			Node<T>	*y = x->leftChild;

			x->leftChild = y->rightChild;
			if (y->rightChild != _nil)
				y->rightChild->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				_root = y;
			else if (x->parent->rightChild == x)
				x->parent->rightChild = y;
			else
				x->parent->leftChild = y;
			y->rightChild = x;
			x->parent = y;
		};

		void	insert(T key)
		{
			Node<T>	*z = _alloc.allocate(1);
			Node<T>	*y = NULL;
			Node<T>	*x = _root;

			z->parent = NULL;
			z->key = key;
			z->leftChild = _nil;
			z->rightChild = _nil;
			z->color = 1;

			while (x != _nil)
			{
				y = x;
				if (z->key < x->key)
					x = x->leftChild;
				else
					x = x->rightChild;
			}
			z->parent = y;
			if (y == NULL)
				_root = z;
			else if (z->key < y->key)
				y->leftChild = z;
			else
				y->rightChild = z;

			_size++;
			if (z->parent == NULL)
			{
				z->color = 0;
				return;
			}
			if (z->parent->parent == NULL)
				return;
			insert_fix(z);
		};

		void	insert_fix(Node<T> *z)
		{
			Node<T>	*y;

			while (z->parent->color == 1)
			{
				if (z->parent == z->parent->parent->leftChild)
				{
					y = z->parent->parent->rightChild;
					if (y->color == 1)
					{
						z->parent->color = 0;
						y->color = 0;
						z->parent->parent->color = 1;
						z = z->parent->parent;
					}
					else
					{
						if (z == z->parent->rightChild)
						{
							z = z->parent;
							left_rotate(z);
						}
						z->parent->color = 0;
						z->parent->parent->color = 1;
						right_rotate(z->parent->parent);
					}
				}
				else
				{
					y = z->parent->parent->leftChild;
					if (y->color == 1)
					{
						z->parent->color = 0;
						y->color = 0;
						z->parent->parent->color = 1;
						z = z->parent->parent;
					}
					else
					{
						if (z == z->parent->leftChild)
						{
							z = z->parent;
							right_rotate(z);
						}
						z->parent->color = 0;
						z->parent->parent->color = 1;
						left_rotate(z->parent->parent);
					}
				}
				if (z == _root)
				{
					break;
				}
			}
			_root->color = 0;
		};

		void	transplant(Node<T> *u, Node<T> *v)
		{
			if (u->parent == _nil)
				_root = v;
			else if (u == u->parent->leftChild)
				u->parent->leftChild = v;
			else
				u->parent->rightChild = v;
			v->parent = u->parent;
		};

		Node<T>	*rbt_min(Node<T> *x)
		{
			while (x->leftChild != _nil)
				x = x->leftChild;
			return x;
		};

		void	delete_node(Node<T> *z)
		{
			Node<T>	*x;
			Node<T>	*y;
			y = z;
			int	color = y->color;

			if (z->leftChild == _nil)
			{
				x = z->rightChild;
				transplant(z, z->rightChild);
			}
			else if (z->rightChild == _nil)
			{
				x = z->leftChild;
				transplant(z, z->leftChild);
			}
			else
			{
				y = rbt_min(z->rightChild);
				color = y->color;
				x = y->rightChild;
				if (y->parent == z)
					x->parent = y;
				else
				{
					transplant(y, y->rightChild);
					y->rightChild = z->rightChild;
					y->rightChild->parent = y;
				}
				transplant(z, y);
				y->leftChild = z->leftChild;
				y->leftChild->parent = y;
				y->color = z->color;
			}
			_alloc.deallocate(z, 1);
			_size--;
			if (color == 0)
				delete_fix(x);
		};

		void	delete_fix(Node<T> *x)
		{
			Node<T>	*w;
			while (x != _root && x->color == 0)
			{
				if (x == x->parent->leftChild)
				{
					w = x->parent->rightChild;
					if (w->color == 1)
					{
						w->color = 0;
						x->parent->color = 1;
						left_rotate(x->parent);
						w = x->parent->rightChild;
					}
					if (w->leftChild->color == 0 && w->rightChild->color == 0)
					{
						w->color = 1;
						x = x->parent;
					}
					else
					{
						if (w->rightChild->color == 0)
						{
							w->leftChild->color = 0;
							w->color = 1;
							right_rotate(w);
							w = x->parent->rightChild;
						}
						w->color = x->parent->color;
						x->parent->color = 0;
						w->rightChild->color = 0;
						left_rotate(x->parent);
						x = _root;
					}
				}
				else
				{
					w = x->parent->leftChild;
					if (w->color == 1)
					{
						w->color = 0;
						x->parent->color = 1;
						right_rotate(x->parent);
						w = x->parent->leftChild;
					}
					if (w->rightChild->color == 0 && w->rightChild->color == 0)
					{
						w->color = 1;
						x = x->parent;
					}
					else
					{
						if (w->leftChild->color == 0)
						{
							w->rightChild->color = 0;
							w->color = 1;
							left_rotate(w);
							w = x->parent->leftChild;
						}
						w->color = x->parent->color;
						x->parent->color = 0;
						w->leftChild->color = 0;
						right_rotate(x->parent);
						x = _root;
					}
				}
			}
			x->color = 0;
		};

		void	_print(Node<T> * node, std::stringstream &buffer, bool isTail, std::string prefix)
		{
			if (node->rightChild != _nil)
				_print(node->rightChild, buffer, false, std::string(prefix).append(isTail ? "│   " : "    "));
			buffer << prefix << (isTail ? "└── " : "┌── ");
			if (node->color == 1)
				buffer << "\033[31m";
			buffer << node->key << "\033[0m" << std::endl;
			if (node->leftChild != _nil)
				_print(node->leftChild, buffer, true, std::string(prefix).append(isTail ? "    " : "│   "));
		};

		void	print(void)
		{
			std::stringstream	buffer;

			std::cout << "size: " << this->_size << std::endl;
			if (_root != _nil)
			{
				_print(_root, buffer, true, "");
				std::cout << buffer.str();
			}
		};

};

#endif