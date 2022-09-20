/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:06:00 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/20 02:41:13 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
 
#include <iostream>

namespace ft {

template < class T, class Allocator = std::allocator<T> > 
class	vector {

	private:

		pointer		_p;
		size_type	_capacity;	// nbr elements possible
		size_type	_size;		// nbr elements 

	public:


		/*
			TYPES
		*/

		typedef typename Allocator::reference reference;	//	= T&
		typedef typename Allocator::const_reference const_reference;
		typedef implementation defined iterator;
		typedef implementation defined const_iterator;
		typedef implementation defined size_type;
		typedef implementation defined difference_type;
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename Allocator::pointer pointer;	//	= T*
		typedef typename Allocator::const_pointer const_pointer
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;


		/*
			MEMBER FUNCTIONS
		*/


		//  CONSTRUCT / COPY / DESTROY
		vector & operator=(vector const & rhs);

		explicit vector(const Allocator& alloc = Allocator());
		explicit vector(size_type n, const T& val = T(), const Allocator& alloc = Allocator());

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const Allocator& alloc = Allocator());

		vector(const vector<T,Allocator>& x);
		~vector();

		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last);
		void	assign(size_type n, const T& val);

		vector& operator=(const vector& x); // vector<T, Allocator> ?


		// ITERATORS
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;


		// CAPACITY
		size_type	size() const
		{
			return (this->_size);
		};

		size_type	max_size() const
		{
			return (Allocator.max_size());
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
			//	pas trop trop compris je crois
		};


		// ELEMENT ACCESS
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
				throw std::out_of_range();
			return (this->_p[n]);
		};

		const_reference	at(size_type n) const
		{
			if (this->_size - 1 < n)
				throw std::out_of_range();
			return (this->_p[n]);
		};

		reference		front()
		{
			return (this->_p[0]);	//	*this->_p.begin()	?
		};

		const_reference	front() const
		{
			return (this->_p[0]);	//	*this->_p.begin()	?
		};

		reference		back()
		{
			//	return le dernier element
		};

		const_reference	back() const
		{
			//	return le dernier element
		};

		pointer			data()
		{
			return (&this->_p[0]);
		};

		const pointer	data() const
		{
			return (&this->_p[0]);
		};


		// MODIFIERS
		void		resize(size_type n, T val = T())
		{
			//	resize le container a n elements
			//	si n est plus petit que size -> garde que les n premiers elements
			//	si plus grand -> ajoute n - size val
		};

		void		push_back(const T& val)
		{
			//	ajoute T a la fin
			this->_size++;
		};

		void		pop_back()	//	manque pleins de trucs mais dans l idee c est peut etre ca 
		{
			Allocator.destroy(this->back());
			this->_size--;
		};

		iterator	insert(iterator position, const T& val)
		{
			//	flemme
		};

		void		insert(iterator position, size_type n, const T& val)
		{
			//	flemme aussi
		};

		template <class InputIterator>
		void		insert(iterator position, InputIterator first, InputIterator last)
		{
			//	tout pareil
		};

		iterator	erase(iterator position)	//	pas fini du tout
		{
			Allocator.destroy(this->_p[position - 1]);
			while (position <= end)
			{
				this->_p[position - 1] = this->_p[position];
				position++;
			}
			// Allocator.destroy(this->back());
			this->_size--;			
		};

		iterator	erase(iterator first, iterator last)	//	pas fini du tout
		{
			while (first <= last)
			{
				Allocator.destroy(this->_p[first]);
				this->_p[first] = this->_p[first + 1];
				first++;
				this->_size--;
			}
		};

		void		swap(vector& x) // vector<T,Allocator>
		{
			ft::vector	tmp;

			//	Walter il a utilisé std::swap j suis perdue on verra plus tard
		};

		void		clear()
		{
			while (this->_size > 0)
			{
				this->pop_back();
				this->_size--;
			}
		};

		allocator_type get_allocator() const
		{
			return (Allocator);
		};


};

		// OPERATORS
		template< class T, class Alloc >
		void swap( ft::vector<T,Alloc> &lhs, ft::vector<T,Alloc> &rhs )
		{
			
		};

		template< class T, class Alloc >
		bool	operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc> &rhs )
		{
			
		};

		template< class T, class Alloc >
		bool	operator!=( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			
		};

		template< class T, class Alloc >
		bool	operator<( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			
		};

		template< class T, class Alloc >
		bool	operator<=( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			
		};

		template< class T, class Alloc >
		bool	operator>( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			
		};

		template< class T, class Alloc >
		bool	operator>=( const ft::vector<T,Alloc> &lhs, const ft::vector<T,Alloc> &rhs )
		{
			
		};

}

#endif

