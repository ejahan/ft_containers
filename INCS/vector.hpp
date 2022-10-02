/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:06:00 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/02 20:03:50 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
 
#include <iostream>
#include "reverse_iterator.hpp"
#include "random_access.hpp"
#include "iterator_traits.hpp"
#include "lexicographical_compare.hpp"


# include <algorithm>
# include <memory>
# include <cstddef>
#include <stdexcept>

namespace ft {

	template < class T, class Allocator = std::allocator<T> > 
	class	vector {

		private:	//	protected? (stack)

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
			typedef typename Allocator::reference reference;	//	= T&
			typedef typename Allocator::const_reference const_reference;
			typedef ft::random_access_iterator<T> iterator;
			typedef ft::random_access_iterator<const T> const_iterator;
			typedef size_t size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef typename Allocator::pointer pointer;	//	= T*
			typedef typename Allocator::const_pointer const_pointer;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;



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
					this->_allocator.construct(&(this->_p[n - 1]), val);
					n--;
				}
			};

			// template <class InputIterator>
			// vector(InputIterator first, InputIterator last, const Allocator& alloc = Allocator())
			// {
			// 	InputIterator	i = first;
			// 	int	j = 0;

			// 	while (first + i != last)
			// 	{
			// 		j++;	
			// 		i++;
			// 	}
			// 	this->_allocator = alloc;
			// 	this->_p = this->_allocator.allocate(j);
			// 	this->_size = j;
			// 	this->_capacity = j;
			// 	while (j > 0)
			// 	{
			// 		this->_allocator.construct(this->_p[j], first + i);
			// 		i--;
			// 		j--;
			// 	}
			// };

			vector(const vector<T,Allocator>& x)
			{
				size_type	i = 0;
				this->_allocator = x.get_allocator();
				this->_p = this->_alloc.allocate(x._capacity);
				while (i < x._size)
				{
					_allocator.construct(&(this->_p[i]), x._p[i]);
					i++;
				}
				this->_size = x._size;
				this->_capacity = x._capacity;
			};

			~vector()
			{
				// size_type	n = 0;
				// while (n < this->_size)
				// {
				// 	std::cout << this->_p[n] << std::endl;
				// 	n++;
				// }
				// std::cout << "size = " << this->_size << std::endl;
				// std::cout << "capacity = " << this->_capacity << std::endl;
				this->clear();
				this->_allocator.deallocate(this->_p, this->_capacity);
				std::cout << "destructor" << std::endl;
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

	// 		vector& operator=(const vector& x) // vector<T, Allocator> ?
	// 		{
	// 			size_type	i = 0;
	// 			this->_allocator = x.get_allocator();
	// 			this->_p = this->_alloc.allocate(x._capacity);
	// 			while (i < x._size)
	// 			{
	// 				_alloc.construct(this->_p[i], x._p[i]));
	// 				i++;
	// 			}
	// 			this->_size = x._size;
	// 			this->_capacity = x._capacity;
	// 		};


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
				reverse_iterator	it = end();
				it++;
				return (it);
			};

			const_reverse_iterator	rbegin() const
			{
				const_reverse_iterator	it = end();
				it++;
				return (it);
			};

			reverse_iterator		rend()
			{
				reverse_iterator	it = begin();
				return (it);
			};

			const_reverse_iterator	rend() const
			{
				const_reverse_iterator	it = begin();
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
					while(i < this->_size)
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
				return (this->_p[n]);
			};

			const_reference	operator[](size_type n) const
			{
				return (this->_p[n]);
			};

			reference		at(size_type n)
			{
				if (this->_size - 1 < n)
					throw std::out_of_range("ERROR : out_of_range exception");
				return (this->_p[n]);
			};

			const_reference	at(size_type n) const
			{
				if (this->_size - 1 < n)
					throw std::out_of_range("ERROR : out_of_range exception");
				return (this->_p[n]);
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
				iterator	it(this->_p + this->_size);
				--it;
				return (*it);
				// return (*--this->end());
			};

			const_reference	back() const
			{
				const_iterator	it(this->_p + this->_size);
				--it;
				return (*it);
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
				if (this->_size > n)
					while (this->_size > n)
						this->pop_back();
				else if (this->_size < n) // capacity ?
					while (this->_size < n)
						push_back(val);
			};

			void		push_back(const T& val)
			{
				this->_allocator.construct(this->_p + this->_size, val);
				this->_size++;
				// std::cout << _p[_size - 1] << std::endl;
			};

			void		pop_back()	//	manque pleins de trucs mais dans l idee c est peut etre ca 
			{
				this->_allocator.destroy(&this->back());
				this->_size--;
			};

	// 		iterator	insert(iterator position, const T& val)
	// 		{
	// 			//	flemme
	// 		};

	// 		void		insert(iterator position, size_type n, const T& val)
	// 		{
	// 			//	flemme aussi
	// 		};

	// 		template <class InputIterator>
	// 		void		insert(iterator position, InputIterator first, InputIterator last)
	// 		{
	// 			//	tout pareil
	// 		};

			iterator	erase(iterator position)	//	pas fini du tout
			{
				// Allocator.destroy(this->_p[position - 1]);
				while (position < this->end())
				{
					this->_p[position] = this->_p[position + 1];
					position++;
				}
				this->_allocator.destroy(&this->back());
				this->_size--;			
			};

			// iterator	erase(iterator first, iterator last)	//	pas fini du tout
			// {
			// 	while (first < last)
			// 	{
			// 		this->_p[first] = this->_p[first + 1];
			// 		first++;
			// 		this->_size--;
			// 		this->_allocator.destroy(first - 1);
			// 	}
			// };

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
			if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) == true)
				return (true);
			return (false);
		};

		template< class T, class Alloc >
		bool	operator<=( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) == true
					|| ft::equal(lhs.begin(), lhs.end(), rhs.begin()) == true)
				return (true);
			return (false);
		};

		template< class T, class Alloc >
		bool	operator>( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) == false)
				return (true);
			return (false);
		};

		template< class T, class Alloc >
		bool	operator>=( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) == false
					|| ft::equal(lhs.begin(), lhs.end(), rhs.begin()) == true)
				return (true);
			return (false);
		};

}

#endif

