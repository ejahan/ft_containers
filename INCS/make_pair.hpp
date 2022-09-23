/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:14:20 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/23 02:20:25 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

namespace	ft {

template< class T1, class T2 >
pair<T1,T2> make_pair( T1 x, T2 y )
{
	return (pair<T1, T2>(x, y));
}

}

#endif

/*
	>>>>> sert plus a rien -> voir pair.hpp
*/
