/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:12:21 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/22 23:35:10 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace	ft {

template < class T >
struct	is_integral
{
	static	bool	value;	//	true if T is an integral type , false otherwise

	typedef	bool	value_type;
	typedef	std::integral_constant<bool, value>;

	operator	bool()	const	//	operator bool	->	converts the object to bool, returns value
	{
		return (value);
	};

	/*
		J AI RIEN COMPRIS ON VERRA PLUS TARD
	*/

};


}

#endif
