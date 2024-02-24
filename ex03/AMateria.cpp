/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:49:59 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/24 02:54:33 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) { }

AMateria::AMateria(AMateria &src) { (void)src; }

AMateria::AMateria(std::string const & type) : type(type) { }

AMateria::~AMateria(void) { }

AMateria &AMateria::operator=(AMateria &src)
{
	(void)src;
	return *this;
}

std::string const &AMateria::getType() const { return type; }

void AMateria::use(ICharacter& target) { (void)target; }
