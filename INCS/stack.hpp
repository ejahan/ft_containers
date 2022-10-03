/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:07:23 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/03 18:47:47 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft {

	template <class T, class Container = ft::vector<T> >
	class	stack {

		protected:

			Container	c;

		public:

			typedef typename	Container::value_type	value_type;
			typedef typename	Container::size_type	size_type;
			typedef Container							container_type;

			stack(const Container& ctnr = Container()) : c(ctnr) {};

			~stack() {};

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

			template <class _T, class _Container>
			friend bool operator== (const stack< _T, _Container > &lhs, const stack< _T, _Container > &rhs);

			template <class _T, class _Container>
			friend bool operator!= (const stack< _T, _Container > &lhs, const stack< _T, _Container > &rhs);

			template <class _T, class _Container>
			friend bool operator< (const stack< _T, _Container > &lhs, const stack< _T, _Container > &rhs);

			template <class _T, class _Container>
			friend bool operator<= (const stack< _T, _Container > &lhs, const stack< _T, _Container > &rhs);

			template <class _T, class _Container>
			friend bool operator> (const stack< _T, _Container > &lhs, const stack< _T, _Container > &rhs);

			template <class _T, class _Container>
			friend bool operator>= (const stack< _T, _Container > &lhs, const stack< _T, _Container > &rhs);

	};

	template< class T, class Container >
	bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		if (lhs.c == rhs.c)
			return (true);
		return (false);
	};

	template< class T, class Container >
	bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		if (lhs.c != rhs.c)
			return (true);
		return (false);
	};

	template< class T, class Container >
	bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		if (lhs.c < rhs.c)
			return (true);
		return (false);
	};

	template< class T, class Container >
	bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		if (lhs.c <= rhs.c)
			return (true);
		return (false);
	};

	template< class T, class Container >
	bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		if (lhs.c > rhs.c)
			return (true);
		return (false);
	};

	template< class T, class Container >
	bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		if (lhs.c >= rhs.c)
			return (true);
		return (false);
	};

}

#endif
