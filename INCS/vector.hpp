/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:06:00 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/15 18:46:46 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
 
#include <iostream>

namespace ft {

template < class T, class Allocator = std::allocator<T> > 
class	vector {

	private:

		T	*array;
		int	capacity;

	public:


		/*
			TYPES
		*/

		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef implementation defined iterator;
		typedef implementation defined const_iterator;
		typedef implementation defined size_type;
		typedef implementation defined difference_type;
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename Allocator::pointer pointer;
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
		size_type	size() const;
		size_type	max_size() const;
		void		resize(size_type n, T val = T());
		size_type	capacity() const;
		bool		empty() const;
		void		reserve(size_type n);


		// ELEMENT ACCESS
		reference		operator[](size_type n);
		const_reference	operator[](size_type n) const;
		reference		at(size_type n);
		const_reference	at(size_type n) const;
		reference		front();
		const_reference	front() const;
		reference		back();
		const_reference	back() const;
		T*			data();
		const T*	data() const;


		// MODIFIERS
		void	push_back(const T& val);
		void	pop_back();
		iterator	insert(iterator position, const T& val);
		void		insert(iterator position, size_type n, const T& val);
		template <class InputIterator>
		void		insert(iterator position, InputIterator first, InputIterator last);
		iterator	erase(iterator position);
		iterator	erase(iterator first, iterator last);
		void	swap(vector& x); // vector<T,Allocator>
		void	clear();
		allocator_type get_allocator() const;


		// OPERATORS
		template< class T, class Alloc >
		void swap( vector<T,Alloc> &lhs, vector<T,Alloc> &rhs );

		template< class T, class Alloc >
		bool	operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc> &rhs );

		template< class T, class Alloc >
		bool	operator!=( const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs );

		template< class T, class Alloc >
		bool	operator<( const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs );

		template< class T, class Alloc >
		bool	operator<=( const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs );

		template< class T, class Alloc >
		bool	operator>( const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs );

		template< class T, class Alloc >
		bool	operator>=( const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs );

};

}

#endif

