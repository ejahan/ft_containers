/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:03:59 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/09 03:01:14 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "pair.hpp"
#include "reverse_iterator.hpp"
#include "random_access.hpp"
#include "iterator_traits.hpp"
#include "lexicographical_compare.hpp"

namespace ft {

	template <	class Key, class T, class Compare = std::less<Key>,
				class Allocator = std::allocator<ft::pair<const Key,T> > >
	class	map {

		private:

			Allocator			_allocator;
			pair<const Key, T>	*_p;
			size_t				_size;

		public:


			/*
				TYPES
			*/

			typedef Key 									key_type;
			typedef T 										mapped_type;
			typedef pair<const Key, T> 						value_type;
			typedef Compare 								key_compare;
			typedef Allocator 								allocator_type;
			typedef typename Allocator::reference 			reference;
			typedef typename Allocator::const_reference 	const_reference;
			typedef ft::random_access_iterator<T>			iterator;
			typedef ft::random_access_iterator<const T>		const_iterator;
			typedef size_t									size_type;
			typedef ptrdiff_t			 					difference_type;
			typedef typename Allocator::pointer 			pointer;
			typedef typename Allocator::const_pointer 		const_pointer;
			typedef ft::reverse_iterator<iterator> 			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> 	const_reverse_iterator;


			class value_compare : public binary_function<value_type,value_type,bool>
			{
				friend class map;
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}
				public:
					bool operator()(const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};


			/*
				MEMBER FUNCTIONS
			*/


			// map();
			// explicit map( const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
			// {
			// };

			// template< class InputIterator >
			// map( InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
			// {
			// };

			// map( const map<Key, T, Compare, Allocator>	&other )	//	map<Key, T, Compare, Allocator> ?
			// {	
			// };

			// ~map()
			// {
			// };

			// map<Key, T, Compare, Allocator> & operator=(map<Key, T, Compare, Allocator> const & rhs)	//	map<Key, T, Compare, Allocator> ?
			// {
			// };


			//	ITERATORS
			iterator				begin()
			{
				iterator	test(this->_p);
				return (test);
			};

			const_iterator			begin() const
			{
				const_iterator	test(this->_p);
				return (test);
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


			//	CAPACITY
			bool		empty() const
			{
				if (this->_size <= 0)
					return true;
				else
					return false;
			};

			size_type	size() const
			{
				return (this->_size);
			};

			size_type	max_size() const
			{
				return (this->_allocator.max_size());
			};


			// 	ELEMENT ACCESS
			// mapped_type&		operator[](const key_type& k);
			// mapped_type&		at(const key_type& k);
			// const mapped_type&	at(const key_type& k) const;


			// 	MODIFIERS
			// pair<iterator,bool> insert (const value_type& val);
			// iterator			insert (iterator position, const value_type& val);
			
			// template <class InputIterator>
			// void				insert (InputIterator first, InputIterator last);

			// void			erase(iterator position);
			// size_type		erase(const key_type& k);
			// void			erase(iterator first, iterator last);
			// void			swap(map& x);
			// void			clear();


			// 	OBSERVERS
			// key_compare		key_comp() const;
			// value_compare	value_comp() const;
			// iterator		find(const key_type &k);
			// const_iterator	find(const key_type &k) const;
			// size_type		count(const key_type &k) const;
			// iterator		lower_bound(const key_type &k);
			// const_iterator	lower_bound(const key_type &k) const;
			// iterator		upper_bound(const key_type &k);
			// const_iterator	upper_bound(const key_type &k) const;
			// pair<const_iterator,const_iterator> equal_range(const key_type &k) const;
			// pair<iterator,iterator>             equal_range(const key_type &k);

			allocator_type	get_allocator() const
			{
				return (this->_allocator);
			};

	};

		template< class Key, class T, class Compare, class Alloc >
		void swap( map<Key,T,Compare,Alloc> &lhs, map<Key,T,Compare,Alloc> &rhs )
		{
			lhs.swap(rhs);
		};


		// OPERATORS
		template< class Key, class T, class Compare, class Alloc >
		bool operator==( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		{
			if (equal(lhs.front(), lhs.back(), rhs.front()) == true)
				return (true);
			return (false);
		};

		template< class Key, class T, class Compare, class Alloc >
		bool operator!=( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		{
			if (equal(lhs.front(), lhs.back(), rhs.front()) == false)
				return (true);
			return (false);
		};

		template< class Key, class T, class Compare, class Alloc >
		bool operator<( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		{
			if (lexicographical_compare(lhs.front(), lhs.back(), rhs.front(), rhs.back()) == true)
				return (true);
			return (false);
		};

		template< class Key, class T, class Compare, class Alloc >
		bool operator<=( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		{
			if (lexicographical_compare(lhs.front(), lhs.back(), rhs.front(), rhs.back()) == true
					|| equal(lhs.front(), lhs.back(), rhs.front()) == true)
				return (true);
			return (false);
		};

		template< class Key, class T, class Compare, class Alloc >
		bool operator>( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		{
			if (lexicographical_compare(lhs.front(), lhs.back(), rhs.front(), rhs.back()) == false)
				return (true);
			return (false);
		};

		template< class Key, class T, class Compare, class Alloc >
		bool operator>=( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		{
			if (lexicographical_compare(lhs.front(), lhs.back(), rhs.front(), rhs.back()) == false
					|| equal(lhs.front(), lhs.back(), rhs.front()) == true)
				return (true);
			return (false);
		};

}

#endif
