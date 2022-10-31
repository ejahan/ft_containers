/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:13:38 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/31 01:11:46 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

#include <iostream>

namespace	ft {

	template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		// static	T1 first;
		// static	T2 second;

		first_type first;
		second_type second;

		pair() : first(), second() {};

		pair(const T1& x, const T2& y) : first(x), second(y) {};

		template<class U, class V>
		pair(const pair<U, V> &p) : first(p.first), second(p.second) {};

		~pair() {};

		pair &operator=(const pair &other)
		{
			first = other.first;
			second = other.second;
			return (*this);
		};

	};

	template <class T1, class T2>
	bool operator==(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y)
	{
		return (x.first == y.first && x.second == y.second);
	};

	template < class T1, class T2 >
	bool operator!=( const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y )
	{
		// return (x.first != y.first || x.second != y.second);
		return (!(x == y));
	};

	template <class T1, class T2>
	bool operator<(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y)
	{
		if (x.first < y.first)
			return (true);
		else if (x.first == y.first && x.second < y.second)
			return (true);
		return (false);
	};

	template < class T1, class T2 >
	bool operator<=( const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y )
	{
		if (x == y || x < y)
			return (true);
		return (false);
	};

	template < class T1, class T2 >
	bool operator>( const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y )
	{
		if (x.first > y.first)
			return (true);
		else if (x.first == y.first && x.second > y.second)
			return (true);
		return (false);
	};

	template < class T1, class T2 >
	bool operator>=( const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y )
	{
		if (x == y || x > y)
			return (true);
		return (false);
	};


	// template<class T1, class T2>
	// std::ostream &operator<<(std::ostream &o, ft::pair<T1, T2> const &x)
	// {
	// 	o << "[" << x.first << " | " << x.second << "]";
	// 	return (o);
	// };

//=================================================================================

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(const T1& x, const T2& y)
	{
		return (ft::pair<T1, T2>(x, y));
	};

	// template< class T1, class T2 >
	// ft::pair<T1,T2> make_pair( T1 x, T2 y )
	// {
	// 	return (ft::pair<T1, T2>(x, y));
	// }

}

#endif
