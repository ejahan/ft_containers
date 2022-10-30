/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:50:27 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/30 23:35:27 by ejahan           ###   ########.fr       */
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




// #include <iostream>
#include "./INCS/containers_test/srcs/base.hpp"

// #include <map>



#define _pair ft::pair

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	// std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T1, typename T2>
void	printReverse(ft::map<T1, T2> &mp)
{
	typename ft::map<T1, T2>::iterator it = mp.end(), ite = mp.begin();

	std::cout << "printReverse:" << std::endl;
	while (it != ite) {
		it--;
		std::cout << "-> " << printPair(it, false) << std::endl;
	}
	std::cout << "_______________________________________________" << std::endl;
}



#include <list>

#define T1 int
#define T2 std::string
typedef _pair<const T1, T2> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	// std::cout << "PARAM = " << param << std::endl;
	mp.erase(param);
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	// std::cout << "PARAM1 = " << param << std::endl;
	// std::cout << "PARAM2 = " << param2 << std::endl;
	mp.erase(param, param2);
	printSize(mp);
}

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	ft::map<T1, T2> mp(lst.begin(), lst.end());
	printSize(mp);

	ft_erase(mp, ++mp.begin());

	ft_erase(mp, mp.begin());
	ft_erase(mp, --mp.end());

	ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	// std::cout << "AVANT ->" << --(--(--mp.end())) << std::endl;
	std::cout << std::endl << "===========" << std::endl << std::endl;
	ft_erase(mp, --(--(--mp.end())), --mp.end());

	mp[10] = "Hello";
	mp[11] = "Hi there";
	printSize(mp);
	ft_erase(mp, --(--(--mp.end())), mp.end());

	mp[12] = "ONE";
	mp[13] = "TWO";
	mp[14] = "THREE";
	mp[15] = "FOUR";
	printSize(mp);
	ft_erase(mp, mp.begin(), mp.end());

	return (0);
}



// /*
// =====================================================================
// OP_SQRB
// =====================================================================
// */

// #define T1 char
// #define T2 foo<std::string>

// int		main(void)
// {
// 	ft::map<T1, T2> mp;

// 	mp['a'] = "an element";
// 	mp['b'] = "another element";
// 	mp['c'] = mp['b'];
// 	mp['b'] = "old element";

// 	printSize(mp);

// 	std::cout << "insert a new element via operator[]: " << mp['d'] << std::endl;

// 	printSize(mp);
// 	return (0);
// }

// /*
// =====================================================================
// OP_SQRB
// =====================================================================
// */
















// #include <list>

// #define T1 char
// #define T2 int
// typedef _pair<const T1, T2> T3;

// template <class T>
// void	is_empty(T const &mp)
// {
// 	std::cout << "is_empty: " << mp.empty() << std::endl;
// }

// int		main(void)
// {
// 	std::list<T3> lst;
// 	unsigned int lst_size = 7;
// 	for (unsigned int i = 0; i < lst_size; ++i)
// 		lst.push_back(T3('a' + i, lst_size - i));

// 	ft::map<T1, T2> mp(lst.begin(), lst.end()), mp2;
// 	ft::map<T1, T2>::iterator it;

// 	lst.clear();
// 	is_empty(mp);
// 	printSize(mp);

// 	is_empty(mp2);
// 	mp2 = mp;
// 	is_empty(mp2);

// 	it = mp.begin();
// 	for (unsigned long int i = 3; i < mp.size(); ++i)
// 		it++->second = i * 7;

// 	printSize(mp);
// 	printSize(mp2);

// 	mp2.clear();
// 	is_empty(mp2);
// 	printSize(mp2);
// 	return (0);
// }


/*
====================================================================================
je sais plus
====================================================================================
*/

// #include <list>

// #define T1 int
// #define T2 int
// typedef _pair<const T1, T2> T3;

// int		main(void)
// {
// 	std::list<T3> lst;
// 	unsigned int lst_size = 7;
// 	for (unsigned int i = 0; i < lst_size; ++i)
// 		lst.push_back(T3(lst_size - i, i));



// 	ft::map<T1, T2> mp(lst.begin(), lst.end());
// 	ft::map<T1, T2>::iterator it = mp.begin(), ite = mp.end();

// 	ft::map<T1, T2> mp_range(it, --(--ite));
// 	std::cout << "la"<< std::endl;
// 	for (int i = 0; it != ite; ++it)
// 	{
// 		std::cout << "for" << std::endl;
// 		it->second = ++i * 5;
// 	}
// 	std::cout << "re la"<< std::endl;

// 	it = mp.begin(); ite = --(--mp.end());
// 	ft::map<T1, T2> mp_copy(mp);
// 	for (int i = 0; it != ite; ++it)
// 		it->second = ++i * 7;

// 	std::cout << "\t-- PART ONE --" << std::endl;
// 	printSize(mp);
// 	printSize(mp_range);
// 	printSize(mp_copy);

// 	mp = mp_copy;
// 	mp_copy = mp_range;
// 	mp_range.clear();

// 	std::cout << "\t-- PART TWO --" << std::endl;
// 	printSize(mp);
// 	printSize(mp_range);
// 	printSize(mp_copy);
// 	return (0);
// }























// int main()
// {
// 	ft::map<std::string, int>	map;
// 	ft::map<std::string, int>::iterator	it;
// 	ft::map<std::string, int>::iterator	ite;

// 	map.insert(ft::make_pair<std::string, int>("ca", 1));
// 	map.insert(ft::make_pair<std::string, int>("marche", 2));
// 	// map.insert(ft::make_pair<std::string, int>("pas", 3));
// 	// map.insert(ft::make_pair<std::string, int>("!", 4));
// 	// map.insert(ft::make_pair<std::string, int>("aaaaaaaaaaaaaaaahhh", 5));
// 	map.print();
// 	map.erase("pas");
// 	std::cout << std::endl;
// 	map.print();
// 	std::cout << std::endl << std::endl;
// 	it = map.find("!");
// 	std::cout << "it -> " << *it << std::endl;
// 	it = map.begin();
// 	std::cout << "it begin -> " << *it << std::endl;
// 	// ++it;
// 	// std::cout << "it++ -> " << *it << std::endl;
// 	// ++it;
// 	// std::cout << "it++ -> " << *it << std::endl;
// 	// ++it;
// 	// std::cout << "it++ -> " << *it << std::endl;
// 	// ++it;
// 	// std::cout << "it++ -> " << *it << std::endl;
// 	// ite = map.end();
// 	// std::cout << "it end -> " << *it << std::endl;


// 	std::cout << "------> " << map["ca"] << std::endl;
// 	std::cout << "------> " << map["marche"] << std::endl;
// 	map["ca"] = 45;
// 	map.print();
// 	// ite = map.end();
// 	// while (it != ite)
// 	// {
// 	// 	std::cout << "it -> " << *it << std::endl;
// 	// 	++it;
// 	// }
// 	// if (it == ite)
// 	// 	std::cout << "it == ite" << std::endl;

// 	return (0);
// }







// #include <iostream>
// #include <map>

// int	main()
// {
// 	std::map<int, std::string>	map;

// 	map.insert(std::make_pair<int, std::string>(2, "asd"));
// 	map.insert(std::make_pair<int, std::string>(5, "qwe"));
// 	map.insert(std::make_pair<int, std::string>(6, "qwe"));
// 	map.insert(std::make_pair<int, std::string>(78, "qwe"));
// 	map.insert(std::make_pair<int, std::string>(465, "qwe"));
// 	std::cout << "size = " << map.size() << std::endl;

// 	return (0);
// }
