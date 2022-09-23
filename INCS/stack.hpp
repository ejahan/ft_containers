/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:07:23 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/23 01:06:26 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
 
# include <iostream>
# include "vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class	stack {

	protected:

		Container	c;

	public:

		typedef typename	Container::value_type value_type;
		typedef typename	Container::size_type size_type;
		typedef Container container_type;

		stack(const Container& ctnr = Container()) : c(ctnr){}
		~stack();

		bool				empty(void) const
		{
			return (this->c.empty());
		};

		size_type			size(void) const
		{
			return (this->c.size());
		};

		value_type			&top(void)
		{
			return (this->c.back());
		};

		const value_type	&top(void) const
		{
			return (this->c.back());
		};

		void				push(const value_type &val)
		{
			this->c.push_back(val);
		};

		void				pop(void)
		{
			this->c.pop_back();
		};

};

}

#endif
