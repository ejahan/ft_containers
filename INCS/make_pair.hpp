/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:14:20 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/13 15:40:36 by ejahan           ###   ########.fr       */
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
