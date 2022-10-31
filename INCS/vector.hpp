/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:06:00 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/31 21:53:10 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "reverse_iterator.hpp"
#include "random_access.hpp"
#include "iterator_traits.hpp"
#include "lexicographical_compare.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

namespace ft {


	template < class T, class Allocator = std::allocator<T> > 
	class	vector {

		protected:	// ->stack

			Allocator	_allocator;
			T		*_p;
			size_t	_capacity;	// nbr elements possible
			size_t	_size;		// nbr elements 

		public:


			/*
			======================================================================================
				TYPES
			======================================================================================
			*/
			typedef typename Allocator::reference 			reference;	//	= T&
			typedef typename Allocator::const_reference 	const_reference;
			typedef ft::random_access_iterator<T> 			iterator;
			typedef ft::random_access_iterator<const T> 	const_iterator;
			typedef size_t 									size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef T 										value_type;
			typedef Allocator 								allocator_type;
			typedef typename Allocator::pointer 			pointer;	//	= T*
			typedef typename Allocator::const_pointer 		const_pointer;
			typedef ft::reverse_iterator<iterator> 			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> 	const_reverse_iterator;



			/*
			======================================================================================
				MEMBER FUNCTIONS
			======================================================================================
			*/

//			____________________________________________________________________________________
//			CONSTRUCT / COPY / DESTROY

			explicit vector(const Allocator& alloc = Allocator()) : _allocator(alloc), _p(0), _capacity(0), _size(0) {};

			explicit vector(size_type n, const T& val = T(), const Allocator& alloc = Allocator()) : _allocator(alloc), _p(0), _capacity(n), _size(n)
			{
				this->_allocator = alloc;
				this->_p = this->_allocator.allocate(n);
				this->_size = n;
				this->_capacity = n;
				while (n > 0)
				{
					--n;
					this->_allocator.construct(&(this->_p[n]), val);
				}
			};

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const Allocator& alloc = Allocator(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true) : _allocator(alloc), _p(NULL), _capacity(0), _size(0)
			{
				this->_allocator = alloc;
				// this->_p = this->_allocator.allocate(0);
				insert(begin(), first, last);
			};

			vector(const vector<T,Allocator>& x) : _allocator(x._allocator)
			{
				size_type	i = 0;

				_capacity = 0;
				_size = 0;
				// _p = _allocator.allocate(x._size);
				reserve(x._size);
				while (i < x._size)
				{
					_allocator.construct(&(this->_p[i]), x._p[i]);
					i++;
				}
				this->_size = x._size;
				this->_capacity = x._size;
			};

			~vector()
			{
				this->clear();
				this->_allocator.deallocate(this->_p, this->_capacity);
			};

			template <class InputIterator>
			void	assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
			{
				clear();
				insert(begin(), first, last);
			};

			void	assign(size_type n, const T& val)
			{
				clear();
				insert(begin(), n, val);
			};

			vector<T, Allocator>	&operator=(const vector<T, Allocator> &x)
			{
				clear();
				insert(begin(), x.begin(), x.end());
				return (*this);
			};


//			____________________________________________________________________________________
//			 ITERATORS

			iterator				begin()
			{
				iterator	test(this->_p);
				return (test);
			};

			const_iterator			begin() const
			{
				const_iterator	it(this->_p);
				return (it);
			};

			iterator				end()
			{
				iterator	it(_p + _size);
				return (it);
			};

			const_iterator			end() const
			{
				const_iterator	it(this->_p + this->_size);
				return (it);
			};

			reverse_iterator		rbegin()
			{
				reverse_iterator	it(end());
				return (it);
			};

			const_reverse_iterator	rbegin() const
			{
				const_reverse_iterator	it(end());
				return (it);
			};

			reverse_iterator		rend()
			{
				reverse_iterator	it(begin());
				return (it);
			};

			const_reverse_iterator	rend() const
			{
				const_reverse_iterator	it(begin());
				return (it);
			};


//			____________________________________________________________________________________
// 			CAPACITY

			size_type	size() const
			{
				return (this->_size);
			};

			size_type	max_size() const
			{
				return (this->_allocator.max_size());
			};

			size_type	capacity() const
			{
				return (this->_capacity);
			};

			bool		empty() const
			{
				if (this->_size <= 0)
					return true;
				else
					return false;
			};

			void		reserve(size_type n)
			{
				if (n > max_size())
					throw (std::length_error("vector::reserve"));
				if (n == 1 && _capacity <= _size)
				{
					_p = _allocator.allocate(1);
					_capacity = 1;
				}
				else if (this->_capacity < n)
				{
					T *tmp = this->_allocator.allocate(n);
					size_type	i = 0;
					while(i < this->_size)
					{
						this->_allocator.construct(&tmp[i], this->_p[i]);
						i++;
					}
					size_type	size_tmp = this->_size;
					clear();
					this->_size = size_tmp;
					if (_capacity > 0)
						this->_allocator.deallocate(this->_p, this->_capacity);
					this->_p = tmp;
					this->_capacity = n;
				}
			};


//			____________________________________________________________________________________
//			ELEMENT ACCESS

