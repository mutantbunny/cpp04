/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:46 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/24 03:22:55 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongCat(void);
		WrongCat(WrongCat &src);

		~WrongCat(void);

		WrongCat &operator=(WrongCat &src);

		std::string getType(void) const;
		void makeSound(void) const;
};

#endif
