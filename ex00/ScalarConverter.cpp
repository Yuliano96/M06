/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 20:49:57 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/22 22:48:53 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter()
{
	std::cout<<"ScalarConverter default constructor\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
	std::cout<<"ScalarConverter copy constructor\n";
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if(this != &other)
	{

	}
	std::cout<<"ScalarConverter assignment operator\n";
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout<<"ScalarConverter destroyed\n";
}

int ScalarConverter::IsInteger(const std::string &value)
{
	size_t i;

	if (value == "")
		return FALSE;
	i = 0;
	if ((value[0] == '+' || value[0] == '-') && value.size() > 1)
		i++;
	while(i < value.size())
	{
		if (!isdigit(value[i]))
			return FALSE;
			
		i++;
	}
	return INT;
}
int ScalarConverter::EvaDecimal(const std::string &value)
{
	if (value.size() < 2)
		return FALSE;
	for (size_t i = 0; i < (value.size() - 1); i++)
	{
		if (!isdigit(value[i]))
			return FALSE;
	}
	if (value[value.size() - 1] == 'f')
		return FLOAT;
	return FALSE;
}
int ScalarConverter::IsFloat(const std::string &value)
{
	std::string integer;
	std::string decimal;
	size_t index;
	
	if (value == "")
		return FALSE;
		
	index = value.find(".");
	if(index != std::string::npos)
	{
		integer = value.substr(0,index);
		if (IsInteger(integer) == INT)
		{
			decimal = value.substr(index + 1);
			if (EvaDecimal(decimal) == FLOAT)
				return FLOAT;
			else
				return FALSE;
				
		}
		else
			return FALSE;
	}
	return FALSE;
}

int ScalarConverter::IsDouble(const std::string &value)
{
	std::string integer;
	std::string decimal;
	size_t index;

	if (value == "")
		return FALSE;
	
	index = value.find(".");
	if(index != std::string::npos)
	{
		integer = value.substr(0,index);
		decimal = value.substr(index + 1);
		if (IsInteger(integer) == INT)
		{
			if ( decimal == ""|| decimal[0] == '+' || decimal[0] == '-')
				return FALSE;
			else if (IsInteger(decimal) == INT)
				return DOUBLE;
		}
		else
			return FALSE;
	}
	return FALSE;
}

int ScalarConverter::DetectType(const std::string &value)
{
	
	if (value.size() == 1)
	{
		if (isprint(value[0]))
		{
			if(isdigit(value[0]))
				return INT;
			else if (value[0] != '+' && value[0] != '-')
				return CHAR;
				
		}
		return FALSE;
	}
	else if (value.size() > 1)
	{
		if (IsInteger(value) == INT)
			return INT;	
		if (IsFloat(value) == FLOAT)
			return FLOAT;
		if (IsDouble(value) == DOUBLE)
			return DOUBLE;
	}
	return FALSE;
}

char ScalarConverter::ParseChar(const std::string &value)
{
	char c = static_cast<char>(value[0]);	
	return c;
}

int ScalarConverter::ParseInt(const std::string &value)
{
	long int num;
	
	num = atol(value.c_str());
	if (num < INT_MIN  || num > INT_MAX)
		throw "value out of range\n";	
	return (int)num;
}

double ScalarConverter::ParseDouble(const std::string &value)
{
	double num;
	num = atof(value.c_str());
	return num;
}

void ScalarConverter::ConverDouble(double dnum)
{
	
	float fnum;
	
	if (dnum < 0 || dnum > 127)
		std::cout<<"char : impossible\n";
	else if (isprint(static_cast<int>(dnum)))
		std::cout<<"char : '"<<static_cast<char>(dnum)<<"'\n";
	else
		std::cout<<"char : Non displayable\n";
	if (dnum >= INT_MIN && dnum <= INT_MAX)
		std::cout<<"int : "<<static_cast<int>(dnum)<<"\n";
	else
		std::cout<<"int : impossible\n";
	fnum = static_cast<float>(dnum);
	ConverDecimal(dnum, fnum);
}

