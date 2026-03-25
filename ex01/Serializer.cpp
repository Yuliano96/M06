/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 22:13:16 by yuliano           #+#    #+#             */
/*   Updated: 2026/03/25 20:25:29 by yuliano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t resul;
	
	resul = reinterpret_cast<uintptr_t>(ptr);
	return (resul);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *resul;
	
	resul = reinterpret_cast<Data *>(raw);
	return (resul);
}
