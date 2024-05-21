/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:44:29 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/21 12:10:49 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <stdexcept>

class BitcoinExchange
{
	std::map<std::string, float> database;
	bool isLeapYear(int year);
	public:
		BitcoinExchange(std::string inputFile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		// void storeData();
		void compareValue(const std::string& date, float value);
		void createInputFile(std::string& inputFile);
		void createDatabase();
		void printDatabase();
		bool isDateValid(const std::string date);
};

#endif // !BITCOINEXCHANGE_HPP