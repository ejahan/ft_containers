/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:50:27 by ejahan            #+#    #+#             */
/*   Updated: 2022/11/01 05:36:53 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// /*
// ================================================================================
// TEST SUJET
// ================================================================================
// */

// // #include <iostream>
// // #include <string>
// // #include <deque>
// // #if 1 //CREATE A REAL STL EXAMPLE
// // 	#include <map>
// // 	#include <stack>
// // 	#include <vector>
// // 	namespace ft = std;
// // #else
// // 	#include "./INCS/map.hpp"
// // 	#include "./INCS/stack.hpp"
// // 	#include "./INCS/vector.hpp"
// // #endif

// // #include <stdlib.h>

// // #define MAX_RAM 4294967296
// // #define BUFFER_SIZE 4096
// // struct Buffer
// // {
// // 	int idx;
// // 	char buff[BUFFER_SIZE];
// // };


// // #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// // template<typename T>
// // class MutantStack : public ft::stack<T>
// // {
// // public:
// // 	MutantStack() {}
// // 	MutantStack(const MutantStack<T>& src) { *this = src; }
// // 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// // 	{
// // 		this->c = rhs.c;
// // 		return *this;
// // 	}
// // 	~MutantStack() {}

// // 	typedef typename ft::stack<T>::container_type::iterator iterator;

// // 	iterator begin() { return this->c.begin(); }
// // 	iterator end() { return this->c.end(); }
// // };

// // int main(int argc, char** argv) {
// // 	if (argc != 2)
// // 	{
// // 		std::cerr << "Usage: ./test seed" << std::endl;
// // 		std::cerr << "Provide a seed please" << std::endl;
// // 		std::cerr << "Count value:" << COUNT << std::endl;
// // 		return 1;
// // 	}
// // 	const int seed = atoi(argv[1]);
// // 	srand(seed);

// // 	ft::vector<std::string> vector_str;
// // 	ft::vector<int> vector_int;
// // 	ft::stack<int> stack_int;
// // 	ft::vector<Buffer> vector_buffer;
// // 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// // 	ft::map<int, int> map_int;

// // 	for (int i = 0; i < COUNT; i++)
// // 	{
// // 		vector_buffer.push_back(Buffer());
// // 	}

// // 	for (int i = 0; i < COUNT; i++)
// // 	{
// // 		const int idx = rand() % COUNT;
// // 		vector_buffer[idx].idx = 5;
// // 	}
// // 	ft::vector<Buffer>().swap(vector_buffer);

// // 	try
// // 	{
// // 		for (int i = 0; i < COUNT; i++)
// // 		{
// // 			const int idx = rand() % COUNT;
// // 			vector_buffer.at(idx);
// // 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// // 		}
// // 	}
// // 	catch(const std::exception& e)
// // 	{
// // 		//NORMAL ! :P
// // 	}
	
// // 	for (int i = 0; i < COUNT; ++i)
// // 	{
// // 		map_int.insert(ft::make_pair(rand(), rand()));
// // 	}

// // 	int sum = 0;
// // 	for (int i = 0; i < 10000; i++)
// // 	{
// // 		int access = rand();
// // 		sum += map_int[access];
// // 	}
// // 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// // 	{
// // 		ft::map<int, int> copy = map_int;
// // 	}
// // 	MutantStack<char> iterable_stack;
// // 	for (char letter = 'a'; letter <= 'z'; letter++)
// // 		iterable_stack.push(letter);
// // 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// // 	{
// // 		std::cout << *it;
// // 	}
// // 	std::cout << std::endl;
// // 	return (0);
// // }




















// /*
// ===================================================================================
// ===================================================================================
// ===================================================================================
// 									   TESTS
// ===================================================================================
// ===================================================================================
// ===================================================================================
// */
// #include <sys/time.h>
// #include <iostream>
// # define NOR "\033[m"
// # define GREY "\033[1;30m"
// # define BLUE "\033[1;34m"
// # define WHITE "\033[1;37m"
// # define CYAN "\033[1;36m"
// # define PURPLE "\033[1;35m"
// # define RED "\033[1;31m"
// # define GREEN "\033[1;32m"
// # define YELL "\033[1;33m"

// # define H_NOR "\033[m"
// # define H_GREY "\033[1;40m"
// # define H_BLUE "\033[1;44m"
// # define H_WHITE "\033[1;47m"
// # define H_CYAN "\033[1;46m"
// # define H_PURPLE "\033[1;45m"
// # define H_RED "\033[1;41m"
// # define H_GREEN "\033[1;42m"
// # define H_YELL "\033[1;43m"



