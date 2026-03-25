/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:57:12 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/24 22:34:08 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h> // Define uintptr_t
#include "Data.h"
#include <stdlib.h>

class Serializer
{
	private:
	
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();

	public :
	
	//It takes a pointer and converts it to the unsigned integer type uintptr_t.
	static uintptr_t serialize(Data *ptr);
	//It takes an unsigned integer parameter and converts it to a pointer to Data
	static Data *deserialize(uintptr_t raw);
	
};

#endif