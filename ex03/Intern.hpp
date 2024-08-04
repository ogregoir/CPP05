/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:13:10 by ogregoir          #+#    #+#             */
/*   Updated: 2024/08/05 01:27:03 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
private:
    std::string form[3];
    AForm *makePresidentialPardonForm(std::string &target);
    AForm *makeRobotomyRequestForm(std::string &target);
    AForm *makeShrubberyCreationForm(std::string &target);
    
public:
    Intern();
    Intern &operator=(const Intern &copy);
    Intern(const Intern &copy);
    ~Intern();
    AForm *makeForm(std::string form, std::string &target);
};


