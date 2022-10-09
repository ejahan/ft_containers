/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:06:00 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/10 00:38:32 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
 
#include <iostream>
#include "reverse_iterator.hpp"
#include "random_access.hpp"
#include "iterator_traits.hpp"
#include "lexicographical_compare.hpp"

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

			explicit vector(const Allocator& alloc = Allocator()) : _allocator(alloc), _p(_allocator.allocate(0)), _capacity(0), _size(0) {};

			explicit vector(size_type n, const T& val = T(), const Allocator& alloc = Allocator())
			{
				this->_allocator = alloc;
				this->_p = this->_allocator.allocate(n);
				this->_size = n;
				this->_capacity = n;
				while (n > 0)
				{
					this->_allocator.construct(&(this->_p[n]), val);
					n--;
				}
			};

/*
	je comprends pas pk ca compile paaaaas
*/
			// template <class InputIterator>
			// vector(InputIterator first, InputIterator last, const Allocator& alloc = Allocator())
			// {
			// 	size_type	i = 0;
			// 	difference_type	j = last - first;
			// 	this->_allocator = alloc;
			// 	this->_p = this->_allocator.allocate(j);
			// 	this->_size = j;
			// 	this->_capacity = j;
			// 	while ((first + i) <= last)
			// 	{
			// 		this->_allocator.construct(&this->_p[i], first + i);
			// 		i++;
			// 	}
			// };

			vector(const vector<T,Allocator>& x)
			{
				size_type	i = 0;
				this->_allocator = x.get_allocator();
				this->_p = this->_allocator.allocate(x._capacity);
				while (i <= x._size)
				{
					_allocator.construct(&(this->_p[i]), x._p[i]);
					i++;
				}
				this->_size = x._size;
				this->_capacity = x._capacity;
			};

			~vector()
			{
				this->clear();
				this->_allocator.deallocate(this->_p, this->_capacity);
			};

	// 		template <class InputIterator>
	// 		void	assign(InputIterator first, InputIterator last)
	// 		{
	// 			InputIterator	i = first;
	// 			int	j = 0;

	// 			while (first + i != last)
	// 			{
	// 				j++;	
	// 				i++;
	// 			}
	// 			while (j > 0)
	// 			{
	// 				this->_allocator.construct(this->_p[j], first + i);
	// 				i--;
	// 				j--;
	// 			}
	// 		};

			void	assign(size_type n, const T& val)
			{
				this->clear();
				this->_size = n;
				while (n > 0)
				{
					this->_allocator.construct(&(this->_p[n - 1]), val);
					n--;
				}
			};

			vector<T, Allocator>	&operator=(const vector<T, Allocator> &x)
			{
				size_type	i = 0;
				this->_allocator = x.get_allocator();
				this->_p = this->_allocator.allocate(x._capacity);
				while (i <= x._size)
				{
					_allocator.construct(&(this->_p[i]), x._p[i]);
					i++;
				}
				this->_size = x._size;
				this->_capacity = x._capacity;
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
				// reverse_iterator	it = end();
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
				if (this->_capacity < n)
				{
					T	*tmp;
					tmp = this->_allocator.allocate(n);
					size_type	i = 0;
					while(i <= this->_size) // juste < ?
					{
						this->_allocator.construct(&tmp[i], this->_p[i]);
						i++;
					}
					size_type	size_tmp = this->_size;
					clear();
					this->_size = size_tmp;
					this->_allocator.deallocate(this->_p, this->_capacity);
					this->_p = tmp;
					this->_capacity = n;
				}
			};