// /*
// ================================================================================
// TESTS VECTOR
// ================================================================================
// */

// #include "./INCS/vector.hpp"

// void	print_vector(ft::vector<int> vect, std::string str)
// {
// 	ft::vector<int>::iterator	it = vect.begin();
// 	ft::vector<int>::iterator	ite = vect.end();

// 	std::cout << std::endl << WHITE << str << NOR << std::endl;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		it++;
// 	}
// }

// void	vector_test()
// {
// 	std::cout << "=====================================================================" << std::endl << "				VECTOR" <<std::endl << "=====================================================================" << std::endl << std::endl << std::endl;

// 	ft::vector<int>	vector1;
// 	if (vector1.empty() == true)
// 		std::cout << GREEN << "vector1 is empty" << NOR << std::endl << std::endl;
// 	for (int n(5); n > 0; n--)
// 	{
// 		std::cout << GREY << "*push_back*" << NOR << std::endl;
// 		vector1.push_back(n * 4);
// 	}
// 	print_vector(vector1, "vector1 :");
// 	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
// 	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;
// 	std::cout << PURPLE << "max_size " << NOR << "vector1 = " << vector1.max_size() << std::endl;

// 	if (vector1.empty() != true)
// 		std::cout << std::endl << GREEN << "vector1 is not empty" << NOR << std::endl << std::endl;

// 	std::cout << GREY << "*pop_back*" << NOR << std::endl;
// 	vector1.pop_back();
// 	std::cout << GREY << "*pop_back*" << NOR << std::endl;
// 	vector1.pop_back();

// 	print_vector(vector1, "vector1 :");
// 	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
// 	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;

// 	std::cout << std::endl << std::endl << std::endl << BLUE << "===============" << std::endl;
// 	std::cout << "*assign(7, 55)*" << std::endl;
// 	std::cout << "===============" << std::endl << NOR;
// 	vector1.assign(7, 55);
// 	print_vector(vector1, "vector1 :");
// 	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
// 	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;

// 	std::cout << std::endl << std::endl << std::endl << BLUE << "===============" << std::endl;
// 	std::cout << "*assign(5, 12)*" << std::endl;
// 	std::cout << "===============" << std::endl << NOR;
// 	vector1.assign(5, 12);
// 	print_vector(vector1, "vector1 :");
// 	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
// 	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;

// 	std::cout << std::endl << std::endl << std::endl << BLUE << "===============" << std::endl;
// 	std::cout << "*reserve(14)*" << std::endl;
// 	std::cout << "===============" << std::endl << NOR;
// 	vector1.reserve(14);
// 	print_vector(vector1, "vector1 :");
// 	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
// 	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;

// 	std::cout << std::endl << std::endl << std::endl << BLUE << "===============" << std::endl;
// 	std::cout << "*resize(10)*" << std::endl;
// 	std::cout << "===============" << std::endl << NOR;
// 	vector1.resize(10);
// 	print_vector(vector1, "vector1 :");
// 	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
// 	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;


// 	std::cout << std::endl << std::endl << std::endl << BLUE << "===============" << std::endl;
// 	std::cout << "*resize(2)*" << std::endl;
// 	std::cout << "===============" << std::endl << NOR;
// 	vector1.resize(2);
// 	print_vector(vector1, "vector1 :");
// 	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
// 	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;

// 	std::cout << std::endl << std::endl << std::endl << BLUE << "===============" << std::endl;
// 	std::cout << "*insert*" << std::endl;
// 	std::cout << "===============" << std::endl << NOR;
// 	vector1.insert(vector1.begin(), 10);
// 	print_vector(vector1, "vector1 :");
// 	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
// 	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;

// 	std::cout << std::endl << GREY << "*insert*" << std::endl << NOR;
// 	vector1.insert(vector1.begin() + 1, 3, 78);
// 	std::cout << GREY << "*insert*" << std::endl << NOR;
// 	vector1.insert(vector1.begin() + 3, 452);
// 	std::cout << GREY << "*insert*" << std::endl << NOR;
// 	vector1.insert(vector1.begin() + 1, 45);
// 	std::cout << GREY << "*insert*" << std::endl << NOR;
// 	vector1.insert(vector1.begin(), 7);
// 	std::cout << GREY << "*insert*" << std::endl << NOR;
// 	vector1.insert(vector1.begin() + 2, 7458);

// 	print_vector(vector1, "vector1 :");
// 	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
// 	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;

// 	std::cout << std::endl << GREEN << "front -> " << vector1.front() << std::endl << NOR;
// 	std::cout << GREEN << "back -> " << vector1.back() << std::endl << NOR;

