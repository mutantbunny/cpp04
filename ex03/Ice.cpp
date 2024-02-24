/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:42:41 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/23 21:07:47 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") { }

Ice::Ice(const Ice &src) : AMateria(src.getType()) { }

Ice::Ice(std::string const & type) : AMateria(type) { }

Ice::~Ice(void) { }

Ice &Ice::operator=(const Ice &src)
{
	if (this == &src)
		return *this;

	type = src.getType();

	return *this;
}

Ice* Ice::clone() const { return new Ice(*this); }

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName()
		<< " *" << std::endl;
}
