/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:47:39 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/27 15:22:06 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PMERGEME_HPP
#define	PMERGEME_HPP
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <climits>
#include <algorithm>
#include <list>
#include <utility>
#include <iomanip>

// template <class Container>

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::list<int> lst;
		PmergeMe();
		size_t jacobsthal(size_t n);
		bool isDigitValid(std::string value);
		void sortAndPrint();
		std::vector<int> sortWithVec();
		std::list<int> sortWithLst();
	public:
		PmergeMe(const char **av);
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& rhs);
		void sort();
};

template <class T>
void print(const T& data)
{
    typename T::const_iterator it = data.begin();
    for (; it != data.end(); ++it)
    {
        std::cout << *it << " ";
    }
	std::cout << std::endl;
}
#endif // PMERGEME_HPP