/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:13:38 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/18 21:01:48 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace	ft {

template <class T1, class T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;

	// static	T1 first;
	// static	T2 second;
	
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
bool operator!=( const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y )
{
	return (x.first != y.first || x.second != y.second);
};

template <class T1, class T2>
bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
	return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
};

// template< class T1, class T2 >
// bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
// {
// 	//	flemme
// };

// template< class T1, class T2 >
// bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
// {
// 	//	flemme
// };

// template< class T1, class T2 >
// bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
// {
// 	//	flemme
// };

template <class T1, class T2>
pair<T1, T2> make_pair(const T1& x, const T2& y)
{
	return (pair<T1, T2>(x, y));
};





// template< class T1, class T2 >
// pair<T1,T2> make_pair( T1 x, T2 y )
// {
// 	return (pair<T1, T2>(x, y));
// }


}

#endif