void ScalarConverter::ConverFloat(float fnum)
{
		double dnum;
	
	if (fnum < 0 || fnum > 127)
		std::cout<<"char : impossible\n";
	else if (isprint(static_cast<int>(fnum)))
		std::cout<<"char : '"<<static_cast<char>(fnum)<<"'\n";
	else
		std::cout<<"char : Non displayable\n";
	if (fnum >= INT_MIN && fnum <= INT_MAX)
		std::cout<<"int : "<<static_cast<int>(fnum)<<"\n";
	else
		std::cout<<"int : impossible\n";
	dnum = static_cast<double>(fnum);
	ConverDecimal(dnum, fnum);
}

void ScalarConverter::ConverDecimal(double dnum, float fnum)
{
	if (fnum != floor(fnum))
		std::cout<<"float : "<<fnum<<"f\n";
	else
		std::cout<<"float : "<<fnum<<".0f\n";
	if (dnum != floor(dnum))
		std::cout<<"double: "<<dnum<<"\n";	
	else
		std::cout<<"double: "<<dnum<<".0\n";
}

void ScalarConverter::ConverChar(char c)
{
	double d_temp;
	float f_temp;
	
	std::cout<<"char  : '"<< c                   <<"'\n";
	std::cout<<"int   : " <<static_cast<int>(c)  <<std::endl;
	d_temp = static_cast<double>(c);
	f_temp = static_cast<float>(c);
	ConverDecimal(d_temp, f_temp);
}


void ScalarConverter::ConverInt(int num)
{
	double d_temp;
	float f_temp;
	if (num < 0 || num > 127)
		std::cout<<"char : impossible\n";
	else if (isprint(num))
		std::cout<<"char : '"<<static_cast<char>(num)<<"'\n";
	else
		std::cout<<"char : Non displayable\n";
	std::cout<<"int   : "<<num<<std::endl;
	f_temp = static_cast<float>(num);
	d_temp = static_cast<double>(num);
	ConverDecimal(d_temp, f_temp);
}

bool ScalarConverter::SpecialCase(const std::string &value)
{
	if (value == "nan" || value == "nanf")
	{
		std::cout<<"char  : impossible\n";
		std::cout<<"int   : impossible\n";
		std::cout<<"float : nanf\n";
		std::cout<<"double: nan\n";
		return true;
	}
	else if (value == "+inf")
	{
		std::cout<<"char  : impossible\n";
		std::cout<<"int   : impossible\n";
		std::cout<<"float : +inff\n";
		std::cout<<"double: +inf\n";
		return true;
	}
	else if (value == "-inf")
	{
		std::cout<<"char  : impossible\n";
		std::cout<<"int   : impossible\n";
		std::cout<<"float : -inff\n";
		std::cout<<"double: -inf\n";
		return true;
	}
	else if (value == "+inff")
	{
		std::cout<<"char  : impossible\n";
		std::cout<<"int   : impossible\n";
		std::cout<<"float : +inff\n";
		std::cout<<"double: +inf\n";
		return true;
	}
	else if (value == "-inff")
	{
		std::cout<<"char  : impossible\n";
		std::cout<<"int   : impossible\n";
		std::cout<<"float : -inff\n";
		std::cout<<"double: -inf\n";
		return true;
	}
	return false;
}

void ScalarConverter::convert(const std::string &value)
{
	int type = DetectType(value);
	char c;
	int num;
	float fnum;
	double dnum;
	
	if (SpecialCase(value))
		return ;
	switch (type)
	{
		case FALSE:
			std::cout<<"Input invalid\n";
			break;
		case CHAR:
			c = ParseChar(value);
			ConverChar(c);
			break;
		case INT:
			try
			{
				num = ParseInt(value);
				ConverInt(num);
			}
			catch(const char *e)
			{
				std::cerr << e;
			}
			break;
		case FLOAT:
			fnum = ParseDouble(value);
			ConverFloat(fnum);
			break;
		case DOUBLE:
			dnum = ParseDouble(value);
			ConverDouble(dnum);
			break;
		}
}