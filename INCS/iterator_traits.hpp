/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:05:50 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/13 17:02:05 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	iterator_traits<Iterator>::difference_type
	iterator_traits<Iterator>::value_type
	iterator_traits<Iterator>::iterator_category
	iterator_traits<Iterator>::difference_type
	iterator_traits<Iterator>::value_type

template<class Iterator>
struct iterator_traits
{
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
	typedef typename Iterator::iterator_category iterator_category;
};
//	NTMMMMM