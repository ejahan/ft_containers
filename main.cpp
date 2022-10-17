/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:50:27 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/17 21:48:14 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./INCS/vector.hpp"
#include "./INCS/stack.hpp"
#include "./INCS/rbt.hpp"
#include <vector>
#include <stack>

int main()
{
	red_black_tree<int> bst;
	bst.insert(55);
	bst.insert(40);
	bst.insert(65);
	bst.insert(60);
	bst.insert(75);
	bst.insert(57);

	bst.print();
	std::cout << std::endl
		 << "After deleting" << std::endl;
	bst.delete_node(bst.searchTree(40));
	bst.print();
	
	return (0);
}