// 	std::cout << std::endl << CYAN << "========================" << std::endl << NOR;
// 	std::cout << CYAN << "CONSTRUCT vector_range :" << std::endl << NOR;
// 	ft::vector<int>	vector_range(vector1.begin() + 1, vector1.begin() + 8);
// 	print_vector(vector_range, "vector_range :");

// 	std::cout << std::endl << CYAN << "===================" << std::endl << NOR;
// 	std::cout << CYAN << "CONSTRUCT vector2 :" << std::endl << NOR;
// 	ft::vector<int>	vector2(6, 123);
// 	print_vector(vector2, "vector2 :");

// 	std::cout << std::endl << std::endl << BLUE << "===================" << std::endl;
// 	std::cout << "*vector2 = vector1*" << std::endl;
// 	std::cout << "===================" << std::endl << NOR;
// 	vector2 = vector1;
// 	ft::vector<int>::iterator	it = vector2.begin();
// 	ft::vector<int>::iterator	ite = vector2.end();
// 	int	i = 0;

// 	std::cout << std::endl << WHITE << "vector2	:		vector1 :" << NOR << std::endl;
// 	while (it != ite)
// 	{
// 		std::cout << *it << "			" << vector1[i] << std::endl;
// 		it++;
// 		i++;
// 	}

// 	std::cout << std::endl << std::endl << BLUE << "===================" << std::endl;
// 	std::cout << "*SWAP*" << std::endl;
// 	std::cout << "===================" << std::endl << NOR;
// 	vector2.swap(vector_range);
// 	print_vector(vector2, "vector2 :");
// 	print_vector(vector_range, "vector_range :");

// 	std::cout << std::endl << std::endl << BLUE << "===================" << std::endl;
// 	std::cout << "*ERASE*" << std::endl;
// 	std::cout << "===================" << std::endl << NOR;
// 	vector2.erase(vector2.begin() + 2);
// 	print_vector(vector2, "vector2 :");

// 	std::cout << std::endl << std::endl << BLUE << "===================" << std::endl;
// 	std::cout << "*ERASE RANGE*" << std::endl;
// 	std::cout << "===================" << std::endl << NOR;
// 	vector2.erase(vector2.begin(), vector2.begin() + 3);
// 	print_vector(vector2, "vector2 :");

// 	std::cout << std::endl << std::endl << BLUE << "===================" << std::endl;
// 	std::cout << "*CLEAR*" << std::endl;
// 	std::cout << "===================" << std::endl << NOR;
// 	vector2.clear();
// 	std::cout << std::endl << PURPLE << "size " << NOR << "= " << vector2.size() << std::endl;

// 	std::cout << std::endl << std::endl;

// }







// /*
// ================================================================================
// TESTS STACK
// ================================================================================
// */

// #include "./INCS/stack.hpp"

// void	stack_test()
// {
// 	std::cout << "=====================================================================" << std::endl << "				STACK" <<std::endl << "=====================================================================" << std::endl << std::endl << std::endl;

// }








// /*
// ================================================================================
// TESTS MAP
// ================================================================================
// */

// #include "./INCS/map.hpp"

// void	map_test()
// {
// 	std::cout << "=====================================================================" << std::endl << "				 MAP" <<std::endl << "=====================================================================" << std::endl << std::endl << std::endl;

// }











// /*
// ================================================================================
// MAIN TESTS
// ================================================================================
// */

// int	main()
// {
// 	long long int	i;
// 	long long int	j;
// 	struct timeval	time;
// 	struct timeval	time2;
// 	gettimeofday(&time, NULL);
// 	i = (time.tv_sec * 1000 + time.tv_usec / 1000);

// 	vector_test();
// 	// stack_test();
// 	// map_test();

// 	gettimeofday(&time2, NULL);
// 	j = (time2.tv_sec * 1000 + time2.tv_usec / 1000);
// 	std::cout << i << std::endl;
// 	std::cout << j << std::endl;
// 	std::cout << "TIME = " << j - i << std::endl;

// 	return (0);
// }














// #include "./INCS/containers_test/srcs/base.hpp"
// #include <iostream>
// #include <list>
// #include "./INCS/map.hpp"


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





// #define T1 int
// #define T2 foo<int>
// typedef ft::map<T1, T2>::value_type T3;
// typedef ft::map<T1, T2>::iterator ft_iterator;
// typedef ft::map<T1, T2>::const_iterator ft_const_iterator;

// static int iter = 0;