//			____________________________________________________________________________________
//			ELEMENT ACCESS

			reference		operator[](size_type n)
			{
				// return (this->_p[n]);
				return (*(this->begin() + n));
			};

			const_reference	operator[](size_type n) const
			{
				// return (this->_p[n]);
				return (*(this->begin() + n));
			};

			reference		at(size_type n)
			{
				if (this->_size - 1 < n)
					throw std::out_of_range("ERROR : out_of_range exception");
				return (*(this->begin() + n));
			};

			const_reference	at(size_type n) const
			{
				if (this->_size - 1 < n)
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
				// iterator	it(this->_p + this->_size);
				// --it;
				// return (*it);
				return (*--this->end());
			};

			const_reference	back() const
			{
				// const_iterator	it(this->_p + this->_size);
				// --it;
				// return (*it);
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

			void		resize(size_type n, T val = T())	//	-> PAS BON!!
			{
				if (this->_size > n)
					while (this->_size > n)
						this->pop_back();
				else if (this->_size < n) // capacity ?
					while (this->_size < n)
						push_back(val);
			};

			void		push_back(const T& val)
			{
				if (this->_capacity == 0)
					reserve(1);
				if (this->_size >= this->_capacity)
					reserve(this->_capacity * 2);
				this->_allocator.construct(&(this->_p[this->_size + 1]), val);
				this->_size++;
				// std::cout << _p[_size - 1] << std::endl;
						// this->_allocator.construct(&tmp[i], this->_p[i]);
			};

			void		pop_back() 
			{
				this->_allocator.destroy(&this->back());
				this->_size--;
			};

			iterator	insert(iterator position, const T& val)
			{
				pointer	new_p;
				size_t	i = 0;

				if (_capacity == 0)
					_capacity = 1;
				else if (_capacity == _size)
					_capacity = _capacity * 2;
				new_p = this->_allocator.allocate(this->_capacity);

				for(; begin() + i <= position ; i++)
					this->_allocator.construct(&new_p[i], this->_p[i]);

				this->_allocator.construct(&new_p[i], val);
				_size++;

				for(; i <= _size ; i++)
					this->_allocator.construct(&new_p[i + 1], this->_p[i]);

				clear();
				this->_allocator.deallocate(this->_p, this->_capacity);
				_size = i - 1;
				_p = new_p;
				return (position);
			};

			void		insert(iterator position, size_type n, const T& val)
			{
				size_t	i = position - begin();
				if (_capacity == 0)
					reserve(n);
				else if (_capacity <= _size + n)
					reserve(_capacity * 2);
				if (_capacity < _size + n)
					reserve(_size + n);
				while (n-- > 0)
					insert(begin() + i, val);
			};

			// template <class InputIterator>
			// void		insert(iterator position, InputIterator first, InputIterator last)
			// {
			// 	if (_capacity == 0)
			// 		reserve(n);
			// 	else if (_capacity <= _size + n)
			// 		reserve(_capacity * 2);
			// 	if (_capacity < _size + n)
			// 		reserve(_size + n);
			// 	while (first != last)
			// 	{
			// 		insert(first, val);
			// 		--last;
			// 	}
			// };

			iterator	erase(iterator position)
			{
				// Allocator.destroy(this->_p[position - 1]);
				size_type	i = position - begin();
				i++;
				while (i < _size)
				{
					_p[i] = _p[i + 1];
					i++;
				}
				this->_allocator.destroy(&this->back());
				this->_size--;	
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
			if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) == true)
				return (true);
			return (false);
		};

		template< class T, class Alloc >
		bool	operator!=( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) == false)
				return (true);
			return (false);
		};

		template< class T, class Alloc >
		bool	operator<( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) == true
					&& ft::equal(lhs.begin(), lhs.end(), rhs.begin()) == false)
				return (true);
			return (false);
		};

		template< class T, class Alloc >
		bool	operator<=( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) == true
					&& ft::equal(lhs.begin(), lhs.end(), rhs.begin()) == true)
				return (true);
			return (false);
		};

		template< class T, class Alloc >
		bool	operator>( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) == false
					&& ft::equal(lhs.begin(), lhs.end(), rhs.begin()) == false)
				return (true);
			return (false);
		};

		template< class T, class Alloc >
		bool	operator>=( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) == false
					&& ft::equal(lhs.begin(), lhs.end(), rhs.begin()) == true)
				return (true);
			return (false);
		};

}

#endif

