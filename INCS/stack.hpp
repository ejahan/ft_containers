/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:07:23 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/11 18:58:36 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
 
# include <iostream>

template <class T, class Container = deque<T> > // vector?
class	stack {

	private:
	

	public:

		stack();//(const container_type& ctnr = container_type());
		bool				empty(void) const;
		size_type			size(void) const;
		value_type			&top(void);
		const value_type	&top(void) const;
		void				push(const value_type &val);

		template <class... Args>
		void	emplace(Args&&... args);

		void				pop(void);
		void				swap(stack& x); // noexcept(); ?

		// stack(stack & cpy);
		// ~stack (void);
		// stack & operator=(stack const & rhs);

};

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

*/

/*

MEMBER TYPE				DEFINITION										NOTES


value_type				The first template parameter (T)				Type of the elements

container_type			The second template parameter (Container)		Type of the underlying container

size_type				an unsigned integral type						usually the same as size_t

*/
