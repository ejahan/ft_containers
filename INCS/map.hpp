/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:03:59 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/11 20:42:53 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
 
# include <iostream>

namespace ft {

template < class Key,                                     // map::key_type
		   class T,                                       // map::mapped_type
           class Compare = less<Key>,                     // map::key_compare
           class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
           >
class	map {

	private:


	public:
		// map (void);
		// map(map & cpy);
		// ~map (void);

		// map & operator=(map const & rhs);
		map();
		~map();
		map & operator=(map const & rhs);

		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;
		const_iterator			cbegin() const;
		const_iterator			cend() const;
		const_reverse_iterator	crbegin() const;
		const_reverse_iterator	crend() const;

		bool		empty() const;
		size_type	size() const;
		size_type	max_size() const;

		mapped_type&		operator[](const key_type& k);
		mapped_type&		at(const key_type& k);
		const mapped_type&	at(const key_type& k) const;

		pair<iterator,bool> insert (const value_type& val);
		iterator			insert (iterator position, const value_type& val);
		
		template <class InputIterator>
		void				insert (InputIterator first, InputIterator last);

		void		erase(iterator position);
		size_type	erase(const key_type& k);
		void		erase(iterator first, iterator last);
		void		swap(map& x);
		void		clear();

		template <class... Args>
		pair<iterator,bool>	emplace(Args&&... args);

		template <class... Args>
		iterator		emplace_hint(const_iterator position, Args&&... args);

		key_compare		key_comp() const;
		value_compare	value_comp() const;

		iterator		find(const key_type& k);
		const_iterator	find(const key_type& k) const;

		size_type		count(const key_type& k) const;

		iterator		lower_bound(const key_type& k);
		const_iterator	lower_bound(const key_type& k) const;

		iterator		upper_bound(const key_type& k);
		const_iterator	upper_bound(const key_type& k) const;

		pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
		pair<iterator,iterator>             equal_range(const key_type& k);

		allocator_type	get_allocator() const;

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

- empty
- size
- max_size

- operator[]
- at

- insert
- erase
- swap
- clear
- emplace
- emplace_hint

- key_comp
- value_comp

- find
- count
- lower_bound
- upper_bound
- equal_range

- get_allocator



MEMBER TYPE					DEFINITION										NOTES

- key_type					The first template parameter (Key)	
- mapped_type				The second template parameter (T)
- value_type				pair<const key_type,mapped_type>	
- key_compare				The third template parameter (Compare)			defaults to: less<key_type>
- value_compare				Nested function class to compare elements		see value_comp
- allocator_type			The second template parameter (Alloc)			defaults to: allocator<value_type>
- reference					allocator_type::reference						for the default allocator: value_type&
- const_reference			allocator_type::const_reference					for the default allocator: const value_type&
- pointer					allocator_type::pointer							for the default allocator: value_type*
- const_pointer				allocator_type::const_pointer					for the default allocator: const value_type*
- iterator					a bidirectional iterator to value_type			convertible to const_iterator
- const_iterator			a bidirectional iterator to const value_type	
- reverse_iterator			reverse_iterator<iterator>	
- const_reverse_iterator	reverse_iterator<const_iterator>	
- difference_type			a signed integral type, identical to: 
							iterator_traits<iterator>::difference_type		usually the same as ptrdiff_t
- size_type					an unsigned integral type that can represent 
							any non-negative value of difference_type		usually the same as size_t

*/
