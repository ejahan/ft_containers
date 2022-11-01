/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:20:30 by ejahan            #+#    #+#             */
/*   Updated: 2022/11/01 06:15:07 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SET_ITERATOR_HPP
# define SET_ITERATOR_HPP

#include <iostream>
#include "node.hpp"
#include "iterator_traits.hpp"


namespace	ft
{
	/*
	======================================================================================
	ITERATORS
	======================================================================================
	*/

	template<class T>
	struct set_rbt_iterator
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

			// set_rbt_iterator() : _node() {};

			// set_rbt_iterator(ft::Node<T> *n, ft::Node<T> *root) : _node(n), _root(root) {};

			// // set_rbt_iterator(const n_pointer &n, const n_pointer &root) : _node(n), _root(root) {};

			// template< class U >
			// set_rbt_iterator(const set_rbt_iterator<U>& other)
			// {
			// 	// this->_node = other.base();
			// 	_node = other.node();
			// 	_root = other.root();
			// };

			// operator set_rbt_iterator<const T> (void) {
			// 	return (set_rbt_iterator<const T>(_node, _root));
			// }

			// ~set_rbt_iterator()
			// {
			// }

			// template< class U >
			// set_rbt_iterator	&operator=(const set_rbt_iterator<U>& other)
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




			set_rbt_iterator (void) : _node(), _root() {};

			// set_rbt_iterator(ft::Node<T> *n, ft::Node<T> *root) : _node(n), _root(root) {};

			set_rbt_iterator (const n_pointer& val, const n_pointer& root) : _node(val), _root(root) {};

			set_rbt_iterator (const set_rbt_iterator& other) : _node(other._node), _root(other._root) {};

			operator set_rbt_iterator<const T> (void) {
				return (set_rbt_iterator<const T>(_node, _root));
			}

			set_rbt_iterator&
			operator=(const set_rbt_iterator& other) {
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

			// reference operator* (void) {
			// 	return (_node->key);
			// }

			// pointer operator-> (void) {
			// 	return (&operator*());
			// }





			// const T& operator*() const
			// {
			// 	return _node->key;
			// };

			// const T* operator->() const 
			// {
			// 	return &(_node->key);
			// };

			const T& operator*() 
			{
				return _node->key;
			};

			const T* operator->()
			{
				return &(_node->key);
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




			set_rbt_iterator& operator++()
			{
				Increment();
				return *this;
			};

			set_rbt_iterator operator++(int)
			{
				set_rbt_iterator tmp = *this;
				Increment();
				return tmp;
			};

			set_rbt_iterator& operator--()
			{
				if (_node == _node->_nil)
					_node = rbt_max(_root);
				else
					Decrement();
				return *this;
			};

			set_rbt_iterator operator--(int)
			{
				set_rbt_iterator tmp = *this;

				if (_node == _node->_nil)
					_node = rbt_max(_root);
				else
					Decrement();
				return tmp;
			};

			bool operator==(const set_rbt_iterator<T>& s)
			{
				return _node == s._node;
			};

			bool operator!=(const set_rbt_iterator<T>& s)
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

























	template<class Iter>
	class	set_rev_iterator  : public	iterator<typename iterator_traits<Iter>::iterator_category,
		typename iterator_traits<Iter>::value_type,
		typename iterator_traits<Iter>::difference_type,
		typename iterator_traits<Iter>::pointer,
		typename iterator_traits<Iter>::reference> 
	{

		protected:

			Iter _current;

		public:

			typedef	Iter													iterator_type;
			typedef	typename	ft::iterator_traits<Iter>::difference_type	difference_type;
			typedef	typename	ft::iterator_traits<Iter>::reference		reference;
			typedef	typename	ft::iterator_traits<Iter>::pointer			pointer;


			// set_rev_iterator() : _current(0) {};
			set_rev_iterator() : _current() {};

			explicit	set_rev_iterator(iterator_type x) : _current(x) {};

			operator set_rev_iterator<const iterator_type>() const
			{
				return (set_rev_iterator<const iterator_type>(_current));
			}

			template< class U >
			set_rev_iterator(const set_rev_iterator<U>& other) : _current(other.base()) {};

			template< class U >
			set_rev_iterator	&operator=(const set_rev_iterator<U>& other)
			{
				this->_current = other.base();
				return (*this);
			};

			iterator_type base() const
			{
				return (this->_current);
			};

			const reference operator*() const
			{
				Iter tmp = this->_current;
				return (*--tmp);
			};

			// reference operator*()
			// {
			// 	Iter tmp = this->_current;
			// 	return (*--tmp);
			// };

			pointer operator->() const
			{
				return &(operator*());
			};

			reference operator[]( difference_type n ) const
			{
				return (*(this->_current - n - 1));
			};

			set_rev_iterator& operator++()
			{
				--this->_current;
				return (*this);
			};

			set_rev_iterator operator++( int )
			{
				set_rev_iterator tmp = *this;
				--this->_current;
				return (tmp);
			};

			set_rev_iterator& operator--()
			{
				++this->_current;
				return (*this);
			};

			set_rev_iterator operator--( int )
			{
				set_rev_iterator tmp = *this;
				++this->_current;
				return (tmp);
			};

			set_rev_iterator operator+( difference_type n ) const
			{
				return (set_rev_iterator(this->_current - n));
			};

			set_rev_iterator& operator+=( difference_type n )
			{
				this->_current -= n;
				return (*this);
			};

			set_rev_iterator operator-( difference_type n ) const
			{
				return (set_rev_iterator(this->_current + n));
			};

			set_rev_iterator& operator-=( difference_type n )
			{
				this->_current += n;
				return (*this);
			};

	};

	template< class Iterator1, class Iterator2 >
	bool operator==(const ft::set_rev_iterator<Iterator1>& lhs, const ft::set_rev_iterator<Iterator2>& rhs)
	{
		return (lhs.base() == rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator!=(const ft::set_rev_iterator<Iterator1>& lhs, const ft::set_rev_iterator<Iterator2>& rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator<(const ft::set_rev_iterator<Iterator1>& lhs, const ft::set_rev_iterator<Iterator2>& rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator<=(const ft::set_rev_iterator<Iterator1>& lhs, const ft::set_rev_iterator<Iterator2>& rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator>(const ft::set_rev_iterator<Iterator1>& lhs, const ft::set_rev_iterator<Iterator2>& rhs)
	{
		return (lhs.base() < rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator>=(const ft::set_rev_iterator<Iterator1>& lhs, const ft::set_rev_iterator<Iterator2>& rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template< class Iter >
	set_rev_iterator<Iter>	operator+(typename set_rev_iterator<Iter>::difference_type n, const set_rev_iterator<Iter>& it)	//	set_rev_iterator<Iter>(it.base() - n)
	{
		return (set_rev_iterator<Iter>(it.base() - n));
	};

	template< class Iterator >
	typename set_rev_iterator<Iterator>::difference_type	operator-(const set_rev_iterator<Iterator>& lhs, const set_rev_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	};

	template <class T1, class T2>
	typename set_rev_iterator<T1>::difference_type operator-(const set_rev_iterator<T1>& x, const reverse_iterator<T2>& y) {
		return y.base() - x.base();
	};



}

#endif
