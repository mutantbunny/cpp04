/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:28 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/24 17:41:33 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

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
		std::cout << "\nAdditional tests for Cat, Dog and Animal classes:\n"
			<< std::endl;

		Cat cat;
		Dog dog;

		Animal &hiddenCat = cat;
		Animal &hiddenDog = dog;

		std::cout << "\nhiddenCat is secretly a " << hiddenCat.getType()
			<< "..." << std::endl;
		hiddenCat.makeSound();

		std::cout << "\nhiddenDog is secretly a " << hiddenDog.getType()
			<< "..." << std::endl;
		hiddenDog.makeSound();

		std::cout << "\nEnd of scope, destructors should be called here:\n"
			<< std::endl;
	}

	{
		std::cout << "\nTests with WrongCat and WrongAnimal classes (with "
			"methods implemented without the virtual specifier on purpose):\n"
			<< std::endl;

		WrongCat wrongCat;
		WrongAnimal &wrongAnimal = wrongCat;

		std::cout << "\nwrongCat is a "<< wrongCat.getType() << "..." << std::endl;
		wrongCat.makeSound();

		std::cout << "\nwrongAnimal is a "<< wrongAnimal.getType() << "..." << std::endl;
		wrongAnimal.makeSound();

		std::cout << "\nEnd of scope, destructors should be called here:\n" << std::endl;
	}

	return 0;
}