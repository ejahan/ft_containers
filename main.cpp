/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:50:27 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/19 22:32:55 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./INCS/vector.hpp"
#include "./INCS/stack.hpp"
#include "./INCS/rbt.hpp"
#include "./INCS/map.hpp"
#include <vector>
#include <stack>

// int main()
// {
// 	ft::red_black_tree<int> bst;
// 	bst.insert(-55);
// 	bst.insert(40);
// 	bst.insert(65);
// 	bst.insert(60);
// 	bst.insert(75);
// 	bst.insert(57);

// 	bst.print();
// 	std::cout << std::endl
// 		 << "After deleting" << std::endl;
// 	ft::Node<int>	*node = bst.searchTree(40);
// 	std::cout << node->key << std::endl;
// 	bst.delete_node(bst.searchTree(40));
// 	bst.delete_node(bst.searchTree(75));
// 	bst.print();
// 	ft::map<int, std::string>	test;
// 	// test.find(12);
// 	// test.insert(ft::pair<int, std::string>(1, "ca marche"));
// 	std::cout << std::endl << "size = " << test.size() << std::endl;

// 	return (0);
// }


// #include <map>

// int main()
// {
// 	std::map<int, std::string>	test;
// 	// test.find(12);
// 	// test.insert(ft::pair<int, std::string>(1, "ca marche"));
// 	test.insert(std::make_pair(45, "ca"));
// 	test.insert(std::pair<int, std::string>(1, "marche"));
// 	// std::cout << "[" << test[2] << "]" << std::endl; // -> pk ca fait size + 1?
// 	std::cout << std::endl << "size = " << test.size() << std::endl;

// 	return (0);
// }


#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>

int main() {
    ft::map<std::string, int> mapOfWordCount;
    // Insert Element in map
    // mapOfWordCount.insert(ft::pair<std::string, int>("first", 1));
    // mapOfWordCount.insert(ft::pair<std::string, int>("second", 2));
    // mapOfWordCount.insert(ft::pair<std::string, int>("third", 3));
    // mapOfWordCount.insert(ft::pair<std::string, int>("third", 4));
    // mapOfWordCount.insert(ft::pair<std::string, int>("third", 5));
    // Create a map iterator and point to beginning of map
    // ft::map<std::string, int>::iterator it = mapOfWordCount.begin();
    // Iterate over the map using Iterator till end.
	
    // while (it != mapOfWordCount.end())
    // {
    //     // Accessing KEY from element pointed by it.
    //     std::string word = it->first;
    //     // Accessing VALUE from element pointed by it.
        
	// 	// int count = it->second;
    //     // std::cout << word << " :: " << count << std::endl;

    //     // Increment the Iterator to point to next entry
    //     it++;
    // }
    return 0;
}
