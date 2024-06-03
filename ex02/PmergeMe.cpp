/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:52:57 by nmunir            #+#    #+#             */
/*   Updated: 2024/06/03 08:44:45 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

size_t PmergeMe::jacobsthal(size_t n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::list<IntPair> PmergeMe::createPairsList(std::list<int> lst)
{
    std::list<IntPair> pairs;
    IntListIterator i = lst.begin();
    while (i != lst.end())
    {
        IntListIterator next = i;
        ++next;
        if (next != lst.end())
        {
            if (*i < *next)
                pairs.push_back(IntPair(*i, *next));
            else
                pairs.push_back(IntPair(*next, *i));
        }
        ++i; ++i;
    }
    return pairs;
}

void PmergeMe::sortPairList(std::list<std::pair<int, int> > &pairs, size_t n)
{
    if (n <= 1)
        return;
    sortPairList(pairs, n - 1);
    size_t i = n - 1;
    std::list<std::pair<int, int> >::iterator it = pairs.begin();
    std::advance(it, n - 1);
    std::pair<int, int> newPair = *it;
    std::list<std::pair<int, int> >::iterator prevIt = it;
    --prevIt;
    for (; i > 0 && (newPair.second < prevIt->second); --i)
    {
        *it = *prevIt;
        --it;
        --prevIt;
    }
    *it = newPair;
}

std::list<int> PmergeMe::build_jacob_insertion_sequence(size_t size)
{
    std::list<int> end_sequence;
    size_t jacob_index = 3;
    while (jacobsthal(jacob_index) < size - 1)
    {
        end_sequence.push_back(jacobsthal(jacob_index));
        jacob_index += 1;
    }
    return (end_sequence);
}

std::list<int>::iterator PmergeMe::bisearch(std::list<int>& S, int item)
{
    return std::upper_bound(S.begin(), S.end(), item);
}

void PmergeMe::createSortedList(std::list<int> &S, std::list<int> &pend)
{
    std::list<int> jacob_sequence = build_jacob_insertion_sequence(pend.size());
    size_t iter = 0;
    bool isJacob = true;
    S.insert(S.begin(), pend.front());
    if (pend.size() == 1)
        return;
    std::list<int> indexSequence;
    indexSequence.push_back(1);
    int item;
    while (iter <= pend.size())
    {
        if(jacob_sequence.size() != 0 && isJacob)
        {
            indexSequence.push_back(jacob_sequence.front());
            std::list<int>::iterator it = pend.begin();
            std::advance(it, jacob_sequence.front() - 1);
            item = *it;
            jacob_sequence.erase(jacob_sequence.begin());
            isJacob = false;
        }
        else
        {
            if (std::find(indexSequence.begin(), indexSequence.end(), iter) != indexSequence.end())
                iter++;
            indexSequence.push_back(iter);
            if (iter == 0)
            {
                iter++;
                continue;
            }
            std::list<int>::iterator it = pend.begin();
            std::advance(it, iter - 1);
            item = *it;
            isJacob = true;
        }
        std::list<int>::iterator pos = bisearch(S, item);
        S.insert(pos, item);
        iter++;
    }
}

std::vector<std::pair<int, int> > PmergeMe::createPairsVector(std::vector<int> vec)
{
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vec.size() - 1; i += 2)
    {
        if (vec[i] < vec[i + 1])
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        else
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
    }
    return (pairs);
}

void PmergeMe::sortPairVector(std::vector<std::pair<int, int> > &pairs, size_t n)
{
    if (n <= 1)
        return ;
    sortPairVector(pairs, n - 1);
    size_t i = n - 1;
    std::pair<int, int> newPair = pairs[n - 1];
    for (; i > 0 && newPair.second < pairs[i - 1].second; i--)
        pairs[i] = pairs[i - 1];
    pairs[i] = newPair;
}

void PmergeMe::printPairs(std::vector<std::pair<int, int> > &pairs)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::cout << "pair: " << pairs[i].first <<  " -> " << pairs[i].second << std::endl;
    }
}

std::vector<int> PmergeMe::build_jacob_insertion_sequence_for_vec(size_t size)
{
    std::vector<int> end_sequence;
    size_t jacob_index = 3;
    while (jacobsthal(jacob_index) < size - 1)
    {
        end_sequence.push_back(jacobsthal(jacob_index));
        jacob_index += 1;
    }
    return (end_sequence);
}

std::vector<int>::iterator PmergeMe::bisearch(std::vector<int>& S, int item)
{
    return std::upper_bound(S.begin(), S.end(), item);
}

void PmergeMe::createSortedVector(std::vector<int> &S, std::vector<int> &pend)
{
    std::vector<int> jacob_sequence = build_jacob_insertion_sequence_for_vec(pend.size());
    size_t iter = 0;
    bool isJacob = true;
    S.insert(S.begin(), pend[0]);
    if (pend.size() == 1)
        return;
    std::vector<int> indexSequence;
    indexSequence.push_back(1);
    int item;
    while (iter <= pend.size())
    {
        if(jacob_sequence.size() != 0 && isJacob)
        {
            indexSequence.push_back(jacob_sequence[0]);
            item = pend[jacob_sequence[0] - 1];
            jacob_sequence.erase(jacob_sequence.begin());
            isJacob = false;
        }
        else
        {
            while (std::find(indexSequence.begin(), indexSequence.end(), iter) != indexSequence.end())
                iter++;
            indexSequence.push_back(iter);
            if (iter == 0)
            {
                iter++;
                continue;
            }
            item = pend[iter - 1];
            isJacob = true;
        }
        std::vector<int>::iterator pos = bisearch(S, item);
        S.insert(pos, item);
        iter++;
    }
}

bool PmergeMe::isDigitValid(std::string value)
{
    std::string::iterator i = value.begin();
    if (value.empty() || *i == '-')
        return (false);
    if (*i == '+')
        i++;
    if (i == value.end())
        return (false);
    while (i != value.end())
    {
        if (!std::isdigit(*i))
            return (false);
        i++;
    }
	if (std::atof(value.c_str()) > INT_MAX)
		return (false);
    return (true);    
}

std::list<int> PmergeMe::sortWithLst()
{
    int staggler;
    bool isOdd = false;
    if (lst.size() % 2 != 0)
    {
        staggler = lst.back();
        isOdd = true;
        lst.pop_back();
    }
    std::list<std::pair<int, int> > pairs =  createPairsList(lst);
    sortPairList(pairs, pairs.size());
    std::list<int> S;
    std::list<int> pend;
    std::list<std::pair<int, int> >::iterator i = pairs.begin();
    for (; i != pairs.end(); i++)
    {
        S.push_back(i->second);
        pend.push_back(i->first);
    }
    if (isOdd)
        pend.push_back(staggler);
    createSortedList(S, pend);
    return (S);
}

std::vector<int> PmergeMe::sortWithVec()
{
    int staggler;
    bool isOdd = false;
    if (_size % 2 != 0)
    {
        staggler = vec.back();
        isOdd = true;
        vec.erase(vec.end() - 1);
    }
    std::vector<std::pair<int, int> > pairs =  createPairsVector(vec);
    sortPairVector(pairs, pairs.size());
    std::vector<int> S;
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        S.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }
    if (isOdd)
        pend.push_back(staggler);
    createSortedVector(S, pend);
    return (S);
}

void PmergeMe::printBeforeAndAfter(const char **av)
{
    size_t i = 1;
    std::cout << "Before:  ";
    clock_t start_vec = clock();
    while (i <= _size)
    {
        vec.push_back(std::atoi(av[i]));
        i++;
    }
    print(vec);
    std::vector<int> S_vec = sortWithVec();
    clock_t end_vec = clock();
    
    clock_t start_lst = clock();
    i = 1;
    while (i <= _size)
    {
        lst.push_back(std::atoi(av[i]));
        i++;
    }
    std::list<int> S_lst = sortWithLst();
    clock_t end_lst = clock();
    
    double elapsed_vec = static_cast<double>(end_vec - start_vec) / CLOCKS_PER_SEC;
    double elapsed_lst = static_cast<double>(end_lst - start_lst) / CLOCKS_PER_SEC;
    std::cout << "After:  ";
    print(S_lst);
    std::cout << "Time to process a range of " << _size << " elements with std::vector : " << std::fixed << std::setprecision(7) << elapsed_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << _size << " elements with std::list : " << std::fixed << std::setprecision(7) << elapsed_lst << " us" << std::endl;
}

PmergeMe::PmergeMe(const char **av)
{
    _size = 0;
    size_t i = 1;
    while (av[i])
    {
        if (!isDigitValid(av[i]))
			throw std::runtime_error ("Error: '" + std::string(av[i]) + "'");
        i++;
        _size++;
    }
    if (_size == 1)
        return ;
    printBeforeAndAfter(av);
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	*this = other;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs) {
        vec = rhs.vec;
        lst = rhs.lst;
    }
	return (*this);
}

PmergeMe::~PmergeMe() { }
