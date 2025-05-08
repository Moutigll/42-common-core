/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:00:59 by ele-lean          #+#    #+#             */
/*   Updated: 2025/04/30 15:21:19 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBG_COLORS_HPP
# define DBG_COLORS_HPP

// Constructors
#define DC "\033[38;5;159m" // Default constructor
#define PC "\033[38;5;45m"        // Parameterized constructor
#define CC "\033[38;5;25m"   // Copy constructor

#define D "\033[38;5;93m" // Destructor
#define A "\033[38;5;226m" // Assignment operator

// General
# define RED    "\033[31m"
# define GREEN  "\033[32m"
# define YELLOW "\033[33m"
# define BLUE   "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN   "\033[36m"
# define WHITE  "\033[37m"

#define RST "\033[0m" // Reset color

#endif