/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:03:08 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/16 19:59:17 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

namespace	ft
{

	template <class InputIt1, class InputIt2>
	bool	lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		--last1;
		--last2;
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 )
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template< class InputIt1, class InputIt2 >
	bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2)
	{
		// std::cout << "EQUAL" << std::endl;
		// --last1;
		for ( ; (first1 != last1); ++first1, ++first2)
		{
			// std::cout << "EQUAL2" << std::endl;
			if (*first1 != *first2)
				return false;
		}
		return (true);
	};

}

#endif
