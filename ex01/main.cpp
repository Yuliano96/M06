#include <iostream>
#include "Serializer.hpp"
#include <stdio.h>
#include <stdint.h> // Define uintptr_t

int main() 
{
	
	
	Data *data = new Data[3];
	uintptr_t x;
	Data *temp;
	//datas
	data[0].name = "pepe";
	data[0].age = 25;
	data[0].DNI = 123;

	data[1].name = "pedro";
	data[1].age = 32;
	data[1].DNI = 456;

	data[2].name = "juan";
	data[2].age = 28;
	data[2].DNI = 789;

	Data *aux = data;
	for (int i = 0; i < 3; i++)
	{
		std::cout<<"===============\n";
		std::cout<<"original adress: "<<aux<<std::endl;
		std::cout<<"Name: "<<aux->name<<std::endl;
		std::cout<<"Age: "<<aux->age<<std::endl;
		std::cout<<"DNI: "<<aux->DNI<<std::endl;
		std::cout<<"==================\n";
		x = Serializer::serialize(aux);
		temp = Serializer::deserialize(x);
		std::cout<<"serialize: "<<x<<std::endl;
		std::cout<<"deserialize: "<<temp<<std::endl;
		std::cout<< "Pointers match:   " 
				<< (aux == temp ? "✓ YES" : "✗ NO") << std::endl;
		aux++;
		
	}

	delete [] data;
    return 0;
}