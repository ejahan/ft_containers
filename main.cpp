/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:50:27 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/26 23:10:37 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./INCS/vector.hpp"
// #include "./INCS/stack.hpp"
// #include "./INCS/rbt.hpp"
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



// int main()
// {
// 	ft::map<std::string, int>	maptest;
// 	// ft::map<std::string, int>	map_copy = maptest;


// 	std::cout << "size = " << maptest.size() << std::endl;
// 	// Insert Element in map

// 	// ft::pair<std::string, int> test;
// 	// test = ft::make_pair<std::string, int>("first", 1);


// 	ft::pair<std::string, int>	test("first", 1);

// 	maptest.insert(ft::make_pair<std::string, int>("second", 2));
// 	maptest.insert(ft::make_pair<std::string, int>("aaa", 3));
// 	maptest.insert(ft::make_pair<std::string, int>("b", 3));
// 	maptest.insert(ft::make_pair<std::string, int>("c", 3));
// 	maptest.insert(ft::make_pair<std::string, int>("d", 3));
// 	maptest.insert(ft::make_pair<std::string, int>("e", 3));
// 	maptest.insert(ft::make_pair<std::string, int>("f", 3));
// 	maptest.insert(ft::make_pair<std::string, int>("g", 3));

// 	maptest.insert(test);

// 	// maptest.find("first");
// 	// maptest.count("test");
// 	// maptest.lower_bound("salut");
// 	// maptest.upper_bound("salut");
// 	// maptest.equal_range("test");
// 	// maptest.insert(ft::pair<std::string, int>("second", 2));
// 	// maptest.insert(ft::pair<std::string, int>("third", 3));
// 	// maptest.insert(ft::pair<std::string, int>("third", 4));
// 	// maptest.insert(ft::pair<std::string, int>("third", 5));
// 	// Create a map iterator and point to beginning of map
// 	// ft::map<std::string, int>::iterator it = maptest.begin();
// 	// Iterate over the map using Iterator till end.
	
// 	// while (it != maptest.end())
// 	// {
// 	//	 // Accessing KEY from element pointed by it.
// 	//	 std::string word = it->first;
// 	//	 // Accessing VALUE from element pointed by it.
		
// 	// 	// int count = it->second;
// 	//	 // std::cout << word << " :: " << count << std::endl;

// 	//	 // Increment the Iterator to point to next entry
// 	//	 it++;
// 	// }
// 	return 0;
// }



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



















// /*
// ========================================================================================
// INSERT
// ========================================================================================
// */


// #define _pair ft::pair

// template <typename T>
// std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
// {
// 	o << "key: " << iterator->first << " | value: " << iterator->second;
// 	if (nl)
// 		o << std::endl;
// 	return ("");
// }

// template <typename T_MAP>
// void	printSize(T_MAP const &mp, bool print_content = 1)
// {
// 	std::cout << "size: " << mp.size() << std::endl;
// 	std::cout << "max_size: " << mp.max_size() << std::endl;
// 	if (print_content)
// 	{
// 		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
// 		++it;
// 		++it;
// 		++it;
// 		++it;
// 		++it;
// 		++it;
// 		++it;
// 		std::cout << "it++ -> " << *it << std::endl;
// 		std::cout << "ite++ -> " << *ite << std::endl;
// 		std::cout << std::endl << "Content is:" << std::endl;
// 		// for (; it != ite; ++it)
// 		// {
// 		// 	std::cout << "- " << printPair(it, false) << std::endl;
// 		// }
// 	}
// 	std::cout << "###############################################" << std::endl;
// }

// // template <typename T1, typename T2>
// // void	printReverse(ft::map<T1, T2> &mp)
// // {
// // 	typename ft::map<T1, T2>::iterator it = mp.end(), ite = mp.begin();

// // 	std::cout << "printReverse:" << std::endl;
// // 	while (it != ite) {
// // 		it--;
// // 		std::cout << "-> " << printPair(it, false) << std::endl;
// // 	}
// // 	std::cout << "_______________________________________________" << std::endl;
// // }


// #define T1 int
// #define T2 std::string
// typedef ft::map<T1, T2>::value_type T3;
// typedef ft::map<T1, T2>::iterator iterator;

// static int iter = 0;

// template <typename MAP, typename U>
// void	ft_insert(MAP &mp, U param)
// {
// 	_pair<iterator, bool> tmp;

// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	tmp = mp.insert(param);
// 	std::cout << "insert return: " << printPair(tmp.first);
// 	std::cout << "Created new node: " << tmp.second << std::endl;
// 	printSize(mp);
// }

// template <typename MAP, typename U, typename V>
// void	ft_insert(MAP &mp, U param, V param2)
// {
// 	iterator tmp;

// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	tmp = mp.insert(param, param2);
// 	std::cout << "insert return: " << printPair(tmp);
// 	printSize(mp);
// }

// int		main(void)
// {
// 	ft::map<T1, T2> mp, mp2;

// 	ft_insert(mp, T3(42, "lol"));
// 	ft_insert(mp, T3(42, "mdr"));

// 	ft_insert(mp, T3(50, "mdr"));
// 	ft_insert(mp, T3(35, "funny"));

// 	ft_insert(mp, T3(45, "bunny"));
// 	ft_insert(mp, T3(21, "fizz"));
// 	ft_insert(mp, T3(38, "buzz"));

// 	ft_insert(mp, mp.begin(), T3(55, "fuzzy"));

// 	ft_insert(mp2, mp2.begin(), T3(1337, "beauty"));
// 	ft_insert(mp2, mp2.end(), T3(1000, "Hello"));
// 	ft_insert(mp2, mp2.end(), T3(1500, "World"));

// 	return (0);
// }




































int main()
{
	ft::map<std::string, int>	map;
	ft::map<std::string, int>::iterator	it;
	ft::map<std::string, int>::iterator	ite;

	map.insert(ft::make_pair<std::string, int>("ca", 1));
	// map.insert(ft::make_pair<std::string, int>("marche", 2));
	// map.insert(ft::make_pair<std::string, int>("pas", 3));
	// map.insert(ft::make_pair<std::string, int>("!", 4));
	// map.insert(ft::make_pair<std::string, int>("aaaaaaaaaaaaaaaahhh", 5));
	map.print();
	map.erase("pas");
	std::cout << std::endl;
	map.print();
	std::cout << std::endl << std::endl;
	it = map.find("!");
	std::cout << "it -> " << *it << std::endl;
	it = map.begin();
	std::cout << "it begin -> " << *it << std::endl;
	// ++it;
	// std::cout << "it++ -> " << *it << std::endl;
	// ++it;
	// std::cout << "it++ -> " << *it << std::endl;
	// ++it;
	// std::cout << "it++ -> " << *it << std::endl;
	// ++it;
	// std::cout << "it++ -> " << *it << std::endl;
	// ite = map.end();
	// std::cout << "it end -> " << *it << std::endl;

	ite = map.end();
	while (it != ite)
	{
		std::cout << "it -> " << *it << std::endl;
		++it;
	}
	// if (it == ite)
	// 	std::cout << "it == ite" << std::endl;

	return (0);
}
