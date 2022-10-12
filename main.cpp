/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:50:27 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/12 16:48:18 by ejahan           ###   ########.fr       */
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





#include <vector>

#include <iostream>

# include <algorithm>
# include <memory>
# include <cstddef>

#include <stdlib.h>
#include "./INCS/vector.hpp"

void	printSize(ft::vector<int> vect)
{
	ft::vector<int>::iterator	it = vect.begin();
	ft::vector<int>::iterator	ite = vect.end();
	int	i = 0;

	for (; it != ite; it++, i++)
	{
		std::cout << "vect[" << i << "] = " << *it << std::endl;
		// std::cout << it[i] << std::endl;
	}
}

void	printVectstd(std::vector<int> vect)
{
	std::vector<int>::iterator	it = vect.begin();
	std::vector<int>::iterator	ite = vect.end();
	int	i = 0;

	for (; it != ite; it++, i++)
	{
		std::cout << "vect[" << i << "] = " << *it << std::endl;
		// std::cout << it[i] << std::endl;
	}
}

// int main()
// {
// 	ft::vector<int>	vect(5, 78);
// 	// ft::vector<int>::iterator it = vect.begin(), ite = vect.end();
// 	// ft::vector<int> vct_range(it, --(--ite));
	
// 	// std::cout << "vect[0] = " << vect[0] << std::endl;
// 	// std::cout << "vect[1] = " << vect[1] << std::endl;
// 	// std::cout << "vect[2] = " << vect[2] << std::endl;
// 	// std::cout << "vect[3] = " << vect[3] << std::endl;
// 	// std::cout << "vect[4] = " << vect[4] << std::endl;

// 	printSize(vect);
// 	// printVect(vct_range);
// 	// printVectstd(vectstd);

// 	return (0);
// }


#include <list>
int		main(void)
{
	std::list<int> lst;
	std::list<int>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	ft::vector<int> vct(lst.begin(), lst.end());
	printSize(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	printSize(vct);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	printSize(vct);
	return (0);
}


// int		main(void)
// {
// 	ft::vector<int> vct(5);
// 	ft::vector<int>::iterator it = vct.begin(), ite = vct.end();

// 	std::cout << "len: " << (ite - it) << std::endl;
// 	for (; it != ite; ++it)
// 		*it = (ite - it);

// 	it = vct.begin();
// 	ft::vector<int> vct_range(it, --(--ite));
// 	for (int i = 0; it != ite; ++it)
// 		*it = ++i * 5;

// 	it = vct.begin();
// 	ft::vector<int> vct_copy(vct);
// 	for (int i = 0; it != ite; ++it)
// 		*it = ++i * 7;
// 	vct_copy.push_back(42);
// 	vct_copy.push_back(21);

// 	std::cout << "\t-- PART ONE --" << std::endl;
// 	printSize(vct);
// 	printSize(vct_range);
// 	printSize(vct_copy);

// 	vct = vct_copy;
// 	vct_copy = vct_range;
// 	vct_range.clear();

// 	std::cout << "\t-- PART TWO --" << std::endl;
// 	printSize(vct);
// 	printSize(vct_range);
// 	printSize(vct_copy);
// 	return (0);
// }












// #include "./INCS/vector.hpp"

// #include <iostream>
// #include "./INCS/reverse_iterator.hpp"
// #include "./INCS/random_access.hpp"
// #include "./INCS/iterator_traits.hpp"
// #include "./INCS/lexicographical_compare.hpp"

// // #include <stdlib.h>

// int main()
// {
// 	std::string	str = "test";
// 	ft::vector<std::string> test(8, str);
// 	ft::vector<std::string>	test_swap(8, "testt");
// 	ft::vector<std::string>::iterator it = test.begin(), ite = test.end();
// 	// ft::vector<int>	test;

// 	// ft::vector<std::string>::iterator it = test.begin();
// 	// ++it;
// 	// std::cout << "it begin = " << *it << std::endl;
// 	// // test.push_back("6");
// 	// ft::vector<std::string>::iterator it2 = test.end();
// 	// std::cout << "it end = " << *it2 << *(it + 2) << std::endl;	

// 	// ft::vector<std::string> vct_range(it, --(--ite));

	

// 	std::cout << std::endl;

// 	return (0);
// }


// #include "./INCS/stack.hpp"

// #include <iostream>
// #include <vector>
// #include "./INCS/reverse_iterator.hpp"
// #include "./INCS/random_access.hpp"
// #include "./INCS/iterator_traits.hpp"
// #include "./INCS/lexicographical_compare.hpp"

// int	main()
// {
// 	std::vector<int> test(8, 7);
// 	std::vector<int> testt(8, 37);
// 	ft::stack<int>	test_stack(test);
// 	ft::stack<int>	test_op(testt);
// 	if (test_stack < test_op)
// 		std::cout << "salut salut" << std::endl;
// 	else
// 		std::cout << "etryty" << std::endl;
// 	return (0);
// }











// ITERATOR INVALIDATED ? 

