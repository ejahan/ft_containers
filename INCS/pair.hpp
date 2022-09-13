/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:13:38 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/13 15:45:01 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace	ft {

template <class T1, class T2>
struct	pair
{
	T1	first;
	T2	second;

	pair() : first(0), second(0) {};

	pair(const T1 &x, const T2 &y) : first(x), second(y) {};

	template< class U1, class U2 >
	pair(const pair<U1, U2> &p) {*this = p};

	pair &operator=(const pair &other)
	{
		first = other.first;
		second = other.second;
		return (*this);
	};

};

}

#endif
