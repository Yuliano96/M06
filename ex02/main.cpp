/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 21:59:55 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/26 21:35:22 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"


int main() 
{
	Base* obj;
	for (int i = 0; i < 5; i++) 
	{
		obj = generate();
		identify(obj);
		identify(*obj);
		delete obj;
		std::cout << std::endl;
	}
}