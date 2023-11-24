/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:20 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/24 03:39:16 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : type("Cat")
{
	std::cout << "Cat class default constructor called" << std::endl;
}

Cat::Cat(Cat &src): Animal(src)
{
	std::cout << "Cat class copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat class destructor called" << std::endl;
}

Cat &Cat::operator=(Cat &src)
{
	type = src.type;
	return *this;
}

std::string Cat::getType(void) const { return type; }

void Cat::makeSound(void) const
{
	std::cout << "Meow..." << std::endl;
}