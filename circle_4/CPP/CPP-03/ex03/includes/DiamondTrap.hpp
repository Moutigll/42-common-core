/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 10:17:02 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/30 11:51:06 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
    public:
        DiamondTrap(void);
        DiamondTrap(std::string const &name);
        DiamondTrap(DiamondTrap const &copy);
        ~DiamondTrap(void);

        DiamondTrap	&operator=(DiamondTrap const &copy);

        void	whoAmI(void);
        void	attack(std::string const &target);
        
    private:
        std::string _name;
};

#endif