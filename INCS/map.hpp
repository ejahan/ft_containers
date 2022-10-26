/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:03:59 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/26 23:11:32 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "pair.hpp"
#include "reverse_iterator.hpp"
#include "random_access.hpp"
#include "is_integral.hpp"
#include "iterator_traits.hpp"
#include "lexicographical_compare.hpp"
#include "enable_if.hpp"
#include "rbt_iterator.hpp"
#include "node.hpp"
#include "rbt.hpp"

namespace ft {

	template <	class Key, class T, class Compare = std::less<Key>,
				class Allocator = std::allocator<ft::pair<const Key,T> > >
	class	map {

		private:

			Allocator			_alloc;
			Compare				_cmp;
			ft::red_black_tree< ft::pair< const Key, T> >	_p;

		public:


			/*
				TYPES
			*/

			typedef Key 									key_type;
			typedef T 										mapped_type;
			typedef ft::pair<const Key, T> 					value_type;
			typedef Compare 								key_compare;
			typedef Allocator 								allocator_type;
			typedef typename Allocator::reference 			reference;
			typedef typename Allocator::const_reference 	const_reference;
			typedef ft::rbt_iterator<ft::pair<const Key,T> >	iterator;
			typedef ft::rbt_iterator<ft::pair<const Key,T> >	const_iterator;
			typedef size_t									size_type;
			typedef ptrdiff_t			 					difference_type;
			typedef typename Allocator::pointer 			pointer;
			typedef typename Allocator::const_pointer 		const_pointer;
			typedef ft::reverse_iterator<iterator> 			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> 	const_reverse_iterator;

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

			map( const map<Key, T, Compare, Allocator>	&other )
			{
				iterator	it = other.begin();
				// while (it != other.end())
					// insert(*it);
			};

			~map() {};

			map<Key, T, Compare, Allocator> & operator=(map<Key, T, Compare, Allocator> const & rhs)
			{
				iterator	it = rhs.begin();
				while (it != rhs.end())
					insert(*it);
			};


			//	ITERATORS
			iterator				begin()
			{
				iterator	test(this->_p.rbt_min(_p.root()));
				return (test);
			};

			const_iterator			begin() const
			{
				const_iterator	test(this->_p.rbt_min(_p.root()));
				return (test);
			};

			iterator				end()
			{
				iterator	it(_p.nil());
				return (it);
			};

			const_iterator			end() const
			{
				const_iterator	it(this->_p.nil());
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
				return (this->_alloc.max_size());
			};


			// 	ELEMENT ACCESS

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

			ft::pair<iterator, bool> insert( const value_type& val )
			{
				_p.insert(val);
				return (ft::make_pair(begin(), 1));
			};

			iterator			insert (iterator position, const value_type& val)
			{
				(void)position;
				if (_p.searchTree(val) != _p.nil())
					return (_p.searchTree(val));
				return (iterator(_p.insert(val)));
			};

			template <class InputIterator>
			void	insert (InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
			{
				while (first != last)
				{
					// std::cout << "ta mere" << std::endl;
					insert(*first);
					first++;
				}
			};

			void			erase(iterator position)
			{
				_p.delete_node(*position);
			};

			size_type		erase(const key_type& k)
			{
				iterator	it(_p.rbt_min(_p.root()));
				ft::Node<ft::pair<const Key, T > >	*node;

				while (it != _p.nil())
				{
					std::cout << "erase" << std::endl;
					node = it.base();
					if (node->key.first == k)
					{
						_p.delete_node(node);
						return (1);
					}
					it++;
				}
				return (0);
			};

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
				std::swap(this->_cmp, x._cmp);
			};

			void			clear()
			{
				while (size() > 0)
					erase(begin());
			};


			// // 	OBSERVERS

			// // j ai pas trop compris je crois
			// key_compare		key_comp() const
			// {
			// 	return (_cmp);
			// };

			// // j ai pas trop compris non plus du coup 
			// value_compare	value_comp() const
			// {
			// 	return (value_compare());
			// };

