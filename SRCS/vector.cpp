/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:09:03 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/15 18:54:45 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"


vector &vector::operator=(vector const & rhs)
{
    value_type  *
    return (*this);
}

explicit vector::vector(const allocator_type& alloc = allocator_type())
{
}

explicit vector::vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
{
}

vector::vector(const vector& x)
{
}

vector::~vector()
{
}

iterator	vector::begin()
{
}

const_iterator	vector::begin() const
{
}

iterator	vector::end()
{
}

const_iterator  	vector::end() const
{
}

reverse_iterator    vector::rbegin()
{
}

const_reverse_iterator	vector::rbegin() const
{
}

reverse_iterator    vector::rend()
{
}

const_reverse_iterator	vector::rend() const
{
}

const_iterator  	vector::cbegin() const
{
}

const_iterator  	vector::cend() const
{
}

const_reverse_iterator	vector::crbegin() const
{
}

const_reverse_iterator	vector::crend() const
{
}

size_type	vector::size() const
{
}

size_type	vector::max_size() const
{
}

void    vector::resize(size_type n, value_type val = value_type())
{
}

size_type	vector::capacity() const
{
}

bool    vector::empty() const
{
}

void    vector::reserve(size_type n)
{
}

void    vector::shrink_to_fit()
{
}

reference   vector::operator[](size_type n)
{
}

const_reference	vector::operator[](size_type n) const
{
}

reference   vector::at(size_type n)
{
}

const_reference	vector::at(size_type n) const
{
}

reference   vector::front()
{
}

const_reference	vector::front() const
{
}

reference   vector::back()
{
}

const_reference	vector::back() const
{
}

value_type* 	vector::data()
{
}

const value_type*	vector::data() const
{
}

void	vector::assign(size_type n, const value_type& val)
{
}

void	vector::push_back(const value_type& val)
{
}

void	vector::pop_back()
{
}

iterator	vector::insert(iterator position, const value_type& val)
{
}

void    vector::insert(iterator position, size_type n, const value_type& val)
{
}

iterator	vector::erase(iterator position)
{
}

iterator	vector::erase(iterator first, iterator last)
{
}

void	vector::swap(vector& x)
{
}

void	vector::clear()
{
}

allocator_type vector::get_allocator() const
{
}

