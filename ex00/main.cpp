/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:06:21 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/21 10:14:31 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isWhitespaceOnly(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isspace(*it)) {
            return false;
        }
    }
    return true;
}

void isFileValid(const char *fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
		throw std::runtime_error("Unable to open file: " + std::string(fileName));
	std::string line;
	// check if the file is empty!
	
	// std::getline(file, line, '\0');
	// if (line.empty())
	// 	throw std::runtime_error("File: '" + std::string(fileName) +  "' is empty.");
	
	while(getline(file, line))
	{
		if (isWhitespaceOnly(line))
			throw std::runtime_error("File is empty!");
	}
}




int main(int argc, const char** argv) {
	if (argc != 2)
	{
		std::cerr << "Invalid Input: ./< file name >" << std::endl;
		 return (1);
	}
	BitcoinExchange b(argv[1]);
	// b.printDatabase();
	// b.compareFile();
	// try
	// {
	// 	isFileValid(argv[1]);
		
	// 	std::ifstream file(argv[1]);
	// 	std::string line;
	// 	std::getline(file, line);
	// 	std::map<std::string, float> data;
	// 	while (std::getline(file, line))
	// 	{
	// 		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
	// 		std::size_t pos = line.find("|");
	// 		if (pos != std::string::npos)
	// 		{	
	// 			std::string date = line.substr(0, pos);
	// 			// isDateValid(date);
	// 			std::string sValue = line.substr(pos + 1);
	// 			float value = std::stof(line.substr(pos + 1));
	// 			if (isValueValid(sValue, date))
	// 				data.insert(std::pair<std::string, float>(date, value));
	// 		}
	// 		else 
	// 		{
	// 			std::cout << "empty value\n";
	// 		}
	// 	}
	// 	std::map<std::string, float>::iterator it;
	// 	// for (it = data.begin(); it != data.end(); it++)
	// 	// {
	// 	// 	std::cout << it->first << " => " << it->second << "\n";
	// 	// }
		
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	
	
		
	return 0;
}
