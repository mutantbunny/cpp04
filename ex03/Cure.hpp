/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 03:12:42 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/23 21:05:40 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	protected:

	public:

		Cure(void);
		Cure(const Cure &src);
		Cure(std::string const & type);

		~Cure(void);

		Cure &operator=(const Cure &src);

		virtual Cure* clone() const;
		virtual void use(ICharacter& target);
};

#endif
