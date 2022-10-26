/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:50:27 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/26 11:52:50 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./INCS/vector.hpp"
// #include "./INCS/stack.hpp"
#include "./INCS/rbt.hpp"
#include "./INCS/map.hpp"
// #include <vector>
// #include <stack>

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
// 	// bst.delete_node(bst.searchTree(75));
// 	bst.print();
// 	ft::rbt_iterator< int > it(bst.insert(12));
// 	std::cout << std::endl << "AFTER INSERT 12" << std::endl << std::endl;
// 	bst.print();
// 	ft::rbt_iterator< int > it2(bst.searchTree(57));
	
// 	std::cout << std::endl << "it = [" << *it << "]" << std::endl;
// 	it++;
// 	std::cout << "it++ = [" << *it << "]" << std::endl;
// 	++it;
// 	std::cout << "++it = [" << *it << "]" << std::endl;
// 	it--;
// 	std::cout << "it-- = [" << *it << "]" << std::endl;
// 	it--;
// 	std::cout << "it-- = [" << *it << "]" << std::endl;
// 	// std::cout << "it2 = [" << *it2 << "]" << std::endl;

// 	return (0);
// }









// #include <map>

// int main()
// {
// 	std::map<int, std::string>	test;
// 	// test.find(12);
// 	// test.insert(ft::pair<int, std::string>(1, "ca marche"));
// 	// test.insert(std::make_pair(45, "ca"));
// 	test.insert(std::pair<int, std::string>(1, "ca"));
// 	test.insert(std::pair<int, std::string>(2, "marche"));
// 	test.insert(std::pair<int, std::string>(3, "ok"));
// 	std::cout << "[" << test[0] << "]" << std::endl; // -> pk ca fait size + 1?
// 	std::cout << std::endl << "size = " << test.size() << std::endl;

// 	return (0);
// }


// int main()
// {
// 	ft::red_black_tree<ft::pair<std::string, int > > bst;
// 	ft::pair<std::string, int>	test("first", 1);

// 	bst.insert(test);

// 	return (0);
// }



int main()
{
	ft::map<std::string, int>	maptest;
	// ft::map<std::string, int>	map_copy = maptest;


	std::cout << "size = " << maptest.size() << std::endl;
	// Insert Element in map

	// ft::pair<std::string, int> test;
	// test = ft::make_pair<std::string, int>("first", 1);


	ft::pair<std::string, int>	test("first", 1);

	// maptest.insert(ft::make_pair<std::string, int>("first", 1));

	maptest.insert(test);

	// maptest.find("first");
	// maptest.count("test");
	// maptest.lower_bound("salut");
	// maptest.upper_bound("salut");
	// maptest.equal_range("test");
	// maptest.insert(ft::pair<std::string, int>("second", 2));
	// maptest.insert(ft::pair<std::string, int>("third", 3));
	// maptest.insert(ft::pair<std::string, int>("third", 4));
	// maptest.insert(ft::pair<std::string, int>("third", 5));
	// Create a map iterator and point to beginning of map
	// ft::map<std::string, int>::iterator it = maptest.begin();
	// Iterate over the map using Iterator till end.
	
	// while (it != maptest.end())
	// {
	//	 // Accessing KEY from element pointed by it.
	//	 std::string word = it->first;
	//	 // Accessing VALUE from element pointed by it.
		
	// 	// int count = it->second;
	//	 // std::cout << word << " :: " << count << std::endl;

	//	 // Increment the Iterator to point to next entry
	//	 it++;
	// }
	return 0;
}



// #include "./INCS/pair.hpp"

// int	main()
// {
// 	ft::pair<int, std::string>	test(1, "sredtf");
// 	ft::pair<int, std::string>	test2(2, "sdfg");

// 	test = test2;
// 	test2 = ft::make_pair< int, std::string >(1, "first");
// 	std::cout << "test1 first = " << test.first << std::endl;
// 	std::cout << "test1 second = " << test.second << std::endl;


// 	std::cout << "test2 first = " << test2.first << std::endl;
// 	std::cout << "test2 second = " << test2.second << std::endl;

// 	return (0);
// }
