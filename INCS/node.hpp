/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:53:46 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/30 20:07:23 by ejahan           ###   ########.fr       */
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
		Node(const Node<T> &other) : key(other.key), leftChild(other.leftChild), rightChild(other.rightChild), parent(other.parent), _nil(other._nil)// {};
		{
			// std::cout << "COPY" << std::endl;
			// *this = other;
		};

		Node(T val) : key(val)
		{
			// std::cout << "CONSTRUCTOR" << std::endl;
		};

		Node<T> & operator=(Node<T> const & other)
		{
			// key = other.key;
			leftChild = other.leftChild;
			rightChild = other.rightChild;
			parent = other.parent;
			_nil = other._nil;
			return (*this);
		};
		
		~Node() {};

	};

}

#endif
