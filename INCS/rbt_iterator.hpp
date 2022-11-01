/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 04:36:32 by ejahan            #+#    #+#             */
/*   Updated: 2022/11/01 02:51:12 by ejahan           ###   ########.fr       */
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

	template<class T>
	struct rbt_iterator
	{
		protected:

			ft::Node<T>		*_node;
			ft::Node<T>		*_root;

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
					if (tmp == _node->_nil)
					{
						_node = _node->_nil;
						return ;
					}
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
					while (_node->rightChild != _node->rightChild->_nil)
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

			Node<T>	*rbt_max(Node<T> *x)
			{
				while (x->rightChild != x->_nil)
					x = x->rightChild;
				return x;
			};


		public:

			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>:: pointer			pointer;
			typedef	ft::Node<T> *		n_pointer;

			// rbt_iterator() : _node() {};

			// rbt_iterator(ft::Node<T> *n, ft::Node<T> *root) : _node(n), _root(root) {};

			// // rbt_iterator(const n_pointer &n, const n_pointer &root) : _node(n), _root(root) {};

			// template< class U >
			// rbt_iterator(const rbt_iterator<U>& other)
			// {
			// 	// this->_node = other.base();
			// 	_node = other.node();
			// 	_root = other.root();
			// };

			// operator rbt_iterator<const T> (void) {
			// 	return (rbt_iterator<const T>(_node, _root));
			// }

			// ~rbt_iterator()
			// {
			// }

			// template< class U >
			// rbt_iterator	&operator=(const rbt_iterator<U>& other)
			// {
			// 	// this->_node = other.base();
			// 	_node = other.node();
			// 	_root = other.root();
			// 	return (*this);
			// };

			ft::Node<T> *base() const
			{
				return (this->_node);
			};


			// T& operator*()
			// {
			// 	return _node->key;
			// };

			// const T& operator*() const
			// {
			// 	return _node->key;
			// };

			// const T* operator->() const 
			// {
			// 	return &(_node->key);
			// };

			// T* operator->()
			// {
			// 	return &(_node->key);
			// };




			rbt_iterator (void) : _node(), _root() {};

			// rbt_iterator(ft::Node<T> *n, ft::Node<T> *root) : _node(n), _root(root) {};

			rbt_iterator (const n_pointer& val, const n_pointer& root) : _node(val), _root(root) {};

			rbt_iterator (const rbt_iterator& other) : _node(other._node), _root(other._root) {};

			operator rbt_iterator<const T> (void) {
				return (rbt_iterator<const T>(_node, _root));
			}

			rbt_iterator&
			operator=(const rbt_iterator& other) {
				if (this == &other) {return (*this);}

				_node = other._node;
				_root = other._root;

				return (*this);
			}

			const reference operator* (void) const {
				return (_node->key);
			}

			const pointer operator-> (void) const {
				return (&operator*());
			}

			reference operator* (void) {
				return (_node->key);
			}

			pointer operator-> (void) {
				return (&operator*());
			}





			// const T& operator*() const
			// {
			// 	return _node->key;
			// };

			// const T* operator->() const 
			// {
			// 	return &(_node->key);
			// };

			// const T& operator*() 
			// {
			// 	return _node->key;
			// };

			// const T* operator->()
			// {
			// 	return &(_node->key);
			// };


			// T& operator*()
			// {
			// 	return _node->key;
			// };

			// const T& operator*() const
			// {
			// 	return _node->key;
			// };

			// const T* operator->() const 
			// {
			// 	return &(_node->key);
			// };

			// T* operator->()
			// {
			// 	return &(_node->key);
			// };




			rbt_iterator& operator++()
			{
				Increment();
				return *this;
			};

			rbt_iterator operator++(int)
			{
				rbt_iterator tmp = *this;
				Increment();
				return tmp;
			};

			rbt_iterator& operator--()
			{
				if (_node == _node->_nil)
					_node = rbt_max(_root);
				else
					Decrement();
				return *this;
			};

			rbt_iterator operator--(int)
			{
				rbt_iterator tmp = *this;

				if (_node == _node->_nil)
					_node = rbt_max(_root);
				else
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

			Node<T>	*node() const
			{
				return (this->_node);
			}

			Node<T>	*root() const
			{
				return (this->_root);
			}

	};


	/*
	======================================================================================
	CONST ITERATORS
	======================================================================================
	*/

	template<class T>
	struct const_rbt_iterator
	{
		protected:

			ft::Node<T>		*_node;
			ft::Node<T>		*_root;

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
					if (tmp == _node->_nil)
					{
						_node = _node->_nil;
						return ;
					}
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
					while (_node->rightChild != _node->rightChild->_nil)
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

			Node<T>	*rbt_max(Node<T> *x)
			{
				while (x->rightChild != x->_nil)
					x = x->rightChild;
				return x;
			};


		public:


			typedef typename ft::iterator<ft::random_access_iterator_tag, const T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, const T>::iterator_category	iterator_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, const T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, const T>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, const T>:: pointer			pointer;



			const_rbt_iterator() : _node(0) {};

			const_rbt_iterator(ft::Node<T> *n, ft::Node<T> *root) : _node(n), _root(root) {};

			template< class U >
			const_rbt_iterator(const const_rbt_iterator<U>& other) : _node(other._node), _root(other._root)
			{
				// this->_node = other.base();
			};

			~const_rbt_iterator() {};

			const_rbt_iterator(const rbt_iterator<T> &iterator) : _node(iterator.node()), _root(iterator.root()) {};

			template< class U >
			const_rbt_iterator	&operator=(const const_rbt_iterator<U>& other)
			{
				this->_node = other.base();
				_root = other.root();
				return (*this);
			};

			template< class U >
			const_rbt_iterator	&operator=(const rbt_iterator<U>& other)
			{
				this->_node = other.base();
				_root = other.root();
				return (*this);
			};

			ft::Node<T> *base() const
			{
				return (this->_node);
			};

			const T& operator*() const
			{
				return _node->key;
			};

			const T* operator->() const 
			{
				return &(_node->key);
			};

			const T& operator*()
			{
				return _node->key;
			};

			const T* operator->()
			{
				return &(_node->key);
			};

			const_rbt_iterator<T>& operator++()
			{
				Increment();
				return *this;
			};

			const_rbt_iterator<T> operator++(int)
			{
				const_rbt_iterator tmp = *this;
				Increment();
				return tmp;
			};

			const_rbt_iterator<T>& operator--()
			{
				if (_node == _node->_nil)
					_node = rbt_max(_root);
				else
					Decrement();
				return *this;
			};

			const_rbt_iterator<T> operator--(int)
			{
				const_rbt_iterator tmp = *this;

				if (_node == _node->_nil)
					_node = rbt_max(_root);
				else
					Decrement();
				return tmp;
			};

			bool operator==(const const_rbt_iterator<T>& s)
			{
				return _node == s._node;
			};

			bool operator!=(const const_rbt_iterator<T>& s)
			{
				return _node != s._node;
			};

			Node<T>	*node() const
			{
				return (this->_node);
			}

			Node<T>	*root() const
			{
				return (this->_root);
			}

	};

}

#endif
