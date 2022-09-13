/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:07:23 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/13 13:52:11 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
 
# include <iostream>
# include "vector.hpp"

namespace ft {

template <class T, class Container = std::vector<T> >
class	stack {

	private:

		Container	c;

	public:

		typedef typename	Container::value_type value_type;
		typedef typename	Container::size_type size_type;
		typedef Container container_type;

		stack(const Container& ctnr = Container()) : c(ctnr){}
		~stack();
		bool				empty(void) const;
		size_type			size(void) const;
		value_type			&top(void);
		const value_type	&top(void) const;
		void				push(const value_type &val);
		void				pop(void);

};

}

#endif

/*

	MEMBERS FUNCTIONS

- constructor
- empty
- size
- top
- push
- emplace
- pop
- swap

(relational operators)
(swap (stack))



MEMBER TYPE				DEFINITION										NOTES

- value_type			The first template parameter (T)				Type of the elements
- container_type		The second template parameter (Container)		Type of the underlying container
- size_type				an unsigned integral type						usually the same as size_t

*/
