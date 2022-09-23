/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:13:38 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/23 02:33:11 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace	ft {

// template <class T1, class T2>
// struct	pair
// {
// 	T1	first;
// 	T2	second;

// 	pair() : first(0), second(0) {};

// 	pair(const T1 &x, const T2 &y) : first(x), second(y) {};

// 	template< class U1, class U2 >
// 	pair(const pair<U1, U2> &p) {*this = p};

// 	pair &operator=(const pair &other)
// 	{
// 		first = other.first;
// 		second = other.second;
// 		return (*this);
// 	};

// };

template <class T1, class T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;

	T1 first;
	T2 second;

	pair() : first(T1()), second(T2()) {};

	pair(const T1& x, const T2& y) : first(x), second(y) {};

	template<class U, class V>
	pair(const pair<U, V> &p) : first(p.first), second(p.second) {};


	pair &operator=(const pair &other)
	{
		first = other.first;
		second = other.second;
		return (*this);
	};

};

template <class T1, class T2>
bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
	return (x.first == y.first && x.second == y.second);
};

template< class T1, class T2 >
bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
	return (x.first != y.first || x.second != y.second);
};

template <class T1, class T2>
bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
	return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
};

template< class T1, class T2 >
bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
	//	flemme
};

template< class T1, class T2 >
bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
	//	flemme
};

template< class T1, class T2 >
bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
	//	flemme
};

template <class T1, class T2>
pair<T1, T2> make_pair(const T1& x, const T2& y)
{
	return (pair<T1, T2>(x, y));
};

}

#endif
