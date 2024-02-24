/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:26 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/23 02:11:47 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain *brain;

public:
		Dog(void);
		Dog(Dog &src);

		virtual ~Dog(void);

		Dog &operator=(Dog &src);

		virtual std::string getType(void) const;
		virtual void makeSound(void) const;
		std::string getIdea(const size_t idx) const;
		void setIdea(size_t idx, std::string idea);
};

#endif
