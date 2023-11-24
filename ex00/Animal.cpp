/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:07 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/24 03:05:46 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Generic")
{
	std::cout << "Animal class default constructor called" << std::endl;
}

Animal::Animal(Animal &src): type(src.type)
{
	std::cout << "Animal class copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal class destructor called" << std::endl;
}

Animal &Animal::operator=(Animal &src)
{
	type = src.type;
	return *this;
}

std::string Animal::getType(void) const { return type; }

void Animal::makeSound(void) const
{
	std::cout << "*** Generic animal sounds ***" << std::endl;
}
