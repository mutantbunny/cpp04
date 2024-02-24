/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:36:42 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/24 19:08:10 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	{
		std::cout << "Test: Run the subject PDF sample code:\n" << std::endl;

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;

		std::cout << "\nEnd of the subject PDF sample code.\n" << std::endl;
	}

	{
		std::cout << "Test: Learn " << Character::NUM_SLOTS + 2 << " materias "
			"(MateriaSource can only store the first "
			 << Character::NUM_SLOTS
			 << ", but there should not be any memory leak):" << std::endl;

		IMateriaSource* src = new MateriaSource();
		for (int i = 0; i < Character::NUM_SLOTS + 1; ++i)
		{
			std::cout << "-> Try to learn ice." << std::endl;
			src->learnMateria(new Ice());
			std::cout << "-> Try to learn cure." << std::endl;
			src->learnMateria(new Cure());
		}

		std::cout << "\nEnd of MateriaSource learning tests.\n" << std::endl;

		std::cout << "Test: Create materias: \"\", \"ice\", \"cure\" and "
			"\"fire\" (\"fire\" does not exist):" << std::endl;

		AMateria * tmp = src->createMateria("");
		if (tmp)
			std::cout << "-> Created " << tmp->getType() << '.' << std::endl;
		else
			std::cout << "-> Could not create materia."<< std::endl;
		delete tmp;

		tmp = src->createMateria("ice");
		if (tmp)
			std::cout << "-> Created " << tmp->getType() << '.' << std::endl;
		else
			std::cout << "-> Could not create materia."<< std::endl;
		delete tmp;

		tmp = src->createMateria("cure");
		if (tmp)
			std::cout << "-> Created " << tmp->getType() << '.' << std::endl;
		else
			std::cout << "-> Could not create materia."<< std::endl;
		delete tmp;

		tmp = src->createMateria("fire");
		if (tmp)
			std::cout << "-> Created " << tmp->getType() << '.' << std::endl;
		else
			std::cout << "-> Could not create materia."<< std::endl;
		delete tmp;

		delete src;
		std::cout << "\nEnd of MateriaSource creation tests.\n" << std::endl;
	}
	{
		std::cout << "Test: Equip " << Character::NUM_SLOTS
			<< " materias (Character can only store the "
			"first 4, but there should not be any memory leak):" << std::endl;

		Character joe("Joe");
		Character unnamed;

		for (int i = 0; i < Character::NUM_SLOTS - 1; ++i)
		{
			std::cout << "-> Try to equip ice." << std::endl;
			joe.equip(new Ice());
		}


		for (int i = Character::NUM_SLOTS - 1;
			i < Character::NUM_SLOTS + 2; ++i)
		{
			std::cout << "-> Try to equip cure." << std::endl;
			AMateria *tmp = new Cure();
			joe.equip(tmp);

			if (i >= Character::NUM_SLOTS)
				delete tmp;
		}

		std::cout << "\n-> Try to use materias from index -1 to "
			<< Character::NUM_SLOTS
			<< ". There should be no output for indices -1 and 4:" << std::endl;

		for (int i = -1; i <= Character::NUM_SLOTS; ++i)
		{
			std::cout << "-->" << joe.getName() << " used equiped materia #"
				<< i << " on unnamed character: \n--> ";
			joe.use(i, unnamed);
			std::cout << std::endl;
		}
		std::cout << "\nEnd of equipped materia tests.\n" << std::endl;
		std::cout << "Test: Try to unequip materias from index -1 to "
			<< Character::NUM_SLOTS
			<<" twice. There should not be any memory leak:" << std::endl;

		for (int i = -1; i <= Character::NUM_SLOTS; ++i)
		{
			std::cout << "-> Try to unequip slot #" << i << '.' << std::endl;
			AMateria *tmp = joe.getSlot(i);
			joe.unequip(i);
			delete tmp;
		}

		std::cout << std::endl;

		for (int i = -1; i <= Character::NUM_SLOTS; ++i)
		{
			std::cout << "-> Try to unequip slot #" << i << '.' << std::endl;
			AMateria *tmp = joe.getSlot(i);
			joe.unequip(i);
			delete tmp;
		}
		std::cout << "\nEnd of unequip tests.\n" << std::endl;
	}
	{
		std::cout << "Test: MateriaSource Copies should be deep:" << std::endl;

		std::cout << "-> src1 learns ice." << std::endl;
		MateriaSource src1;
		src1.learnMateria(new Ice());

		std::cout << "\n-> List src1's materias:" << std::endl;
		for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
		{
			AMateria *m = src1.getMateria(i);
			if (m != NULL)
				std::cout << "--> #" << i << ": " << m->getType()<< std::endl;
			else
				std::cout << "--> #" << i << ": None" << std::endl;
		}

		std::cout << "-> src2 learns cure." << std::endl;

		MateriaSource src2;
		src2.learnMateria(new Cure());

		std::cout << "\n->List src2's materias:" << std::endl;
		for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
		{
			AMateria *m = src2.getMateria(i);
			if (m != NULL)
				std::cout << "--> #" << i << ": " << m->getType() << std::endl;
			else
				std::cout << "--> #" << i << ": None" << std::endl;
		}

		std::cout << "-> Create src3 from src1 using copy constructor."
			<< std::endl;

		MateriaSource src3(src1);

		std::cout << "\n-> List src3's materias:" << std::endl;
		for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
		{
			AMateria *m = src3.getMateria(i);
			if (m != NULL)
				std::cout << "--> #" << i << ": " << m->getType()<< std::endl;
			else
				std::cout << "--> #" << i << ": None" << std::endl;
		}

		std::cout << "-> Copy src2 from src1 using assignment operator."
			<< std::endl;
		src2 = src1;
		std::cout << "-> src1 learns cure." << std::endl;
		src1.learnMateria(new Cure());

		std::cout << "\n-> List src1's materias:" << std::endl;
		for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
		{
			AMateria *m = src1.getMateria(i);
			if (m != NULL)
				std::cout << "--> #" << i << ": " << m->getType()<< std::endl;
			else
				std::cout << "--> #" << i << ": None" << std::endl;
		}

		std::cout << "\n->List src2's materias:" << std::endl;
		for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
		{
			AMateria *m = src2.getMateria(i);
			if (m != NULL)
				std::cout << "--> #" << i << ": " << m->getType() << std::endl;
			else
				std::cout << "--> #" << i << ": None" << std::endl;
		}

		std::cout << "\n->List src3's materias:" << std::endl;
		for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
		{
			AMateria *m = src2.getMateria(i);
			if (m != NULL)
				std::cout << "--> #" << i << ": " << m->getType() << std::endl;
			else
				std::cout << "--> #" << i << ": None" << std::endl;
		}

		std::cout << "\nEnd of MateriaSource deep copy tests.\n" << std::endl;
	}
	{
		std::cout << "Test: Character Copies should be deep:" << std::endl;

		std::cout << "-> c1 equips ice." << std::endl;
		Character c1;
		c1.equip(new Ice());

		std::cout << "\n-> List c1's materias:" << std::endl;
		for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
		{
			AMateria *m = c1.getSlot(i);
			if (m != NULL)
				std::cout << "--> #" << i << ": " << m->getType()<< std::endl;
			else
				std::cout << "--> #" << i << ": None" << std::endl;
		}

		std::cout << "-> c2 equips cure." << std::endl;

		Character c2;
		c2.equip(new Cure());

		std::cout << "\n->List c2's materias:" << std::endl;
		for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
		{
			AMateria *m = c2.getSlot(i);
			if (m != NULL)
				std::cout << "--> #" << i << ": " << m->getType() << std::endl;
			else
				std::cout << "--> #" << i << ": None" << std::endl;
		}

		std::cout << "-> Create c3 from src1 using copy constructor."
			<< std::endl;

		Character c3(c1);

		std::cout << "\n-> List c3's materias:" << std::endl;
		for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
		{
			AMateria *m = c3.getSlot(i);
			if (m != NULL)
				std::cout << "--> #" << i << ": " << m->getType()<< std::endl;
			else
				std::cout << "--> #" << i << ": None" << std::endl;
		}

		std::cout << "-> Copy c2 from c1 using assignment operator."
			<< std::endl;
		c2 = c1;
		std::cout << "-> src1 equips cure." << std::endl;
		c1.equip(new Cure());

		std::cout << "\n-> List c1's materias:" << std::endl;
		for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
		{
			AMateria *m = c1.getSlot(i);
			if (m != NULL)
				std::cout << "--> #" << i << ": " << m->getType()<< std::endl;
			else
				std::cout << "--> #" << i << ": None" << std::endl;
		}

		std::cout << "\n->List c2's materias:" << std::endl;
		for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
		{
			AMateria *m = c2.getSlot(i);
			if (m != NULL)
				std::cout << "--> #" << i << ": " << m->getType() << std::endl;
			else
				std::cout << "--> #" << i << ": None" << std::endl;
		}

		std::cout << "\n->List c3's materias:" << std::endl;
		for (int i = 0; i < MateriaSource::NUM_MATERIAS; ++i)
		{
			AMateria *m = c2.getSlot(i);
			if (m != NULL)
				std::cout << "--> #" << i << ": " << m->getType() << std::endl;
			else
				std::cout << "--> #" << i << ": None" << std::endl;
		}

		std::cout << "\nEnd of Character deep copy tests.\n" << std::endl;
	}

	return 0;
}
