/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:47:39 by nmunir            #+#    #+#             */
/*   Updated: 2024/06/03 08:44:20 by nmunir           ###   ########.fr       */
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

typedef std::list<int>::iterator IntListIterator;
typedef std::pair<int, int> IntPair;

class PmergeMe
{
	private:
		std::vector<int> vec;
		std::list<int> lst;
		size_t _size;
		PmergeMe();
		bool isDigitValid(std::string value);
		void printBeforeAndAfter(const char **av);
		void printPairs(std::vector<std::pair<int, int> > &pairs);
		size_t jacobsthal(size_t n);
		std::list<IntPair> createPairsList(std::list<int> lst);
		void sortPairList(std::list<std::pair<int, int> > &pairs, size_t n);
		void sortPairVector(std::vector<std::pair<int, int> > &pairs, size_t n);
		std::vector<int> build_jacob_insertion_sequence_for_vec(size_t size);
		std::list<int> build_jacob_insertion_sequence(size_t size);
		std::list<int>::iterator bisearch(std::list<int>& S, int item);
		std::vector<int>::iterator bisearch(std::vector<int>& S, int item);
		void createSortedList(std::list<int> &S, std::list<int> &pend);
		void createSortedVector(std::vector<int> &S, std::vector<int> &pend);
		std::vector<std::pair<int, int> > createPairsVector(std::vector<int> vec);
	public:
		PmergeMe(const char **av);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& rhs);
		~PmergeMe();
		std::vector<int> sortWithVec();
		std::list<int> sortWithLst();

		template <class T>
		void print(const T& data);
};

template <class T>
void PmergeMe::print(const T& data)
{
    typename T::const_iterator it = data.begin();
    for (; it != data.end(); ++it)
    {
        std::cout << *it << " ";
    }
	std::cout << std::endl;
}
#endif // PMERGEME_HPP