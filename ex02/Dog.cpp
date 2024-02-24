/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:24 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/23 02:58:20 by gmachado         ###   ########.fr       */
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
	brain = new Brain;

	for (size_t i = 0; i < 100; ++i)
		brain->setIdea(i, "Food...");

	std::cout << "Dog class default constructor called" << std::endl;
}

Dog::Dog(Dog &src): Animal(src)
{
	std::cout << "Dog class copy constructor called" << std::endl;
	brain = new Brain;

	for (size_t i = 0; i < 100; ++i)
		brain->setIdea(i, src.getIdea(i));
}

Dog::~Dog(void)
{
	std::cout << "Dog class destructor called" << std::endl;
	delete brain;
}

Dog &Dog::operator=(Dog &src)
{
	std::cout << "Dog class assignment operator called" << std::endl;

	if (this == &src)
		return *this;

	for (size_t i = 0; i < 100; ++i)
		brain->setIdea(i, src.getIdea(i));

	type = src.type;
	return *this;
}

std::string Dog::getType(void) const { return type; }

void Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}

std::string Dog::getIdea(const size_t idx) const
{
	return brain->getIdea(idx);
}

void Dog::setIdea(size_t idx, std::string idea)
{
	brain->setIdea(idx, idea);
}
