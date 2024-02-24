/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:09:09 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/24 03:28:48 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &src)
{
	for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
	{
		AMateria *tmp = src.getMateria(i);

		if (tmp != NULL)
			materias[i] = tmp->clone();
		else
			materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
		delete materias[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource &src)
{
	if (this == &src)
		return *this;

	for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
	{
		delete materias[i];
		AMateria *tmp = src.getMateria(i);

		if (tmp != NULL)
			materias[i] = tmp->clone();
		else
			materias[i] = NULL;
	}

	return *this;
}

AMateria *MateriaSource::getMateria(int idx)
{
	if (idx < 0 || idx >= MateriaSource::NUM_MATERIAS || !materias[idx])
		return NULL;

	return materias[idx];
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
	{
		if (materias[i] == NULL)
		{
			materias[i] = m;
			return;
		}
	}

	delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
	{
		if (materias[i] != NULL && materias[i]->getType() == type)
			return materias[i]->clone();
	}

	return NULL;
}
