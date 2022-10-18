/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:50:27 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/18 21:36:46 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCS/vector.hpp"
#include "./INCS/stack.hpp"
#include "./INCS/rbt.hpp"
#include "./INCS/map.hpp"
#include <vector>
#include <stack>

int main()
{
	ft::red_black_tree<int> bst;
	bst.insert(-55);
	bst.insert(40);
	bst.insert(65);
	bst.insert(60);
	bst.insert(75);
	bst.insert(57);

	bst.print();
	std::cout << std::endl
		 << "After deleting" << std::endl;
	ft::Node<int>	*node = bst.searchTree(40);
	std::cout << node->key << std::endl;
	bst.delete_node(bst.searchTree(40));
	bst.delete_node(bst.searchTree(75));
	bst.print();
	ft::map<int, std::string>	test;
	// test.find(12);
	// test.insert(ft::pair<int, std::string>(1, "ca marche"));
	std::cout << std::endl << "size = " << test.size() << std::endl;

	return (0);
}
