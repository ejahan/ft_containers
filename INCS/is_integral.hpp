/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:12:21 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/12 16:22:21 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace	ft {

// template < class T >
// struct	is_integral
// {
// 	static	bool	value;	//	true if T is an integral type , false otherwise

// 	typedef	bool	value_type;
// 	typedef	std::integral_constant<bool, value>;

// 	operator	bool()	const	//	operator bool	->	converts the object to bool, returns value
// 	{
// 		return (value);
// 	};

// 	/*
// 		J AI RIEN COMPRIS ON VERRA PLUS TARD
// 	*/

// };

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

// bool
// char
// char16_t
// char32_t
// wchar_t
// signed char
// short int
// int
// long int
// long long int
// unsigned char
// unsigned short int
// unsigned int
// unsigned long int
// unsigned long long int