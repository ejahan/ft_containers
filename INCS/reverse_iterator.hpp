/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:10:32 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/11 17:13:57 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "random_access.hpp"

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


			reverse_iterator() : _current(0) {};

			explicit	reverse_iterator(iterator_type x) : _current(x) {};

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
				return &(operator*());	//	??
			};

			reference operator[]( difference_type n ) const
			{
				// return (this->_current[-n-1]);	//	== base()[-n-1]
				// return (*(this->base() - n - 1));
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


	// j ai compris mais comment il a trouve qu il fallait mettre ca aussi?
	template <class T1, class T2>
	typename reverse_iterator<T1>::difference_type operator-(const reverse_iterator<T1>& x, const reverse_iterator<T2>& y) {
		return y.base() - x.base();
	};

}

	// template <class Iterator>
	// bool operator==(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y);
	
	// template <class Iterator>
	// bool operator<(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y);
	
	// template <class Iterator>
	// bool operator!=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y);
	
	// template <class Iterator>
	// bool operator>(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y);
	
	// template <class Iterator>
	// bool operator>=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y);
	
	// template <class Iterator>
	// bool operator<=(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y);








	// reverse_iterator();
	// explicit reverse_iterator(Iterator x);
	// template <class U> reverse_iterator(const reverse_iterator<U>& u);
	// Iterator base() const; // explicit
	// reference operator*() const;
	// pointer operator->() const;
	// reverse_iterator& operator++();
	// reverse_iterator operator++(int);
	// reverse_iterator& operator--();
	// reverse_iterator operator--(int);
	// reverse_iterator operator+ (difference_type n) const;
	// reverse_iterator& operator+=(difference_type n);
	// reverse_iterator operator- (difference_type n) const;
	// reverse_iterator& operator-=(difference_type n);
	// reference operator[](difference_type n) const;
	// };
	
#endif

    // explicit reverse_iterator(Itr itr): itr(itr) {}
    // auto& operator*() {
    //     return *std::prev(itr); // <== returns the content of prev
    // }
    // auto& operator++() {
    //     --itr;
    //     return *this;
    // }
    // friend bool operator!=(reverse_iterator<Itr> a, reverse_iterator<Itr> b) {
    //     return a.itr != b.itr;
    // }




// template <class BidirectionalIterator>
// void reverse(BidirectionalIterator first, BidirectionalIterator last) {
// typename iterator_traits<BidirectionalIterator>::difference_type n =
// distance(first, last);
// --n;
// while(n > 0) {
// typename iterator_traits<BidirectionalIterator>::value_type
// tmp = *first;
// *first++ = *--last;
// *last = tmp;
// n -= 2;
// }
// }