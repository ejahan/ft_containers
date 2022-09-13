/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:06:00 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/13 13:42:47 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
 
# include <iostream>

namespace ft {

template < class T, class Alloc = allocator<T> > 
class	vector {

	private:



	public:

		vector & operator=(vector const & rhs);

		explicit vector(const allocator_type& alloc = allocator_type());
		explicit vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type());
		template <class InputIterator>
		vector(InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type());
		vector(const vector& x);
		~vector();
		vector& operator=(const vector& x);

		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		size_type	size() const;
		size_type	max_size() const;
		void		resize(size_type n, value_type val = value_type());
		size_type	capacity() const;
		bool		empty() const;
		void		reserve(size_type n);

		reference		operator[](size_type n);
		const_reference	operator[](size_type n) const;
		reference		at(size_type n);
		const_reference	at(size_type n) const;
		reference		front();
		const_reference	front() const;
		reference		back();
		const_reference	back() const;
		value_type*			data();
		const value_type*	data() const;

		template <class InputIterator>
		void	assign(InputIterator first, InputIterator last);
		void	assign(size_type n, const value_type& val);
		void	push_back(const value_type& val);
		void	pop_back();
		iterator	insert(iterator position, const value_type& val);
		void		insert(iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void		insert(iterator position, InputIterator first, InputIterator last);
		iterator	erase(iterator position);
		iterator	erase(iterator first, iterator last);
		void	swap(vector& x);
		void	clear();
		allocator_type get_allocator() const;

};

}

#endif

/*

	MEMBER FUNCTIONS

- constructor
- destructor
- operator=

- begin
- end
- rbegin
- rend
- cbegin
- cend
- crbegin
- crend

- size
- max_size
- resize
- capacity
- empty
- reserve
- shrink_to_fit

- operator[]
- at
- front
- back
- data

- assign
- push_back
- pop_back
- insert
- erase
- swap
- clear
- emplace
- emplace_back

- get_allocator

(relational operators)
(swap)


MEMBER TYPE					DEFINITION										NOTES

- value_type				The first template parameter (T)	
- allocator_type			The second template parameter (Alloc)			defaults to: allocator<value_type>
- reference					allocator_type::reference						for the default allocator: value_type&
- const_reference			allocator_type::const_reference					for the default allocator: const value_type&
- pointer					allocator_type::pointer							for the default allocator: value_type*
- const_pointer				allocator_type::const_pointer					for the default allocator: const value_type*
- iterator					a random access iterator to value_type			convertible to const_iterator
- const_iterator			a random access iterator to const value_type	
- reverse_iterator			reverse_iterator<iterator>	
- const_reverse_iterator	reverse_iterator<const_iterator>	
- difference_type			a signed integral type, identical to: 
							iterator_traits<iterator>::difference_type		usually the same as ptrdiff_t
- size_type					an unsigned integral type that can represent 
							any non-negative value of difference_type		usually the same as size_t

*/