			iterator		find(const key_type &k)
			{
				iterator	it(_p.rbt_min(_p.root()));
				ft::Node<ft::pair<const Key, T > >	*node;
				while (it != _p.nil())
				{
					node = it.base();
					if (node->key.first == k)
						return (it);
					it++;
				}
				return (end());
			};

			const_iterator	find(const key_type &k) const
			{
				const_iterator	it(_p.rbt_min(_p.root()));
				ft::Node<ft::pair<const Key, T > >	*node;

				while (it != _p.nil())
				{
					node = it.base();
					if (node->key.first == k)
						return (it);
					it++;
				}
				return (end());
			};

			size_type		count(const key_type &k) const
			{
				const_iterator	it(_p.root());
				ft::Node<ft::pair<const Key, T > >	*node;

				while (it != _p.nil())
				{
					node = it.base();
					if (node->key.first == k)
						return (1);
					it++;
				}
				return (0);
			};

			iterator		lower_bound(const key_type &k)
			{
				iterator	it(_p.root());
				ft::Node<ft::pair<const Key, T > >	*node;

				// std::cout << "LOWER_BOUND" << std::endl;
				while (it != _p.nil())
				{
					node = it.base();
					if (node->key.first == k)
						return (it);
					it++;
				}
				return (it);
			};

			const_iterator	lower_bound(const key_type &k) const
			{
				const_iterator	it(_p.root());
				ft::Node<ft::pair<const Key, T > >	*node;

				// std::cout << "LOWER_BOUND" << std::endl;
				while (it != _p.nil())
				{
					node = it.base();
					if (node->key.first == k)
						return (it);
					it++;
				}
				return (it);
			};

			iterator		upper_bound(const key_type &k)
			{
				iterator	it(_p.root());
				ft::Node<ft::pair<const Key, T > >	*node;

				// std::cout << "UPPER_BOUND" << std::endl;
				while (it != _p.nil())
				{
					node = it.base();
					if (node->key.first == k)
						return (it);
					it++;
				}
				return (it);
			};

			const_iterator	upper_bound(const key_type &k) const
			{
				const_iterator	it(_p.root());
				ft::Node<ft::pair<const Key, T > >	*node;

				// std::cout << "UPPER_BOUND" << std::endl;
				while (it != _p.nil())
				{
					node = it.base();
					if (node->key.first == k)
						return (it);
					it++;
				}
				return (it);
			};

			pair<const_iterator,const_iterator>	equal_range(const key_type &k) const
			{
				// std::cout << "EQUAL_RANGE" << std::endl;
				return (ft::make_pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k)));
			};

			pair<iterator,iterator>	equal_range(const key_type &k)
			{
				// std::cout << "EQUAL_RANGE" << std::endl;
				return (ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
			};

			allocator_type	get_allocator() const
			{
				return (this->_allocator);
			};

			void	print()
			{
				_p.print();
			}

	};

		template< class Key, class T, class Compare, class Alloc >
		void swap( map<Key,T,Compare,Alloc> &lhs, map<Key,T,Compare,Alloc> &rhs )
		{
			lhs.swap(rhs);
		};


		/*
		======================================================================================
		OPERATORS
		======================================================================================
		*/

		template< class Key, class T, class Compare, class Alloc >
		bool	operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		{
			if ((lhs.size() == rhs.size())
					&& (ft::equal(lhs.begin(), lhs.end(), rhs.begin())) == true)
				return (true);
			return (false);
		};

		template< class Key, class T, class Compare, class Alloc >
		bool	operator!=( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		{
			if (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) == false
					|| (lhs.size() != rhs.size()))
				return (true);
			return (false);
		};

		template< class Key, class T, class Compare, class Alloc >
		bool	operator<( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		{
			if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) == true)
				return (true);
			return (false);
		};

		template< class Key, class T, class Compare, class Alloc >
		bool	operator<=( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		{
			if (lhs < rhs || lhs == rhs)
				return (true);
			return (false);
		};

		template< class Key, class T, class Compare, class Alloc >
		bool	operator>( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		{
			if (lhs <= rhs)
				return (false);
			return (true);
		};

		template< class Key, class T, class Compare, class Alloc >
		bool	operator>=( const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs )
		{
			if (lhs < rhs)
				return (false);
			return (true);
		};

}

#endif
