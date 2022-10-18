/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:03:59 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/18 21:49:38 by ejahan           ###   ########.fr       */
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

			Allocator			_alloc;
			Compare				_cmp;
			// pair<const Key, T>	*_p;	//	first -> Key, second -> T
			ft::red_black_tree<pair<const Key, T> >	_p;
			Node<ft::pair<const Key, T> >	*_nil;

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
			typedef ft::rbt_iterator<T>						iterator;
			typedef ft::rbt_iterator<const T>				const_iterator;
			typedef size_t									size_type;
			typedef ptrdiff_t			 					difference_type;
			typedef typename Allocator::pointer 			pointer;
			typedef typename Allocator::const_pointer 		const_pointer;
			typedef ft::rev_rbt_iterator<iterator> 			reverse_iterator;
			typedef ft::rev_rbt_iterator<const_iterator> 	const_reverse_iterator;

			class value_compare : public std::binary_function< value_type, value_type,bool >
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


			// map()
			// {
			// 	_cmp = Compare();
			// 	_allocator = Allocator();
			// };

			explicit map( const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
			{
				_cmp = comp;
				_alloc = alloc;
			};

			template< class InputIterator >
			map( InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
			{
				_cmp = comp;
				_alloc = alloc;
				insert(first, last);
			};

			// map( const map<Key, T, Compare, Allocator>	&other )
			// {	
			// };

			~map() {};

			// map<Key, T, Compare, Allocator> & operator=(map<Key, T, Compare, Allocator> const & rhs)
			// {
			// };


			//	ITERATORS
			iterator				begin()
			{
				iterator	test(this->_p.root());
				return (test);
			};

			const_iterator			begin() const
			{
				const_iterator	test(this->_p.root());
				return (test);
			};

			iterator				end()
			{
				iterator	it(_p.root() + _p.size());
				return (it);
			};

			const_iterator			end() const
			{
				const_iterator	it(this->_p.root() + this->_p.size());
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
				if (_p.size() <= 0)
					return true;
				else
					return false;
			};

			size_type	size() const
			{
				return (this->_p.size());
			};

			size_type	max_size() const
			{
				return (this->_allocator.max_size());
			};


			// 	ELEMENT ACCESS

			const_reference	at(size_type n) const
			{
				if (this->_p.size() < n)
					throw std::out_of_range("ERROR : out_of_range exception");
				return (*(this->begin() + n));
			};

			mapped_type&		operator[](const key_type& k)
			{
				return (*(this->begin() + k));
			};

			mapped_type&		at(const key_type& k)
			{
				if (this->_p.size() < k)
					throw std::out_of_range("ERROR : out_of_range exception");
				return (*(this->begin() + k));
			};

			const mapped_type&	at(const key_type& k) const
			{
				if (this->_p.size() < k)
					throw std::out_of_range("ERROR : out_of_range exception");
				return (*(this->begin() + k));
			};


			// 	MODIFIERS

			ft::pair<iterator, bool> insert( const value_type& value )
			{
				if (_p.searchTree(value) == _nil)
					_p.insert(value);
				return (value);
			};

			iterator			insert (iterator position, const value_type& val)
			{
				(void)position;
				if (_p.searchTree(val) == _nil)
					_p.insert(val);
				return (iterator(_p.searchTree(val)));
			};

			template <class InputIterator>
			void	insert (InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
			{
				while (first != last)
				{
					insert(*first);
					first++;
				}
			};

			void			erase(iterator position)
			{
				_p.delete_node(position);
			};

			// size_type		erase(const key_type& k)
			// {
			// 	Node<T>	*node = _p.root();
			// 	if (node == _nil)
			// 		return (0);
			// 	while (node != _nil && node->key->first != k)
			// 	{
			// 		// en fait non
			// 	}
			// };

			void			erase(iterator first, iterator last)
			{
				while (first != last)
				{
					erase(*first);
					first++;
				}
			};

			void			swap(map& x)
			{
				std::swap(this->_p, x._p);
				std::swap(this->_allocator, x._allocator);
				std::swap(this->_size, x._size);
				std::swap(this->_cmp, x._cmp);
			};

			void			clear()
			{
				while (size() > 0)
					erase(begin());
			};


			// 	OBSERVERS

			// j ai pas trop compris
			key_compare		key_comp() const
			{
				return (key_compare());
			};

			// j ai pas trop compris
			value_compare	value_comp() const
			{
				return (value_compare());
			};

			iterator		find(const key_type &k)
			{
				iterator	it(_p.root());
				while (it != _nil)
				{
					// if (key_compare(k, *it->key) == 1)
					if (*it->key == k)
						return (k);
				}
				return (end());
			};

			const_iterator	find(const key_type &k) const
			{
				const_iterator	it(_p.root());
				while (it != _nil)
				{
					if (*it->key == k)
						return (k);
				}
				return (end());
			};

			size_type		count(const key_type &k) const
			{
				const_iterator	it(_p.root());
				while (it != _nil)
				{
					if (*it->key == k)
						return (1);
				}
				return (0);
			};

			// iterator		lower_bound(const key_type &k)
			// {
			// 	// flemme
			// };

			// const_iterator	lower_bound(const key_type &k) const
			// {
			// };

			// iterator		upper_bound(const key_type &k)
			// {
			// };

			// const_iterator	upper_bound(const key_type &k) const
			// {
			// };

			// pair<const_iterator,const_iterator>	equal_range(const key_type &k) const
			// {
			// };

			// pair<iterator,iterator>	equal_range(const key_type &k)
			// {
			// };

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


		// // OPERATORS
		// template< class Key, class T, class Compare, class Alloc >
		// bool operator==( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		// {
		// 	if (equal(lhs.front(), lhs.back(), rhs.front()) == true)
		// 		return (true);
		// 	return (false);
		// };

		// template< class Key, class T, class Compare, class Alloc >
		// bool operator!=( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		// {
		// 	if (equal(lhs.front(), lhs.back(), rhs.front()) == false)
		// 		return (true);
		// 	return (false);
		// };

		// template< class Key, class T, class Compare, class Alloc >
		// bool operator<( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		// {
		// 	if (lexicographical_compare(lhs.front(), lhs.back(), rhs.front(), rhs.back()) == true)
		// 		return (true);
		// 	return (false);
		// };

		// template< class Key, class T, class Compare, class Alloc >
		// bool operator<=( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		// {
		// 	if (lexicographical_compare(lhs.front(), lhs.back(), rhs.front(), rhs.back()) == true
		// 			|| equal(lhs.front(), lhs.back(), rhs.front()) == true)
		// 		return (true);
		// 	return (false);
		// };

		// template< class Key, class T, class Compare, class Alloc >
		// bool operator>( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		// {
		// 	if (lexicographical_compare(lhs.front(), lhs.back(), rhs.front(), rhs.back()) == false)
		// 		return (true);
		// 	return (false);
		// };

		// template< class Key, class T, class Compare, class Alloc >
		// bool operator>=( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		// {
		// 	if (lexicographical_compare(lhs.front(), lhs.back(), rhs.front(), rhs.back()) == false
		// 			|| equal(lhs.front(), lhs.back(), rhs.front()) == true)
		// 		return (true);
		// 	return (false);
		// };

}

#endif
