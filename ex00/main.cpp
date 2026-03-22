/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 12:42:22 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/22 20:42:39 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>


int main(int argc, char **argv)
{
	if(argc == 2)
		ScalarConverter::convert(argv[1]);
	else
	{
		std::cout<<"Invalid number of arguments\n";
	}
	
	return (0);
}