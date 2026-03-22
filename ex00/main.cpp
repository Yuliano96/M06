/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 12:42:22 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/22 19:35:22 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>


int main(int argc, char **argv)
{
	if(argc == 2)
	{
		ScalarConverter::convert(argv[1]);
	}
	/*ScalarConverter::convert("12");
	ScalarConverter::convert("a");
	ScalarConverter::convert("-");
	ScalarConverter::convert("0");
	ScalarConverter::convert("2147483647");
	ScalarConverter::convert("21474836479");
	ScalarConverter::convert(" ");
	ScalarConverter::convert("1.34f");
	ScalarConverter::convert("1.345");*/
	return (0);
}