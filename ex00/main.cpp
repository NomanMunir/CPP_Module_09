/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:06:21 by nmunir            #+#    #+#             */
/*   Updated: 2024/06/02 16:07:54 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, const char** argv) {
	if (argc != 2)
	{
		std::cout << "Invalid Input: ./< file name >" << std::endl;
		 return (1);
	}
	try
	{
		BitcoinExchange b(argv[1]);
		BitcoinExchange a = BitcoinExchange(b);
		BitcoinExchange c = a;
		// c.printDatabase();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}

// 	date | value
// 2009-01-02 | 0
// 2011-01-03 | 3
// 2011-01-03 | 2
// 2011-01-03 | 1
// 2011-01-03 | 1.2
// 2011-01-09 | 1.12f
// 2012-01-11 | -1
// 2001-42-42
// 2012-01-11 | 1
// 2012-01-11 | 2147483648