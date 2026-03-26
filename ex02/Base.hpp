/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:56:02 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/26 21:32:40 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
class Base
{
	public:
	virtual ~Base();
};

class A:public Base {};
class B:public Base {};
class C:public Base {};

Base *generate(void);
void identify(Base* p);
void identify(Base& p);
#endif