/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:24 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/23 02:55:58 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:20 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/24 03:10:39 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)  : Animal()
{
	type= "Dog";
	std::cout << "Dog class default constructor called" << std::endl;
}

Dog::Dog(Dog &src): Animal(src)
{
	std::cout << "Dog class copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog class destructor called" << std::endl;
}

Dog &Dog::operator=(Dog &src)
{
	std::cout << "Dog class assignment operator called" << std::endl;

	if (this == &src)
		return *this;

	type = src.type;
	return *this;
}

std::string Dog::getType(void) const { return type; }

void Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}
