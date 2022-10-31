/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:50:27 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/31 03:11:13 by ejahan           ###   ########.fr       */
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




// // #include <iostream>
#include "./INCS/containers_test/srcs/base.hpp"

// // #include <map>

#include "./INCS/set.hpp"


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
// 	// std::cout << "max_size: " << mp.max_size() << std::endl;
// 	if (print_content)
// 	{
// 		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
// 		std::cout << std::endl << "Content is:" << std::endl;
// 		for (; it != ite; ++it)
// 			std::cout << "- " << printPair(it, false) << std::endl;
// 	}
// 	std::cout << "###############################################" << std::endl;
// }

// template <typename T1, typename T2>
// void	printReverse(ft::map<T1, T2> &mp)
// {
// 	typename ft::map<T1, T2>::iterator it = mp.end(), ite = mp.begin();

// 	std::cout << "printReverse:" << std::endl;
// 	while (it != ite) {
// 		it--;
// 		std::cout << "-> " << printPair(it, false) << std::endl;
// 	}
// 	std::cout << "_______________________________________________" << std::endl;
// }





#define _pair ft::pair

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "value: " << *iterator;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_SET>
void	printSize(T_SET const &st, bool print_content = 1)
{
	std::cout << "size: " << st.size() << std::endl;
	std::cout << "max_size: " << st.max_size() << std::endl;
	if (print_content)
	{
		typename T_SET::const_iterator it = st.begin(), ite = st.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename T1>
void	printReverse(ft::set<T1> &st)
{
	typename ft::set<T1>::iterator it = st.end(), ite = st.begin();

	std::cout << "printReverse:" << std::endl;
	while (it-- != ite)
		std::cout << "-> " << printPair(it, false) << std::endl;
	std::cout << "_______________________________________________" << std::endl;
}























#include <list>

#define T1 foo<int>

int		main(void)
{
	std::list<T1> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(2.5 + i);

	ft::set<T1> st(lst.begin(), lst.end());
	ft::set<T1>::iterator it(st.begin());
	ft::set<T1>::const_iterator ite(st.begin());
	printSize(st);

	printPair(++ite);
	printPair(ite++);
	printPair(ite++);
	printPair(++ite);

	it->m();
	ite->m();

	printPair(++it);
	printPair(it++);
	printPair(it++);
	printPair(++it);

	printPair(--ite);
	printPair(ite--);
	printPair(--ite);
	printPair(ite--);

	(*it).m();
	(*ite).m();

	printPair(--it);
	printPair(it--);
	printPair(it--);
	printPair(--it);

	return (0);
}













// #define T1 std::string
// typedef ft::set<T1>::iterator iterator;

// static int iter = 0;

// template <typename SET, typename U>
// void	ft_insert(SET &st, U param)
// {
// 	_pair<iterator, bool> tmp;

// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	tmp = st.insert(param);
// 	std::cout << "insert return: " << printPair(tmp.first);
// 	std::cout << "Created new node: " << tmp.second << std::endl;
// 	printSize(st);
// }

// template <typename SET, typename U, typename V>
// void	ft_insert(SET &st, U param, V param2)
// {
// 	iterator tst;

// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	tst = st.insert(param, param2);
// 	std::cout << "insert return: " << printPair(tst);
// 	printSize(st);
// }

// int		main(void)
// {
// 	ft::set<T1> st, st2;

// 	ft_insert(st, "lol");
// 	ft_insert(st, "mdr");

// 	ft_insert(st, "mdr");
// 	ft_insert(st, "funny");

// 	ft_insert(st, "bunny");
// 	ft_insert(st, "fizz");
// 	ft_insert(st, "buzz");

// 	ft_insert(st, st.begin(), "fuzzy");

// 	ft_insert(st2, st2.begin(), "beauty");
// 	ft_insert(st2, st2.end(), "Hello");
// 	ft_insert(st2, st2.end(), "World");

// 	return (0);
// }
























// #define T1 int

// ft::set<T1> st;
// ft::set<T1>::iterator it = st.end();

// void	ft_find(T1 const &k)
// {
// 	ft::set<T1>::iterator ret = st.find(k);

// 	if (ret != it)
// 		printPair(ret);
// 	else
// 		std::cout << "set::find(" << k << ") returned end()" << std::endl;
// }

// void	ft_count(T1 const &k)
// {
// 	std::cout << "set::count(" << k << ")\treturned [" << st.count(k) << "]" << std::endl;
// }

// int		main(void)
// {
// 	st.insert(42);
// 	st.insert(25);
// 	st.insert(80);
// 	st.insert(12);
// 	st.insert(27);
// 	st.insert(90);
// 	printSize(st);

// 	std::cout << "\t-- FIND --" << std::endl;
// 	ft_find(12);
// 	ft_find(3);
// 	ft_find(35);
// 	ft_find(90);
// 	ft_find(100);

// 	std::cout << "\t-- COUNT --" << std::endl;
// 	ft_count(-3);
// 	ft_count(12);
// 	ft_count(3);
// 	ft_count(35);
// 	ft_count(90);
// 	ft_count(100);

// 	st.erase(st.find(27));

// 	printSize(st);

// 	ft::set<T1> const c_set(st.begin(), st.end());
// 	std::cout << "const set.find(" << 42 << ")->second: [" << *(c_set.find(42)) << "]" << std::endl;
// 	std::cout << "const set.count(" << 80 << "): [" << c_set.count(80) << "]" << std::endl;
// 	return (0);
// }


































// #include <list>

// #define T1 int
// typedef ft::set<T1>::iterator ft_iterator;
// typedef ft::set<T1>::const_iterator ft_const_iterator;

// static int iter = 0;

// template <typename SET>
// void	ft_bound(SET &st, const T1 &param)
// {
// 	ft_iterator ite = st.end(), it[2];
// 	_pair<ft_iterator, ft_iterator> ft_range;

// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	std::cout << "with key [" << param << "]:" << std::endl;
// 	it[0] = st.lower_bound(param); it[1] = st.upper_bound(param);
// 	ft_range = st.equal_range(param);
// 	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
// 	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
// 	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
// }

// template <typename SET>
// void	ft_const_bound(const SET &st, const T1 &param)
// {
// 	ft_const_iterator ite = st.end(), it[2];
// 	_pair<ft_const_iterator, ft_const_iterator> ft_range;

// 	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
// 	std::cout << "with key [" << param << "]:" << std::endl;
// 	it[0] = st.lower_bound(param); it[1] = st.upper_bound(param);
// 	ft_range = st.equal_range(param);
// 	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
// 	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
// 	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
// }

// int		main(void)
// {
// 	std::list<T1> lst;
// 	unsigned int lst_size = 10;
// 	for (unsigned int i = 0; i < lst_size; ++i)
// 		lst.push_back((i + 1) * 3);
// 	ft::set<T1> st(lst.begin(), lst.end());
// 	printSize(st);

// 	ft_const_bound(st, -10);
// 	ft_const_bound(st, 1);
// 	ft_const_bound(st, 5);
// 	ft_const_bound(st, 10);
// 	ft_const_bound(st, 50);

// 	printSize(st);

// 	ft_bound(st, 5);
// 	ft_bound(st, 7);

// 	printSize(st);
// 	return (0);
// }



























// #include <list>

// #define T1 int
// #define T2 std::string
// typedef _pair<const T1, T2> T3;

// static int iter = 0;

// template <typename MAP, typename U>
// void	ft_erase(MAP &mp, U param)
// {
// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	// std::cout << "PARAM = " << param << std::endl;
// 	mp.erase(param);
// 	printSize(mp);
// }

// template <typename MAP, typename U, typename V>
// void	ft_erase(MAP &mp, U param, V param2)
// {
// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	// std::cout << "PARAM1 = " << param << std::endl;
// 	// std::cout << "PARAM2 = " << param2 << std::endl;
// 	mp.erase(param, param2);
// 	printSize(mp);
// }

// int		main(void)
// {
// 	std::list<T3> lst;
// 	unsigned int lst_size = 10;
// 	for (unsigned int i = 0; i < lst_size; ++i)
// 		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
// 	ft::map<T1, T2> mp(lst.begin(), lst.end());
// 	printSize(mp);

// 	ft_erase(mp, ++mp.begin());

// 	ft_erase(mp, mp.begin());
// 	ft_erase(mp, --mp.end());

// 	ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
// 	// std::cout << "AVANT ->" << --(--(--mp.end())) << std::endl;
// 	std::cout << std::endl << "===========" << std::endl << std::endl;
// 	ft_erase(mp, --(--(--mp.end())), --mp.end());

// 	mp[10] = "Hello";
// 	mp[11] = "Hi there";
// 	printSize(mp);
// 	ft_erase(mp, --(--(--mp.end())), mp.end());

// 	mp[12] = "ONE";
// 	mp[13] = "TWO";
// 	mp[14] = "THREE";
// 	mp[15] = "FOUR";
// 	printSize(mp);
// 	ft_erase(mp, mp.begin(), mp.end());

// 	return (0);
// }



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





// 	// map.insert(ft::make_pair<std::string, int>("ca", 1));
// 	// map.insert(ft::make_pair<std::string, int>("marche", 2));
// 	// map.insert(ft::make_pair<std::string, int>("pas", 3));
// 	// map.insert(ft::make_pair<std::string, int>("!", 4));
// 	// map.insert(ft::make_pair<std::string, int>("aaaaaaaaaaaaaaaahhh", 5));
// 	map.print();
// 	map.erase("pas");
// 	std::cout << std::endl;
// 	map.print();
// 	std::cout << std::endl << std::endl;
// 	it = map.find("!");
// 	// std::cout << "it -> " << *it << std::endl;
// 	it = map.begin();
// 	// std::cout << "it begin -> " << *it << std::endl;
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


// 	// std::cout << "------> " << map["ca"] << std::endl;
// 	// std::cout << "------> " << map["marche"] << std::endl;
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
// 	std::map<std::string, int>	map;
// 	std::map<std::string, int>	map2;

// 	map.insert(std::make_pair<std::string, int>("satan", 666));
// 	map.insert(std::make_pair<std::string, int>("lol", 8));
// 	map.insert(std::make_pair<std::string, int>("uch", 442));
// 	map.insert(std::make_pair<std::string, int>("xD", 123));
// 	// map.insert(std::make_pair<int, std::string>(5, "qwe"));
// 	// map.insert(std::make_pair<int, std::string>(6, "qwe"));
// 	// map.insert(std::make_pair<int, std::string>(78, "qwe"));
// 	// map.insert(std::make_pair<int, std::string>(465, "qwe"));
// 	// std::cout << "size = " << map.size() << std::endl;
// 	if (map > map2)
// 		std::cout << true << std::endl;

// 	return (0);
// }
