/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:53:46 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/26 17:29:28 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

namespace ft
{

	template<class T>
	struct	Node
	{
		int		color;
		T		key;
		Node	*leftChild;
		Node	*rightChild;
		Node	*parent;
		Node	*_nil;

		Node() {};
		Node(T val) : key(val) {};
		~Node() {};

	};

}

#endif
