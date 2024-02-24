/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:42:41 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/23 20:57:12 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") { }

Cure::Cure(const Cure &src) : AMateria(src.getType()) { }

Cure::Cure(std::string const & type) : AMateria(type) { }

Cure::~Cure(void) { }

Cure &Cure::operator=(const Cure &src)
{
	if (this == &src)
		return *this;

	type = src.getType();

	return *this;
}

Cure* Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
