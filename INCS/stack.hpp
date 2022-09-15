/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:07:23 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/15 18:11:23 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
 
# include <iostream>
# include "vector.hpp"

namespace ft {

template <class T, class Container = vector<T> >
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
