/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 03:15:01 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/24 16:18:41 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		static const int NUM_SLOTS = 4;

		Character(void);
		Character(Character &src);
		Character(std::string name);

		virtual ~Character();

		Character &operator=(Character &src);

		AMateria *getSlot(int idx);
		virtual std::string const &getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

		private:
			std::string name;
			AMateria *slots[NUM_SLOTS];
};

#endif
