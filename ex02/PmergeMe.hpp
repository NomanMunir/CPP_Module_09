/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:47:39 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/26 14:00:30 by nmunir           ###   ########.fr       */
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

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::list<int> lst;
		PmergeMe();
		bool isDigitValid(std::string value);
	public:
		PmergeMe(const char **av);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& rhs);
		std::vector<int> sortWithVec();
		std::list<int> sortWithLst();
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