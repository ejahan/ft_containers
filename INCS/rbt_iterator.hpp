/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 04:36:32 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/26 23:12:09 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

# include "node.hpp"

namespace	ft
{
	/*
	======================================================================================
	ITERATORS
	======================================================================================
	*/

	template<class T, class Allocator = std::allocator<Node<T> > >
	struct rbt_iterator
	{
		protected:

			ft::Node<T>		*_node;
			Allocator	_alloc;

			void Increment()
			{
				std::cout << "increment" << std::endl;
				if (_node == _node->_nil)
					return ;
				if (_node->rightChild != _node->_nil)
				{
					ft::Node<T> *temp = _node->rightChild;
					while (temp->leftChild != _node->_nil)
					{
						std::cout << "ici" << std::endl;
						temp = temp->leftChild;
					}
					_node = temp;

				}
				else
				{
					ft::Node<T> *tmp = _node->parent;
					if (tmp->rightChild ==_node)
					{
						while (_node == tmp->rightChild)
						{
							_node = tmp;
							tmp = tmp->parent;
						}
					}
					if (_node->rightChild != tmp)
						_node = tmp;
				}
			};

			void Decrement()
			{
				if (_node->parent->parent == _node && _node->color == 1)
				{
					_node = _node->leftChild;
					// j'ai pas compris l'interet
				}
				else if (_node->leftChild != _node->_nil)
				{
					_node = _node->leftChild;
					while (_node->rightChild != _node->_nil)
						_node = _node->rightChild;
				}
				else
				{
					ft::Node<T> *parent = _node->parent;
					while (parent->leftChild == _node)
					{
						_node = parent;
						parent = parent->parent;
					}
					_node = parent;
				}
			};

		public:

			rbt_iterator(ft::Node<T> *n, const Allocator& alloc = Allocator()) : _node(n), _alloc(alloc)
			{
			};

			rbt_iterator(const Allocator& alloc = Allocator()) : _node(0), _alloc(alloc)
			{
			};

			template< class U >
			rbt_iterator(const rbt_iterator<U>& other)
			{
				this->_node = other.base();
			};

			~rbt_iterator()
			{
			}

			template< class U >
			rbt_iterator	&operator=(const rbt_iterator<U>& other)
			{
				this->_node = other.base();
				return (*this);
			};

			ft::Node<T> *base() const
			{
				return (this->_node);
			};

			T& operator*()
			{
				return _node->key;
			};

			T* operator->() const 
			{
				return &(_node->key);
			};

			rbt_iterator<T>& operator++()
			{
				if (_node != _node->_nil)
					Increment();
				return *this;
			};

			rbt_iterator<T> operator++(int)
			{
				rbt_iterator tmp = *this;
				if (_node != _node->_nil)
					Increment();
				// std::cout << "la" << std::endl;
				return tmp;
			};

			rbt_iterator<T>& operator--()
			{
				Decrement();
				return *this;
			};

			rbt_iterator<T> operator--(int)
			{
				rbt_iterator tmp = *this;
				// rbt_iterator tmp = this;
				Decrement();
				return tmp;
			};

			bool operator==(const rbt_iterator<T>& s)
			{
				return _node == s._node;
			};

			bool operator!=(const rbt_iterator<T>& s)
			{
				return _node != s._node;
			};

			// rbt_iterator<T>& operator+(size_t n)
			// {
			// 	while (n > 0)
			// 		Increment();
			// 	return *this;
			// };
	};




	/*
	======================================================================================
	CONST ITERATORS
	======================================================================================
	*/

	template<class T, class Allocator = std::allocator<ft::Node<T> > >
	struct const_rbt_iterator
	{

		protected:

			ft::Node<T>		*_node;
			Allocator		_alloc;

			void Increment()
			{
				if (_node->rightChild != _node->_nil)
				{
					ft::Node<T> *temp = _node->rightChild;
					while (temp->leftChild != _node->_nil)
						temp = temp->leftChild;
					_node = temp;

				}
				else
				{
					ft::Node<T> *tmp = _node->parent;
					if (tmp->rightChild ==_node)
					{
						while (_node == tmp->rightChild)
						{
							_node = tmp;
							tmp = tmp->parent;
						}
					}
					if (_node->rightChild != tmp)
						_node = tmp;
				}
			};

			void Decrement()
			{
				if (_node->parent->parent == _node && _node->color == 1)
					_node = _node->leftChild;

				else if (_node->leftChild != _node->_nil)
				{
					_node = _node->leftChild;
					while (_node->rightChild != _node->_nil)
						_node = _node->rightChild;
				}
				else
				{
					ft::Node<T> *parent = _node->parent;
					while (parent->leftChild == _node)
					{
						_node = parent;
						parent = parent->parent;
					}
					_node = parent;
				}
			};

		public:

			const_rbt_iterator(ft::Node<T> *n = NULL, const Allocator& alloc = Allocator()) : _node(n), _alloc(alloc)
			{
			};
		
			// autre constructeur a partir d'un iterator
		
			template< class U >
			const_rbt_iterator(const const_rbt_iterator<U>& other)
			{
				this->_node = other.base();
			};

			~const_rbt_iterator() {};

			template< class U >
			const_rbt_iterator	&operator=(const const_rbt_iterator<U>& other)
			{
				this->_node = other.base();
				return (*this);
			};

			ft::Node<T> *base() const
			{
				return (this->_node);
			};

			T& operator*()
			{
				return _node->key;
			};

			T* operator->()
			{
				return &(_node->key);
			};

			const_rbt_iterator& operator++()
			{
				if (_node != _node->_nil)
					Increment();
				return *this;
			};

			const_rbt_iterator operator++(int)
			{
				const_rbt_iterator tmp = *this;
				if (_node != _node->_nil)
					Increment();
				return tmp;
			};

			const_rbt_iterator& operator--()
			{
				Decrement();
				return *this;
			};

			const_rbt_iterator operator--(int)
			{
				const_rbt_iterator tmp = *this;
				Decrement();
				return tmp;
			};

			bool operator==(const const_rbt_iterator& s)
			{
				return _node == s._node;
			};

			bool operator!=(const const_rbt_iterator& s)
			{
				return _node != s._node;
			};
	};

}

#endif
