/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:14:45 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/26 21:34:14 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base::~Base(){}

Base *generate(void)
{
	static bool seeded = false;
	int base;
	Base *obj;
	
    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
	
	base = std::rand() % 3;

	if (base == 1)
		return (obj = new A());
	else if(base == 2)
		return (obj = new B());
	else
		return (obj = new C());
}

void identify(Base* p) 
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A pointer" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B pointer" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C pointer" << std::endl;
}

void identify(Base& p) {
	try 
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A reference" << std::endl;
		return;
	} catch (...) {}
	try 
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B reference" << std::endl;
		return;
	} catch (...) {}
	try 
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C reference" << std::endl;
		return;
	} catch (...) {}
}