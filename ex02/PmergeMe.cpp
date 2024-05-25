/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:52:57 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/25 15:35:51 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<std::pair<int, int> > createPairs(std::vector<int> vec)
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

void sortPair(std::vector<std::pair<int, int> > &pairs, size_t n)
{
    if (n <= 1)
        return ;
    sortPair(pairs, n - 1);
    size_t i = n - 1;
    std::pair<int, int> newPair = pairs[n - 1];
    for (; i > 0 && newPair.second < pairs[i - 1].second; i--)
        pairs[i] = pairs[i - 1];
    pairs[i] = newPair;
}

void printPairs(std::vector<std::pair<int, int> > &pairs)
{
    for (size_t i = 0; i < pairs.size(); i++)
    {
        std::cout << "pair: " << pairs[i].first <<  " -> " << pairs[i].second << std::endl;
    }
}

size_t jacobsthal(size_t n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector<int> build_jacob_insertion_sequence(size_t size)
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

std::vector<int>::iterator bisearch(std::vector<int>& S, int item)
{
    return std::upper_bound(S.begin(), S.end(), item);
}

void create_S(std::vector<int> &S, std::vector<int> &pend)
{
    std::vector<int> jacob_sequence = build_jacob_insertion_sequence(pend.size());
    size_t iter = 0;
    size_t jacobIndex = 3;
    bool isJacob = true;
    S.insert(S.begin(), pend[0]);
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
            if (std::find(indexSequence.begin(), indexSequence.end(), iter) != indexSequence.end())
                iter++;
            indexSequence.push_back(iter);
            std::cout << "iter: " << iter << std::endl;
            if (iter == 0)
            {
                iter++;
                continue;
            }
            item = pend[iter - 1];
            std::cout << "item: " << item << std::endl;
            
            isJacob = true;
        }
        std::cout <<"hi\n";
        print(indexSequence);
        std::vector<int>::iterator pos = bisearch(S, item);
        S.insert(pos, item);
        iter++;
        jacobIndex++;
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
PmergeMe::PmergeMe(const char **av)
{
    while (++av && *av)
    {
        if (!isDigitValid(*av))
			throw std::runtime_error ("Error: '" + std::string(*av) + "'");
        vec.push_back(std::atoi(*av));
		lst.push_back(std::atoi(*av));
    }
    std::vector<std::pair<int, int> > pairs =  createPairs(vec);
    sortPair(pairs, pairs.size());
    // printPairs(pairs);
    std::vector<int> S;
    std::vector<int> pend;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        S.push_back(pairs[i].second);
        pend.push_back(pairs[i].first);
    }
    print(S);
    create_S(S, pend);
    print(S);
    
	// std::cout<<"Vector\n";
    
	// print(vec);
	// std::cout<<"List\n";
	// print(lst);
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
