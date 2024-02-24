/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:20 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/23 02:58:01 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	type= "Cat";
	brain = new Brain;
	for (size_t i = 0; i < 100; ++i)
		brain->setIdea(i, "Catnip...");
	std::cout << "Cat class default constructor called" << std::endl;
}

Cat::Cat(Cat &src): Animal(src)
{
	brain = new Brain;
	for (size_t i = 0; i < 100; ++i)
		brain->setIdea(i, src.getIdea(i));
	std::cout << "Cat class copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat class destructor called" << std::endl;
	delete brain;
}

Cat &Cat::operator=(Cat &src)
{
	std::cout << "Cat class assignment operator called" << std::endl;

	if (this == &src)
		return *this;

	for (size_t i = 0; i < 100; ++i)
		brain->setIdea(i, src.getIdea(i));

	type = src.type;
	return *this;
}

std::string Cat::getType(void) const { return type; }

void Cat::makeSound(void) const
{
	std::cout << "Meow..." << std::endl;
}

std::string Cat::getIdea(const size_t idx) const
{
	return brain->getIdea(idx);
}

void Cat::setIdea(size_t idx, std::string idea)
{
	brain->setIdea(idx, idea);
}
