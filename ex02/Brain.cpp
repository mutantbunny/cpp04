/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:45:37 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/23 02:58:02 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain class default constructor called" << std::endl;
}

Brain::Brain(Brain &src)
{
	std::cout << "Brain class copy constructor called" << std::endl;

	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain class destructor called" << std::endl;
}

Brain &Brain::operator=(Brain &src)
{
	std::cout << "Brain class assignment operator called" << std::endl;

	if (this == &src)
		return (*this);

	for (size_t i = 0; i < 100; ++i)
		ideas[i] = src.getIdea(i);

	return (*this);
}

std::string Brain::getIdea(size_t idx)
{
	if (idx < 100)
		return ideas[idx];
	std::cerr << "This brain cannot store so many ideas" << std::endl;
	return "";
}
void Brain::setIdea(size_t idx, std::string idea)
{
	if (idx < 100)
		ideas[idx] = idea;
	else
		std::cerr << "This brain cannot store so many ideas" << std::endl;
}
