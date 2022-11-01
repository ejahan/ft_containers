/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:10:32 by ejahan            #+#    #+#             */
/*   Updated: 2022/11/01 23:02:40 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace	ft {

	template<class Iter>
	class	reverse_iterator  : public	iterator<typename iterator_traits<Iter>::iterator_category,
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


			reverse_iterator() : _current() {};

			explicit	reverse_iterator(iterator_type x) : _current(x) {};

			// operator reverse_iterator<const iterator_type>() const
			// {
			// 	return (reverse_iterator<const iterator_type>(_current));
			// }

			template< class U >
			reverse_iterator(const reverse_iterator<U>& other) : _current(other.base()) {};

			template< class U >
			reverse_iterator	&operator=(const reverse_iterator<U>& other)
			{
				this->_current = other.base();
				return (*this);
			};

			iterator_type base() const
			{
				return (this->_current);
			};

			reference operator*() const
			{
				Iter tmp = this->_current;
				return (*--tmp);
			};

			pointer operator->() const
			{
				return &(operator*());
			};

			reference operator[]( difference_type n ) const
			{
				return (*(this->_current - n - 1));
			};

			reverse_iterator& operator++()
			{
				--this->_current;
				return (*this);
			};

			reverse_iterator operator++( int )
			{
				reverse_iterator tmp = *this;
				--this->_current;
				return (tmp);
			};

			reverse_iterator& operator--()
			{
				++this->_current;
				return (*this);
			};

			reverse_iterator operator--( int )
			{
				reverse_iterator tmp = *this;
				++this->_current;
				return (tmp);
			};

			reverse_iterator operator+( difference_type n ) const
			{
				return (reverse_iterator(this->_current - n));
			};

			reverse_iterator& operator+=( difference_type n )
			{
				this->_current -= n;
				return (*this);
			};

			reverse_iterator operator-( difference_type n ) const
			{
				return (reverse_iterator(this->_current + n));
			};

			reverse_iterator& operator-=( difference_type n )
			{
				this->_current += n;
				return (*this);
			};

	};

	template< class Iterator1, class Iterator2 >
	bool operator==(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() == rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator!=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator<(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator<=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator>(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() < rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator>=(const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template< class Iter >
	reverse_iterator<Iter>	operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)	//	reverse_iterator<Iter>(it.base() - n)
	{
		return (reverse_iterator<Iter>(it.base() - n));
	};

	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type	operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	};

	template <class T1, class T2>
	typename reverse_iterator<T1>::difference_type operator-(const reverse_iterator<T1>& x, const reverse_iterator<T2>& y) {
		return y.base() - x.base();
	};

}

#endif
