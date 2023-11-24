/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:26 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/24 03:34:24 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	protected:
		std::string type;

	public:
		Dog(void);
		Dog(Dog &src);

		virtual ~Dog(void);

		Dog &operator=(Dog &src);

		virtual std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif
