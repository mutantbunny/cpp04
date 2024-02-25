/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:28 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/25 00:47:04 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		std::cout << "Tests from the subject PDF:\n" << std::endl;

		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		std::cout << "\nDeleting pointers, destructors should be called here:\n"
			<< std::endl;

		delete meta;
		delete j;
		delete i;
	}

	{
		std::cout << "\n*****************************************************\n"
			<< std::endl;

		std::cout << "Additional tests for Cat classes:\n" << std::endl;

		Cat firstCat;

		Animal &hiddenCat = firstCat;

		std::cout << "\nhiddenCat is secretly a " << hiddenCat.getType()
			<< "..." << std::endl;
		hiddenCat.makeSound();

		std::cout << "\nTest deep copy:" << std::endl;
		std::cout << "\nFirst idea of firstCat: "
			<< firstCat.getIdea(0) << std::endl;
		std::cout << "Last idea of firstCat: "
			<< firstCat.getIdea(99) << std::endl;

		std::cout << "\nCreate anotherCat as a copy of firstCat using "
			"copy constructor." << std::endl;
		Cat anotherCat(firstCat);
		std::cout << "\nFirst idea of anotherCat: "
			<< anotherCat.getIdea(0) << std::endl;
		std::cout << "Last idea of anotherCat: "
			<< anotherCat.getIdea(99) << std::endl;

		std::cout << "\nCreate yetAnotherCat as a copy of firstCat using "
			"default constructor + assignment operator." << std::endl;
		Cat yetAnotherCat;
		yetAnotherCat = firstCat;
		std::cout << "\nFirst idea of yetAnotherCat: "
			<< yetAnotherCat.getIdea(0) << std::endl;
		std::cout << "Last idea of yetAnotherCat: "
			<< yetAnotherCat.getIdea(99) << std::endl;

		std::cout << "\nChange first idea of firstCat to \"Fish..\""
			<< std::endl;
		firstCat.setIdea(0, "Fish...");

		std::cout << "Change last idea of firstCat to \"Sleep...\""
			<< std::endl;
		firstCat.setIdea(99, "Sleep..");

		std::cout << "\nVerify that only the ideas of firstCat were changed "
			"(each cat's brain should be unique)." << std::endl;

		std::cout << "\nFirst idea of firstCat: "
			<< firstCat.getIdea(0) << std::endl;
		std::cout << "Last idea of firstCat: "
			<< firstCat.getIdea(99) << std::endl;

		std::cout << "\nFirst idea of anotherCat: "
			<< yetAnotherCat.getIdea(0) << std::endl;
		std::cout << "Last idea of anotherCat: "
			<< yetAnotherCat.getIdea(99) << std::endl;

		std::cout << "\nFirst idea of yetAnotherCat: "
			<< yetAnotherCat.getIdea(0) << std::endl;
		std::cout << "Last idea of yetAnotherCat: "
			<< yetAnotherCat.getIdea(99) << std::endl;

		std::cout << "\nEnd of scope, destructors should be called here:\n"
			<< std::endl;
	}

	{
		std::cout << "\n*****************************************************\n"
			<< std::endl;
		std::cout << "Additional tests for Dog classes:\n" << std::endl;

		Dog firstDog;
		Animal &hiddenDog = firstDog;

		std::cout << "\nhiddenDog is secretly a " << hiddenDog.getType()
			<< "..." << std::endl;
		hiddenDog.makeSound();

		std::cout << "\nTest deep copy:" << std::endl;
		std::cout << "\nFirst idea of firstDog: "
			<< firstDog.getIdea(0) << std::endl;
		std::cout << "Last idea of firstDog: "
			<< firstDog.getIdea(99) << std::endl;

		std::cout << "\nCreate anotherDog as a copy of firstDog using "
			"copy constructor." << std::endl;
		Dog anotherDog(firstDog);
		std::cout << "\nFirst idea of anotherDog: "
			<< anotherDog.getIdea(0) << std::endl;
		std::cout << "Last idea of anotherDog: "
			<< anotherDog.getIdea(99) << std::endl;

		std::cout << "\nCreate yetAnotherDog as a copy of firstDog using "
			"default constructor + assignment operator." << std::endl;
		Dog yetAnotherDog;
		yetAnotherDog = firstDog;
		std::cout << "\nFirst idea of yetAnotherDog: "
			<< yetAnotherDog.getIdea(0) << std::endl;
		std::cout << "Last idea of yetAnotherDog: "
			<< yetAnotherDog.getIdea(99) << std::endl;

		std::cout << "\nChange first idea of firstDog to \"Tree...\""
			<< std::endl;
		firstDog.setIdea(0, "Tree...");

		std::cout << "Change last idea of firstDog to \"Mailman...\""
			<< std::endl;
		firstDog.setIdea(99, "Mailman...");

		std::cout << "\nVerify that only the ideas of firstDog were changed "
			"(each dog's brain should be unique)." << std::endl;

		std::cout << "\nFirst idea of firstDog: "
			<< firstDog.getIdea(0) << std::endl;
		std::cout << "Last idea of firstDog: "
			<< firstDog.getIdea(99) << std::endl;

		std::cout << "\nFirst idea of anotherDog: "
			<< yetAnotherDog.getIdea(0) << std::endl;
		std::cout << "Last idea of anotherDog: "
			<< yetAnotherDog.getIdea(99) << std::endl;

		std::cout << "\nFirst idea of yetAnotherDog: "
			<< yetAnotherDog.getIdea(0) << std::endl;
		std::cout << "Last idea of yetAnotherDog: "
			<< yetAnotherDog.getIdea(99) << std::endl;

		std::cout << "\nEnd of scope, destructors should be called here:\n"
			<< std::endl;
	}

	return 0;
}
