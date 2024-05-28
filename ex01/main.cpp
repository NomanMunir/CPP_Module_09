/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:24:37 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/28 12:17:26 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

template <typename T>
void printStack(std::deque<T> stack) {
    while (!stack.empty()) {
        std::cout << stack.front() << "\n";
        stack.pop_front();
    }
    std::cout << std::endl;
}


int main(int ac, const char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: ./< input >" << std::endl;
		return (1);
	}
    try
    {
        RPN(std::string(av[1]));
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	return (0);
}