			reference		operator[](size_type n)
			{
				return (*(this->begin() + n));
			};

			const_reference	operator[](size_type n) const
			{
				return (*(this->begin() + n));
			};

			reference		at(size_type n)
			{
				if (this->_size < n)
					throw std::out_of_range("ERROR : out_of_range exception");
				return (*(this->begin() + n));
			};

			const_reference	at(size_type n) const
			{
				if (this->_size < n)
					throw std::out_of_range("ERROR : out_of_range exception");
				return (*(this->begin() + n));
			};

			reference		front()
			{
				return (*this->begin());
			};

			const_reference	front() const
			{
				return (*this->begin());
			};

			reference		back()
			{
				return (*--this->end());
			};

			const_reference	back() const
			{
				return (*--this->end());
			};

			pointer			data()
			{
				return (&this->_p[0]);
			};

			const pointer	data() const
			{
				return (&this->_p[0]);
			};


//			____________________________________________________________________________________
//			MODIFIERS

			void		resize(size_type n, T val = T())
			{
				if (n > size())
					insert(end(), n - size(), val);
				else if (n < size())
					erase(begin() + n, end());
				else
					return ;
			};

			void		push_back(const T& val)
			{
				if (this->_capacity == 0)
					reserve(1);
				else if (this->_size >= this->_capacity)
					reserve(this->_capacity * 2);
				this->_allocator.construct(&(this->_p[this->_size]), val);
				this->_size++;
			};

			void		pop_back() 
			{
				this->_allocator.destroy(this->_p + _size - 1);
				this->_size--;
			};

			iterator	insert(iterator position, const T& val)
			{
				size_t	i = position - begin();
				size_t	size = _size;

				if (_capacity == 0) {
					reserve(1);
				}
				else if (_capacity == _size && _capacity!= 0) {
					reserve(2 * _capacity);
				}
				
				_allocator.construct(&(_p[size]), val);
				while (size > i)
				{
					_p[size] = _p[size- 1];
					size--;
				}
				_p[size] = val;
				_size++;

				return (begin() + size);
			};

			void		insert(iterator position, size_type n, const T& val)
			{
				if (n == 0)
					return ;
				size_t	i = position - begin();
				if (_capacity == 0)
					reserve(n);
				if (_capacity < _size + n && _size * 2 >= _size + n) {
						reserve(2 * _size);
				}
				else {
					reserve(_size + n);
				}
				while (n-- > 0)
				{
					insert(begin() + i, val);
					i++;
				}
			};

			template <class InputIterator>
			void		insert(iterator position, InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
			{
				InputIterator	tmp = first;
				size_t			size = 0;
				size_t	i = position - begin();
				while (tmp != last)
				{
					tmp++;
					size++;
				}
				if (_capacity <= _size + size && _size + size < _size * 2)
					reserve(2 * _size);
				else
					reserve(_size + size);
				while (first != last)
				{
					insert(begin() + i, *first);
					i++;
					first++;
				}
			};

			iterator	erase(iterator position)
			{
				size_type	i = position - begin();
				while (i < _size - 1)
				{
					i++;
					_p[i - 1] = _p[i];
				}
				this->_allocator.destroy(&back());
				_size--;
				return (position);
			};

			iterator	erase(iterator first, iterator last)
			{
				iterator	ret = first;

				while (first != last)
				{
					erase(first);
					--last;
				}
				return (ret);
			};

			void		swap(vector<T, Allocator>& x)
			{
				std::swap(this->_p, x._p);
				std::swap(this->_allocator, x._allocator);
				std::swap(this->_size, x._size);
				std::swap(this->_capacity, x._capacity);
			};

			void		clear()
			{
				while (this->_size > 0)
					this->pop_back();
			};

			allocator_type get_allocator() const
			{
				return (this->_allocator);
			};

	};


		/*
		======================================================================================
		OPERATORS
		======================================================================================
		*/

		template< class T, class Alloc >
		void swap( ft::vector<T,Alloc> &lhs, ft::vector<T,Alloc> &rhs )
		{
			lhs.swap(rhs);
		};

		template< class T, class Alloc >
		bool	operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc> &rhs )
		{
			if ((lhs.size() == rhs.size())
					&& (ft::equal(lhs.begin(), lhs.end(), rhs.begin())) == true)
				return (true);
			return (false);
		};

		template< class T, class Alloc >
		bool	operator!=( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) == false
					|| (lhs.size() != rhs.size()))
				return (true);
			return (false);
		};

		template< class T, class Alloc >
		bool	operator<( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) == true)
				return (true);
			return (false);
		};

		template< class T, class Alloc >
		bool	operator<=( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			if (lhs < rhs || lhs == rhs)
				return (true);
			return (false);
		};

		template< class T, class Alloc >
		bool	operator>( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			if (lhs <= rhs)
				return (false);
			return (true);
		};

		template< class T, class Alloc >
		bool	operator>=( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			if (lhs < rhs)
				return (false);
			return (true);
		};

}

#endif

