/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Derived.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloe <chloe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:33:00 by chloe             #+#    #+#             */
/*   Updated: 2025/06/18 16:59:11 by chloe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DERIVED_HPP
#define DERIVED_HPP

#include "Base.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif
