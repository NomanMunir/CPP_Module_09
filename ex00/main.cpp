/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:06:21 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/20 11:06:51 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>

int main(int argc, const char** argv) {
	if (argc != 2)
		std::cerr << "Invalid Input: ./< file name >" << std::endl; return (1);
	std::ifstream file(argv[1]);
	if (!file.is_open() || file)
	{
		std::cerr << "Could not open file: " << argv[1] << std::endl;
		return (1);
	}
	std::string line;
	// file.getline(line, )
	// std::map<std::string, int> data;
	// data.insert(std::pair<std::string, int>("HI", 123));
	// std::map<std::string, int>::iterator it = data.begin();
	// for (it = data.begin(); it != data.end(); it++)
	// {
	// 	std::cout << it->first << " => " << it->second << "\n";
	// }
		
	return 0;
}
