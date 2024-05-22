/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmunir <nmunir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 13:06:21 by nmunir            #+#    #+#             */
/*   Updated: 2024/05/21 12:53:58 by nmunir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, const char** argv) {
	if (argc != 2)
	{
		std::cerr << "Invalid Input: ./< file name >" << std::endl;
		 return (1);
	}
	try
	{
		BitcoinExchange b(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
