/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:11:26 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/13 14:41:42 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft {

template <bool B, class T = void>
struct	enable_if {};

template <class T>
struct	enable_if <true, T>
{
	typedef T type;
};

}

#endif
