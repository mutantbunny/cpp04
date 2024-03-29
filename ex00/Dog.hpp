/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:26 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/25 04:17:44 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		Dog(Dog &src);

		virtual ~Dog(void);

		Dog &operator=(Dog &src);

		virtual std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif
