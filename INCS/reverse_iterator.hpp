/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:10:32 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/13 16:40:39 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace	ft {

template <class Iter>
class	reverse_iterator
{

	protected:

		Iter	current;

	public: 

		reverse_iterator();
		explicit reverse_iterator( iterator_type x );
		template< class U >
		reverse_iterator( const reverse_iterator<U>& other );

};

}

#endif

    explicit reverse_iterator(Itr itr): itr(itr) {}
    auto& operator*() {
        return *std::prev(itr); // <== returns the content of prev
    }
    auto& operator++() {
        --itr;
        return *this;
    }
    friend bool operator!=(reverse_iterator<Itr> a, reverse_iterator<Itr> b) {
        return a.itr != b.itr;
    }