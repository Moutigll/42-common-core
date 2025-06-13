/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:43:57 by ele-lean          #+#    #+#             */
/*   Updated: 2025/06/13 10:46:04 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base {
	public:
		virtual ~Base();
};
#endif

#ifndef A__HPP
# define A__HPP

class A : public Base {
	public:
		~A();
};
#endif

#ifndef B__HPP
# define B__HPP
class B : public Base {
	public:
		~B();
};
#endif

#ifndef C__HPP
# define C__HPP
class C : public Base {
	public:
		~C();
};
#endif