// template <typename MAP>
// void	ft_bound(MAP &mp, const T1 &param)
// {
// 	ft_iterator ite = mp.end(), it[2];
// 	_pair<ft_iterator, ft_iterator> ft_range;

// 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// 	std::cout << "with key [" << param << "]:" << std::endl;
// 	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
// 	ft_range = mp.equal_range(param);
// 	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
// 	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
// 	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
// }

// template <typename MAP>
// void	ft_const_bound(const MAP &mp, const T1 &param)
// {
// 	ft_const_iterator ite = mp.end(), it[2];
// 	_pair<ft_const_iterator, ft_const_iterator> ft_range;

// 	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
// 	std::cout << "with key [" << param << "]:" << std::endl;
// 	it[0] = mp.lower_bound(param); it[1] = mp.upper_bound(param);
// 	ft_range = mp.equal_range(param);
// 	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
// 	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
// 	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
// }

// int		main(void)
// {
// 	std::list<T3> lst;
// 	unsigned int lst_size = 10;
// 	for (unsigned int i = 0; i < lst_size; ++i)
// 		lst.push_back(T3(i + 1, (i + 1) * 3));
// 	ft::map<T1, T2> mp(lst.begin(), lst.end());
// 	printSize(mp);

// 	ft_const_bound(mp, -10);
// 	ft_const_bound(mp, 1);
// 	ft_const_bound(mp, 5);
// 	ft_const_bound(mp, 10);
// 	ft_const_bound(mp, 50);

// 	printSize(mp);

// 	mp.lower_bound(3)->second = 404;
// 	mp.upper_bound(7)->second = 842;
// 	ft_bound(mp, 5);
// 	ft_bound(mp, 7);

// 	printSize(mp);
// 	return (0);
// }












































// /*
// ===================================================================================
// ===================================================================================
// ===================================================================================
// TESTEUR 
// ===================================================================================
// ===================================================================================
// ===================================================================================
// */

#include <iostream>
#include "./INCS/containers_test/srcs/base.hpp"
#include "./INCS/set.hpp"

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


// // #include <list>

// // #define T1 int
// // typedef ft::set<T1>::iterator ft_iterator;
// // typedef ft::set<T1>::const_iterator ft_const_iterator;

// // static int iter = 0;

// // template <typename SET>
// // void	ft_bound(SET &st, const T1 &param)
// // {
// // 	ft_iterator ite = st.end(), it[2];
// // 	_pair<ft_iterator, ft_iterator> ft_range;

// // 	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
// // 	std::cout << "with key [" << param << "]:" << std::endl;
// // 	it[0] = st.lower_bound(param); it[1] = st.upper_bound(param);
// // 	ft_range = st.equal_range(param);
// // 	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
// // 	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
// // 	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
// // }

// // template <typename SET>
// // void	ft_const_bound(const SET &st, const T1 &param)
// // {
// // 	ft_const_iterator ite = st.end(), it[2];
// // 	_pair<ft_const_iterator, ft_const_iterator> ft_range;

// // 	std::cout << "\t-- [" << iter++ << "] (const) --" << std::endl;
// // 	std::cout << "with key [" << param << "]:" << std::endl;
// // 	it[0] = st.lower_bound(param); it[1] = st.upper_bound(param);
// // 	ft_range = st.equal_range(param);
// // 	std::cout << "lower_bound: " << (it[0] == ite ? "end()" : printPair(it[0], false)) << std::endl;
// // 	std::cout << "upper_bound: " << (it[1] == ite ? "end()" : printPair(it[1], false)) << std::endl;
// // 	std::cout << "equal_range: " << (ft_range.first == it[0] && ft_range.second == it[1]) << std::endl;
// // }

// // int		main(void)
// // {
// // 	std::list<T1> lst;
// // 	unsigned int lst_size = 10;
// // 	for (unsigned int i = 0; i < lst_size; ++i)
// // 		lst.push_back((i + 1) * 3);
// // 	ft::set<T1> st(lst.begin(), lst.end());
// // 	printSize(st);

// // 	ft_const_bound(st, -10);
// // 	ft_const_bound(st, 1);
// // 	ft_const_bound(st, 5);
// // 	ft_const_bound(st, 10);
// // 	ft_const_bound(st, 50);

// // 	printSize(st);

// // 	ft_bound(st, 5);
// // 	ft_bound(st, 7);

// // 	printSize(st);
// // 	return (0);
// // }




// // #define T1 int

// // int		main(void)
// // {
// // 	ft::set<T1> const st;
// // 	ft::set<T1>::iterator it = st.begin(); // <-- no error, actually ! set allows for const_iterator => iterator conversion

