/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 20:39:10 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/22 19:07:38 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

#include <string>
#include <cctype>
#include <cstdlib>
#include <cmath>
#define INT_MAX 2147483647
#define INT_MIN -2147483648

class ScalarConverter
{
	private:
	enum {FALSE, CHAR, INT, FLOAT, DOUBLE};
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
	static int IsInteger(const std::string &value);
	static int EvaDecimal(const std::string &value);
	static int IsFloat(const std::string &value);
	static int IsDouble(const std::string &value);
	static int DetectType(const std::string &value);
	static char ParseChar(const std::string &value);
	static int ParseInt(const std::string &value);
	static void ConverDecimal(double dnum, float fnum);
	static void ConverChar(char c);
	static void ConverInt(int num);
	
	public:
	
	static void convert(const std::string &value);
	
};
#endif