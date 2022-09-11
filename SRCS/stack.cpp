/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:09:18 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/11 20:35:21 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"

bool		stack::empty(void) const
{
	return (this->c.empty());
}

size_type	stack::size(void) const
{
	return (this->c.size());
}

value_type	&stack::top(void)
{
	return (this->c.back());
}

const value_type	&stack::top(void) const
{
	return (this->c.back);
}

void	stack::push(const value_type &val)
{
	this->c.push_back(val);
}

void	stack::pop(void)
{
	this->c.pop_back();
}

// void	stack::swap(stack& x)
// {
// 	this->c.swap(x);
// }
