/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 03:12:42 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/23 21:01:33 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	protected:

	public:
		Ice(void);
		Ice(const Ice &src);
		Ice(std::string const & type);

		~Ice(void);

		Ice &operator=(const Ice &src);

		virtual Ice* clone() const;
		virtual void use(ICharacter& target);
};

#endif
