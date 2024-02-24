/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 04:16:45 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/24 18:23:05 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE
# define MATERIA_SOURCE

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		static const int NUM_MATERIAS = 4;

		MateriaSource(void);
		MateriaSource(MateriaSource &src);

		virtual ~MateriaSource();

		MateriaSource &operator=(MateriaSource &src);

		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);
		AMateria *getMateria(int idx);

	private:
		AMateria *materias[NUM_MATERIAS];

};

#endif