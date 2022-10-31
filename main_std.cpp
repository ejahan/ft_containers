/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_std.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:13:37 by ejahan            #+#    #+#             */
/*   Updated: 2022/10/31 23:02:37 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
================================================================================
TEST SUJET
================================================================================
*/

// #include <iostream>
// #include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include "./INCS/map.hpp"
// 	#include "./INCS/stack.hpp"
// 	#include "./INCS/vector.hpp"
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












/*
===================================================================================
===================================================================================
===================================================================================
									   TESTS
===================================================================================
===================================================================================
===================================================================================
*/

#include <sys/time.h>
#include <iostream>
# define NOR "\033[m"
# define GREY "\033[1;30m"
# define BLUE "\033[1;34m"
# define WHITE "\033[1;37m"
# define CYAN "\033[1;36m"
# define PURPLE "\033[1;35m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELL "\033[1;33m"

# define H_NOR "\033[m"
# define H_GREY "\033[1;40m"
# define H_BLUE "\033[1;44m"
# define H_WHITE "\033[1;47m"
# define H_CYAN "\033[1;46m"
# define H_PURPLE "\033[1;45m"
# define H_RED "\033[1;41m"
# define H_GREEN "\033[1;42m"
# define H_YELL "\033[1;43m"



/*
================================================================================
TESTS VECTOR
================================================================================
*/

#include <vector>

void	print_vector(std::vector<int> vect, std::string str)
{
	std::vector<int>::iterator	it = vect.begin();
	std::vector<int>::iterator	ite = vect.end();

	std::cout << std::endl << WHITE << str << NOR << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
}

void	vector_test()
{
	std::cout << "=====================================================================" << std::endl << "				VECTOR" <<std::endl << "=====================================================================" << std::endl << std::endl << std::endl;

	std::vector<int>	vector1;
	if (vector1.empty() == true)
		std::cout << GREEN << "vector1 is empty" << NOR << std::endl << std::endl;
	for (int n(5); n > 0; n--)
	{
		std::cout << GREY << "*push_back*" << NOR << std::endl;
		vector1.push_back(n * 4);
	}
	print_vector(vector1, "vector1 :");
	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;
	std::cout << PURPLE << "max_size " << NOR << "vector1 = " << vector1.max_size() << std::endl;

	if (vector1.empty() != true)
		std::cout << std::endl << GREEN << "vector1 is not empty" << NOR << std::endl << std::endl;

	std::cout << GREY << "*pop_back*" << NOR << std::endl;
	vector1.pop_back();
	std::cout << GREY << "*pop_back*" << NOR << std::endl;
	vector1.pop_back();

	print_vector(vector1, "vector1 :");
	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;

	std::cout << std::endl << std::endl << std::endl << BLUE << "===============" << std::endl;
	std::cout << "*assign(7, 55)*" << std::endl;
	std::cout << "===============" << std::endl << NOR;
	vector1.assign(7, 55);
	print_vector(vector1, "vector1 :");
	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;

	std::cout << std::endl << std::endl << std::endl << BLUE << "===============" << std::endl;
	std::cout << "*assign(5, 12)*" << std::endl;
	std::cout << "===============" << std::endl << NOR;
	vector1.assign(5, 12);
	print_vector(vector1, "vector1 :");
	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;

	std::cout << std::endl << std::endl << std::endl << BLUE << "===============" << std::endl;
	std::cout << "*reserve(14)*" << std::endl;
	std::cout << "===============" << std::endl << NOR;
	vector1.reserve(14);
	print_vector(vector1, "vector1 :");
	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;

	std::cout << std::endl << std::endl << std::endl << BLUE << "===============" << std::endl;
	std::cout << "*resize(10)*" << std::endl;
	std::cout << "===============" << std::endl << NOR;
	vector1.resize(10);
	print_vector(vector1, "vector1 :");
	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;


	std::cout << std::endl << std::endl << std::endl << BLUE << "===============" << std::endl;
	std::cout << "*resize(2)*" << std::endl;
	std::cout << "===============" << std::endl << NOR;
	vector1.resize(2);
	print_vector(vector1, "vector1 :");
	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;

	std::cout << std::endl << std::endl << std::endl << BLUE << "===============" << std::endl;
	std::cout << "*insert*" << std::endl;
	std::cout << "===============" << std::endl << NOR;
	vector1.insert(vector1.begin(), 10);
	print_vector(vector1, "vector1 :");
	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;

	std::cout << std::endl << GREY << "*insert*" << std::endl << NOR;
	vector1.insert(vector1.begin() + 1, 3, 78);
	std::cout << GREY << "*insert*" << std::endl << NOR;
	vector1.insert(vector1.begin() + 3, 452);
	std::cout << GREY << "*insert*" << std::endl << NOR;
	vector1.insert(vector1.begin() + 1, 45);
	std::cout << GREY << "*insert*" << std::endl << NOR;
	vector1.insert(vector1.begin(), 7);
	std::cout << GREY << "*insert*" << std::endl << NOR;
	vector1.insert(vector1.begin() + 2, 7458);

	print_vector(vector1, "vector1 :");
	std::cout << std::endl << PURPLE << "size " << NOR << "vector1 = " << vector1.size() << std::endl;
	std::cout << PURPLE << "capacity " << NOR << "vector1 = " << vector1.capacity() << std::endl;

	std::cout << std::endl << GREEN << "front -> " << vector1.front() << std::endl << NOR;
	std::cout << GREEN << "back -> " << vector1.back() << std::endl << NOR;

	std::cout << std::endl << CYAN << "========================" << std::endl << NOR;
	std::cout << CYAN << "CONSTRUCT vector_range :" << std::endl << NOR;
	std::vector<int>	vector_range(vector1.begin() + 1, vector1.begin() + 8);
	print_vector(vector_range, "vector_range :");

	std::cout << std::endl << CYAN << "===================" << std::endl << NOR;
	std::cout << CYAN << "CONSTRUCT vector2 :" << std::endl << NOR;
	std::vector<int>	vector2(6, 123);
	print_vector(vector2, "vector2 :");

	std::cout << std::endl << std::endl << BLUE << "===================" << std::endl;
	std::cout << "*vector2 = vector1*" << std::endl;
	std::cout << "===================" << std::endl << NOR;
	vector2 = vector1;
	std::vector<int>::iterator	it = vector2.begin();
	std::vector<int>::iterator	ite = vector2.end();
	int	i = 0;

	std::cout << std::endl << WHITE << "vector2	:		vector1 :" << NOR << std::endl;
	while (it != ite)
	{
		std::cout << *it << "			" << vector1[i] << std::endl;
		it++;
		i++;
	}

	std::cout << std::endl << std::endl << BLUE << "===================" << std::endl;
	std::cout << "*SWAP*" << std::endl;
	std::cout << "===================" << std::endl << NOR;
	vector2.swap(vector_range);
	print_vector(vector2, "vector2 :");
	print_vector(vector_range, "vector_range :");

	std::cout << std::endl << std::endl << BLUE << "===================" << std::endl;
	std::cout << "*ERASE*" << std::endl;
	std::cout << "===================" << std::endl << NOR;
	vector2.erase(vector2.begin() + 2);
	print_vector(vector2, "vector2 :");

	std::cout << std::endl << std::endl << BLUE << "===================" << std::endl;
	std::cout << "*ERASE RANGE*" << std::endl;
	std::cout << "===================" << std::endl << NOR;
	vector2.erase(vector2.begin(), vector2.begin() + 3);
	print_vector(vector2, "vector2 :");

	std::cout << std::endl << std::endl << BLUE << "===================" << std::endl;
	std::cout << "*CLEAR*" << std::endl;
	std::cout << "===================" << std::endl << NOR;
	vector2.clear();
	std::cout << std::endl << PURPLE << "size " << NOR << "= " << vector2.size() << std::endl;

	std::cout << std::endl << std::endl;

}







/*
================================================================================
TESTS STACK
================================================================================
*/

#include <stack>

void	stack_test()
{
	std::cout << "=====================================================================" << std::endl << "				STACK" <<std::endl << "=====================================================================" << std::endl << std::endl << std::endl;

}








/*
================================================================================
TESTS MAP
================================================================================
*/

#include <map>

void	map_test()
{
	std::cout << "=====================================================================" << std::endl << "				 MAP" <<std::endl << "=====================================================================" << std::endl << std::endl << std::endl;

}











/*
================================================================================
MAIN TESTS
================================================================================
*/

int	main()
{
	unsigned int	i;
	unsigned int	j;
	struct timeval	time;
	gettimeofday(&time, NULL);
	i = (time.tv_sec * 1000 + time.tv_usec / 1000);
	vector_test();
	// stack_test();
	// map_test();

	gettimeofday(&time, NULL);
	j = (time.tv_sec * 1000 + time.tv_usec / 1000);
	std::cout << "TIME = " << j - i << std::endl;
	return (0);
}






