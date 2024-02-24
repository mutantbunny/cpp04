/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:08:00 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/24 16:06:37 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : name ("Unnamed")
{
	for (int i = 0; i < Character::NUM_SLOTS; ++i)
		slots[i] = NULL;
}

Character::Character(Character &src) : name (src.getName())
{
	for (int i = 0; i < Character::NUM_SLOTS; ++i)
	{
		AMateria *tmp = src.getSlot(i);

		if (tmp != NULL)
			slots[i] = tmp->clone();
		else
			slots[i] = NULL;
	}
}

Character::Character(std::string name) : name (name)
{
	for (int i = 0; i < Character::NUM_SLOTS; ++i)
		slots[i] = NULL;
}

Character::~Character()
{
	for (int i = 0; i < Character::NUM_SLOTS; ++i)
		delete slots[i];
}

Character &Character::operator=(Character &src)
{
	if (this == &src)
		return *this;

	for (int i = 0; i < Character::NUM_SLOTS; ++i)
	{
		delete slots[i];
		AMateria *tmp = src.getSlot(i);

		if (tmp != NULL)
			slots[i] = tmp->clone();
		else
			slots[i] = NULL;
	}

	return *this;
}

std::string const &Character::getName() const { return name; }

AMateria *Character::getSlot(int idx) {

	if (idx < 0 || idx >= Character::NUM_SLOTS || !slots[idx])
		return NULL;

	return slots[idx];
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < Character::NUM_SLOTS; ++i)
	{
		if (slots[i] == NULL)
		{
			slots[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < Character::NUM_SLOTS && slots[idx] != NULL)
	{
		for (int i = idx + 1; i < Character::NUM_SLOTS; ++i)
			slots[i - 1] = slots[i];
		slots[Character::NUM_SLOTS - 1] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < Character::NUM_SLOTS && slots[idx])
		slots[idx]->use(target);
}
