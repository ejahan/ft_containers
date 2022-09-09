/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:07:23 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/07 18:08:29 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
 
# include <iostream>
 
class	stack {

	private:
	

	public:
		stack (void);
		stack(stack & cpy);
		~stack (void);

		stack & operator=(stack const & rhs);

};

#endif
