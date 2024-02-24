/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:44 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/23 02:56:39 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : type("Cat")
{
	std::cout << "WrongCat class default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat &src): WrongAnimal(src)
{
	std::cout << "WrongCat class copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat class destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &src)
{
	std::cout << "WrongCat class assignment operator called" << std::endl;

	if (this == &src)
		return *this;

	type = src.type;
	return *this;
}

std::string WrongCat::getType(void) const { return type; }

void WrongCat::makeSound(void) const
{
	std::cout << "Meow..." << std::endl;
}