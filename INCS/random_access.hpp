/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:42:05 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/25 18:50:46 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_HPP
# define RANDOM_ACCESS_HPP

#include "iterator_traits.hpp"

namespace	ft {

	template<class Iter>
	class	random_access_iterator /*: public
		Iter<typename iterator_traits<Iter>::iter_category,
		typename iter_traits<Iter>::value_type,
		typename iter_traits<Iter>::difference_type,
		typename iter_traits<Iter>::pointer,
		typename iter_traits<Iter>::reference> */	//	jsp trop si je dois le mettre c est pareil qu en dessous je crois
	{

		protected:

			Iter _current;

		public:

			// typedef	Iter	iterator_type;

			typedef	typename	ft::iterator_traits<Iter>::iterator_category	iterator_type;
			typedef	typename	ft::iterator_traits<Iter>::value_type	value_type;
			typedef	typename	ft::iterator_traits<Iter>::difference_type	difference_type;
			typedef	typename	ft::iterator_traits<Iter>::pointer	pointer;
			typedef	typename	ft::iterator_traits<Iter>::reference	reference;

/*		WALTER
			typedef typename ft::iterator<ft::random_access_iterator_tag, Iter>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, Iter>::iterator_category	iterator_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, Iter>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, Iter>::reference			reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, Iter>:: pointer			pointer;
*/
			random_access_iterator() : _current(0) {};

			explicit	random_access_iterator(iterator_type x) : _current(x) {};

			template< class U >
			random_access_iterator(const random_access_iterator<U>& other) : _current(other.base()) {};

			template< class U >
			random_access_iterator	&operator=(const random_access_iterator<U>& other)
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
				return (*++tmp);
			};

			pointer operator->() const
			{
				return &(operator*());	//	??
			};

			Iter	operator[]( difference_type n ) const   // a changer
			{
				return (this->_current[-n-1]);	//	== base()[-n-1]
			};

			random_access_iterator& operator++()
			{
				++this->_current;
				return (*this);
			};

			random_access_iterator operator++( int )
			{
				random_access_iterator tmp = *this;
				++this->_current;
				return (tmp);
			};

			random_access_iterator& operator--()
			{
				--this->_current;
				return (*this);
			};

			random_access_iterator operator--( int )
			{
				random_access_iterator tmp = *this;
				--this->_current;
				return (tmp);
			};

			random_access_iterator operator+( difference_type n ) const
			{
				return (random_access_iterator(this->_current + n));
			};

			random_access_iterator& operator+=( difference_type n )
			{
				this->_current += n;
				return (*this);
			};

			random_access_iterator operator-( difference_type n ) const
			{
				return (random_access_iterator(this->_current - n));
			};

			random_access_iterator& operator-=( difference_type n )
			{
				this->_current -= n;
				return (*this);
			};

	};

	template< class Iterator1, class Iterator2 >
	bool operator==(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs)
	{
		return (lhs.base() == rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator!=(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator<(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs)
	{
		return (lhs.base() < rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator<=(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator>(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template< class Iterator1, class Iterator2 >
	bool operator>=(const ft::random_access_iterator<Iterator1>& lhs, const ft::random_access_iterator<Iterator2>& rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template< class Iter >
	random_access_iterator<Iter>
		operator+(typename random_access_iterator<Iter>::difference_type n, const random_access_iterator<Iter>& it)	//	random_access_iterator<Iter>(it.base() - n)
	{
		return (random_access_iterator<Iter>(it.base() + n));
	};

	template< class Iterator >
	typename random_access_iterator<Iterator>::difference_type
		operator-(const random_access_iterator<Iterator>& lhs, const random_access_iterator<Iterator>& rhs)
	{
		return (lhs.base() - rhs.base());
	};

}

#endif
