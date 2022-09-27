/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:50:27 by ejahan            #+#    #+#             */
/*   Updated: 2022/09/27 19:08:59 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }

// #include "./INCS/vector.hpp"
// // #include <vector>

// #include <iostream>
// #include "./INCS/reverse_iterator.hpp"
// #include "./INCS/random_access.hpp"
// #include "./INCS/iterator_traits.hpp"
// #include "./INCS/lexicographical_compare.hpp"

// # include <algorithm>
// # include <memory>
// # include <cstddef>

// int main()
// {
// 	std::string	test_str = "test";
// 	ft::vector<std::string> test(8, test_str);
	
// 	test.assign(4, "change");
// 	test.assign(1, "first");
// 	std::cout << test.begin() << std::endl;

// 	return (0);
// }





// #include <vector>

// #include <iostream>

// # include <algorithm>
// # include <memory>
// # include <cstddef>

// #include <stdlib.h>

// int main()
// {
// 	std::string	test_str = "test";
// 	std::vector<int> test(8, 8);
	
// 	test.assign(7, 78);
// 	test.assign(4, 45);
// 	test.assign(1, 1);
// 	std::vector<int>::iterator it = test.begin();
// 	std::cout << *it << std::endl;
// 	std::cout << "size : " << test.size() << std::endl;
// 	std::cout << "capacity : " << test.capacity() << std::endl;
// 	std::cout << "max_size : " << test.max_size() << std::endl;
// 	std::cout << "front = " << test.front() << std::endl;
// 	std::cout << "back = " << test.back() << std::endl;
// 	std::cout << "data = " << test.data() << std::endl;
// 	test.reserve(12);
// 	std::cout << "new capacity = " << test.capacity() << std::endl;

// 	return (0);
// }











#include "./INCS/vector.hpp"

#include <iostream>
#include "./INCS/reverse_iterator.hpp"
#include "./INCS/random_access.hpp"
#include "./INCS/iterator_traits.hpp"
#include "./INCS/lexicographical_compare.hpp"

// #include <stdlib.h>

int main()
{
	// std::string	str = "test";
	ft::vector<int> test(8, 8);
	ft::vector<int>	test_swap(5, 6);
	// ft::vector<int>	test;
	
	test.assign(7, 78);
	test.assign(4, 45);
	// test.assign(1, 1);

	// ft::vector<int>::iterator it = test.begin();
	// std::cout << *it << std::endl;
	std::cout << "size : " << test.size() << std::endl;
	std::cout << "capacity : " << test.capacity() << std::endl;
	std::cout << "max_size : " << test.max_size() << std::endl;
	// test.clear();
	if (test.empty() == true)
		std::cout << "vector is empty" << std::endl;
	else
		std::cout << "vector is not empty" << std::endl;
	std::cout << "test[2] = "<< test[2] << std::endl;		// je comprends paaaaas
	std::cout << "test[0] = "<< test.at(0) << std::endl;
	std::cout << "front = " << test.front() << std::endl;
	std::cout << "back = " << test.back() << std::endl;
	std::cout << "data = " << test.data() << std::endl;
	test.pop_back();
	std::cout << "size : " << test.size() << std::endl;
	std::cout << "capacity : " << test.capacity() << std::endl;
	test.push_back(56);
	std::cout << "size : " << test.size() << std::endl;
	std::cout << "capacity : " << test.capacity() << std::endl;
	std::cout << "test[1] = "<< test[1] << std::endl;
	std::cout << "test[2] = "<< test[2] << std::endl;
	std::cout << "test[3] = "<< test[3] << std::endl;
	test.push_back(6);
	std::cout << "size : " << test.size() << std::endl;
	std::cout << "capacity : " << test.capacity() << std::endl;
	std::cout << "test[4] = "<< test[4] << std::endl;
	test.pop_back();
	std::cout << "size : " << test.size() << std::endl;
	std::cout << "capacity : " << test.capacity() << std::endl;
	// test.resize(2, 5);
	// std::cout << "size : " << test.size() << std::endl;
	// test.pop_back();
	// std::cout << "size : " << test.size() << std::endl;
	// std::cout << "capacity : " << test.capacity() << std::endl;
	// test.resize(2, 5);
	// std::cout << "size : " << test.size() << std::endl;
	// std::cout << "test[0] = "<< test[0] << std::endl;
	// std::cout << "test[1] = "<< test[1] << std::endl;
	// test.resize(1, 7);
	// std::cout << "size : " << test.size() << std::endl;
	// std::cout << "test[0] = "<< test[0] << std::endl;
	test.reserve(12);
	std::cout << "new capacity = " << test.capacity() << std::endl;
	std::cout << "size : " << test.size() << std::endl;

	// test.swap(test_swap);
	// std::cout << test.get_allocator() << std::endl;

	// if (test < test_swap)
	// 	std::cout << "test < test_swap" << std::endl;
	// else
	// 	std::cout << "test > test_swap" << std::endl;

	std::cout << std::endl;

	return (0);
}


// ITERATOR INVALIDATED ? 

