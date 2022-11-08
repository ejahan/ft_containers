/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:12:21 by ejahan            #+#    #+#             */
/*   Updated: 2022/11/08 13:48:08 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace	ft {

	template<class T>
	struct	is_integral
	{
		static const bool	value = false;
	};

	template<>
	struct	is_integral<bool>
	{
		static const bool	value = true;
	};

	template<>
	struct	is_integral<char>
	{
		static const bool	value = true;
	};

	template<>
	struct	is_integral<wchar_t>
	{
		static const bool	value = true;
	};

	template<>
	struct	is_integral<signed char>
	{
		static const bool	value = true;
	};

	template<>
	struct	is_integral<short int>
	{
		static const bool	value = true;
	};

	template<>
	struct	is_integral<long int>
	{
		static const bool	value = true;
	};

	template<>
	struct	is_integral<int>
	{
		static const bool	value = true;
	};

	template<>
	struct	is_integral<long long int>
	{
		static const bool	value = true;
	};

	template<>
	struct	is_integral<unsigned char>
	{
		static const bool	value = true;
	};

	template<>
	struct	is_integral<unsigned short int>
	{
		static const bool	value = true;
	};

	template<>
	struct	is_integral<unsigned int>
	{
		static const bool	value = true;
	};

	template<>
	struct	is_integral<unsigned long int>
	{
		static const bool	value = true;
	};

	template<>
	struct	is_integral<unsigned long long int>
	{
		static const bool	value = true;
	};
}

#endif
