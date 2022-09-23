/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:05:50 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/23 00:08:17 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace	ft {

template <class Iterator>
struct	iterator_traits
{
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
	typedef typename Iterator::iterator_category iterator_category;
};

template <class T>
struct	iterator_traits<T*>
{
	typedef	ptrdiff_t	difference_type;
	typedef	T			value_type;
	typedef	T			*pointer;
	typedef	T			&reference;
	typedef	random_access_iterator_tag	iterator_category;
};

template <class T>
struct	iterator_traits<const T*>
{
	typedef	ptrdiff_t	difference_type;
	typedef	T			value_type;
	typedef	const T		*pointer;
	typedef	const T		&reference;
	typedef	random_access_iterator_tag	iterator_category;
};

}

#endif
