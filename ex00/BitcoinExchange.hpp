/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:44:29 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/20 17:05:52 by nmunir           ###   ########.fr       */
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
	std::map<std::string, float> data;
	std::ifstream _inputFile;

	public:
		BitcoinExchange(std::string inputFile);
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& rhs);
		// void storeData();
		void compareValue(std::string& date, float value);
		void createInputFile(std::string& inputFile);
		void createDatabase();
};

#endif // !BITCOINEXCHANGE_HPP