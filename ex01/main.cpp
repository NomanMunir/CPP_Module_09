/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:24:37 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/21 15:48:33 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>
#include <sstream>
#include <string>
#include <cctype>
#include <cstdlib>

template <typename T>
void printStack(std::deque<T> stack) {
    while (!stack.empty()) {
        std::cout << stack.front() << "\n";
        stack.pop_front();
    }
    std::cout << std::endl;
}

bool validateInput(std::deque<std::string> stack)
{
	std::string validExp = "+-/*";
	size_t countExp = 0;
	size_t countDigit = 0;

	while (!stack.empty()) {
		if (stack.front().length() == 1 && validExp.find(stack.front()[0]) != std::string::npos)
			countExp++;
		else
		{
			std::string::iterator it = stack.front().begin();
			if (*it == '-' || *it == '+')
				it++;
			if (std::distance(it, stack.front().end()) < 2)
			{
				if (std::isdigit(*it))
					countDigit++;
				else
					return (false);
			}
			else
				return (false);
		}
        stack.pop_front();
    }
	if (countExp != countDigit - 1)
		return (false);
	return (true);
}
void calculate(std::deque<std::string> data) {
    std::deque<int> op;
    std::string exp = "+-*/";

    for (std::deque<std::string>::reverse_iterator rit = data.rbegin(); rit != data.rend(); ++rit) {
        std::string tok = *rit;
        if (exp.find(tok) != std::string::npos) {
            if (op.size() < 2) {
                std::cerr << "Invalid expression" << std::endl;
                return;
            }
            int a = op.back();
            op.pop_back();
            int b = op.back();
            op.pop_back();

            if (tok == "*")
                op.push_back(a * b);
            else if (tok == "-")
                op.push_back(b - a);
            else if (tok == "+")
                op.push_back(a + b);
            else if (tok == "/") {
                if (b == 0) {
                    std::cerr << "Division by zero" << std::endl;
                    return;
                }
                op.push_back(a / b);  // Correct order: a / b
            }
        } else {
            op.push_back(std::atoi(tok.c_str()));
        }
    }
    if (op.size() != 1) {
        std::cerr << "Invalid expression" << std::endl;
        return;
    }
    std::cout << "Result: " << op.front() << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: ./< input >" << std::endl;
		return (1);
	}
	std::deque<std::string> data;
	std::string input = av[1];
	std::istringstream iss(input);
    std::string word; 
	while(iss >> word)
		data.push_front(word);
	if (!validateInput(data))
		{ std::cerr << "Error" << std::endl; return (0); }
	
	return (0);
}