// // 	(void)it;
// // 	return (0);
// // }



// // #define T1 int

// // int		main(void)
// // {
// // 	ft::set<T1> st;

// // 	ft::set<T1>::const_iterator ite = st.begin();
// // 	*ite = 42; // < -- error
// // 	return (0);
// // }




// #include <list>

// #define T1 int

// int		main(void)
// {
// 	std::list<T1> lst;
// 	unsigned int lst_size = 5;
// 	for (unsigned int i = 0; i < lst_size; ++i)
// 		lst.push_back((i + 1) * 7);

// 	ft::set<T1> st(lst.begin(), lst.end());
// 	ft::set<T1>::iterator it_ = st.begin();
// 	ft::set<T1>::reverse_iterator it(it_), ite;
// 	printSize(st);

// 	std::cout << (it_ == it.base()) << std::endl;
// 	std::cout << (it_ == dec(it, 3).base()) << std::endl;

// 	printPair(it.base());
// 	printPair(inc(it.base(), 1));

// 	std::cout << "TEST OFFSET" << std::endl;
// 	--it;
// 	printPair(it);
// 	printPair(it.base());

// 	it = st.rbegin(); ite = st.rend();
// 	while (it != ite)
// 		std::cout << "[rev] " << printPair(it++, false) << std::endl;
// 	// printReverse(st); <-- this causes a strange bug on the macos std lib ?

// 	return (0);
// }

// #include <list>

// #define T1 foo<int>

// int		main(void)
// {
// 	std::list<T1> lst;
// 	unsigned int lst_size = 5;
// 	for (unsigned int i = 0; i < lst_size; ++i)
// 		lst.push_back(2.5 + i);

// 	ft::set<T1> st(lst.begin(), lst.end());
// 	ft::set<T1>::iterator it(st.begin());
// 	ft::set<T1>::const_iterator ite(st.begin());
// 	printSize(st);

// 	printPair(++ite);
// 	printPair(ite++);
// 	printPair(ite++);
// 	printPair(++ite);

// 	std::cout << "la" << std::endl;
// 	it->m();
// 	ite->m();

// 	printPair(++it);
// 	printPair(it++);
// 	printPair(it++);
// 	printPair(++it);

// 	printPair(--ite);
// 	printPair(ite--);
// 	printPair(--ite);
// 	printPair(ite--);

// 	(*it).m();
// 	(*ite).m();

// 	printPair(--it);
// 	printPair(it--);
// 	printPair(it--);
// 	printPair(--it);

// 	return (0);
// }









// #include <list>

// #define T1 foo<int>

// int		main(void)
// {
// 	std::list<T1> lst;
// 	unsigned int lst_size = 5;
// 	for (unsigned int i = 0; i < lst_size; ++i)
// 		lst.push_back((i + 1) * 7);

// 	TESTED_NAMESPACE::set<T1> st(lst.begin(), lst.end());
// 	TESTED_NAMESPACE::set<T1>::reverse_iterator it(st.rbegin());
// 	TESTED_NAMESPACE::set<T1>::const_reverse_iterator ite(st.rbegin());
// 	printSize(st);

// 	printPair(++ite);
// 	printPair(ite++);
// 	printPair(ite++);
// 	printPair(++ite);

// 	it->m();
// 	ite->m();

// 	printPair(++it);
// 	printPair(it++);
// 	printPair(it++);
// 	printPair(++it);

// 	printPair(--ite);
// 	printPair(ite--);
// 	printPair(--ite);
// 	printPair(ite--);

// 	(*it).m();
// 	(*ite).m();

// 	printPair(--it);
// 	printPair(it--);
// 	printPair(it--);
// 	printPair(--it);

// 	return (0);
// }





#include <list>

#define T1 int

int		main(void)
{
	std::list<T1> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back((i + 1) * 7);

	ft::set<T1> st(lst.begin(), lst.end());
	ft::set<T1>::iterator it_ = st.begin();
	ft::set<T1>::reverse_iterator it(it_), ite;
	printSize(st);

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == dec(it, 3).base()) << std::endl;

	printPair(it.base());
	printPair(inc(it.base(), 1));

	std::cout << "TEST OFFSET" << std::endl;
	--it;
	printPair(it);
	printPair(it.base());

	it = st.rbegin(); ite = st.rend();
	while (it != ite)
		std::cout << "[rev] " << printPair(it++, false) << std::endl;
	// printReverse(st); <-- this causes a strange bug on the macos std lib ?

	return (0);
}
