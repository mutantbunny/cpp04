/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:22 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/24 03:34:58 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	protected:
		std::string type;

	public:
		Cat(void);
		Cat(Cat &src);

		virtual ~Cat(void);

		Cat &operator=(Cat &src);

		virtual std::string getType(void) const;
		virtual void makeSound(void) const;
};

#endif
