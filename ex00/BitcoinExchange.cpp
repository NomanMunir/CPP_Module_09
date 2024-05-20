/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:51:32 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/20 17:08:42 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::createDatabase()
{
	std::ifstream file("./data.csv");
	if (!file.is_open())
		throw std::runtime_error("Error: unable to open file.");

	std::string line;
	getline(file, line);

	while (std::getline(file, line))
	{	
		line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

		std::size_t pos = line.find(",");
		if (pos != std::string::npos)
		{
			std::string date = line.substr(0, pos);
			// isDateValid(date);
			std::string sValue = line.substr(pos + 1);
			std::istringstream iss(sValue);
            float value;
            iss >> value;
			if (iss.fail())
				throw std::runtime_error("Error: invalid float value in file.");
			// isValueValid(value);
			database.insert(std::make_pair(date, value));
		}
	}
	// 	std::map<std::string, float>::iterator it;
	// for (it = database.begin(); it != database.end(); it++)
	// {
	// 	std::cout << it->first << " => " << it->second << "\n";
	// }
}

bool isValueValid(float value)
{
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}
	else if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

void BitcoinExchange::createInputFile(std::string& inputFile)
{
	try
	{
		std::ifstream _inputFile(inputFile.c_str());
		if (!_inputFile.is_open())
			throw std::runtime_error("Error: unable to open file '" + inputFile + "'");
		std::string line;
		getline(_inputFile, line);

		while (std::getline(_inputFile, line))
		{	
			line.erase(std::remove(line.begin(), line.end(), ' '), line.end());

			std::size_t pos = line.find("|");
			if (pos != std::string::npos)
			{
				std::string date = line.substr(0, pos);
				// isDateValid(date);
				std::string sValue = line.substr(pos + 1);
				std::istringstream iss(sValue);
				float value;
				iss >> value;
				std::cout << value << std::endl;
				if (iss.fail())
					throw std::runtime_error("Error: invalid float value in file.");
				if (isValueValid(value))
					compareValue(date, value);
			// data.insert(std::make_pair(date, value));
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

BitcoinExchange::BitcoinExchange(std::string inputFile)
{
	try
	{
		createDatabase();
		createInputFile(inputFile);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		throw;
	}
}

void BitcoinExchange::compareValue(std::string& date, float value)
{
	std::map<std::string, float>::iterator it;
	for (it = database.begin(); it != database.end(); it++)
	{
		if (it->first == date)
			std::cout << it->second * value << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	return (*this);
}
