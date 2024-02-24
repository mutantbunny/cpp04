/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:37:22 by gmachado          #+#    #+#             */
/*   Updated: 2024/02/23 02:13:08 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain *brain;

	public:
		Cat(void);
		Cat(Cat &src);

		virtual ~Cat(void);

		Cat &operator=(Cat &src);

		virtual std::string getType(void) const;
		virtual void makeSound(void) const;
		std::string getIdea(const size_t idx) const;
		void setIdea(size_t idx, std::string idea);
};

#endif
