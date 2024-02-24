/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:39 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/23 02:56:18 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Generic animal")
{
	std::cout << "Animal class default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &src): type(src.type)
{
	std::cout << "Animal class copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Animal class destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &src)
{
	std::cout << "WrongAnimal class assignment operator called" << std::endl;

	if (this == &src)
		return *this;

	type = src.type;
	return *this;
}

std::string WrongAnimal::getType(void) const { return type; }

void WrongAnimal::makeSound(void) const
{
	std::cout << "*** Generic animal sounds ***" << std::endl;
}