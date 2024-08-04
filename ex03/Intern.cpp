/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <ogregoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:13:05 by ogregoir          #+#    #+#             */
/*   Updated: 2024/08/05 01:38:50 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    form[0] = "presidential pardon";
    form[1] = "robotomy request";
    form[2] = "shrubbery creation";
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern &copy)
{
    (void)copy;
    return *this;   
}

Intern::Intern(const Intern &copy)
{
    *this = copy;
    form[0] = "presidential pardon";
    form[1] = "robotomy request";
    form[2] = "shrubbery creation";
}

AForm*    Intern::makePresidentialPardonForm(std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm   *Intern::makeRobotomyRequestForm(std::string &target)
{
    return (new RobotomyRequestForm(target));
}

AForm   *Intern::makeShrubberyCreationForm(std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

AForm    *Intern::makeForm(std::string form, std::string &target)
{
    int i = 0;
    
    typedef AForm* (Intern::*FormMaker)(std::string &target);
    FormMaker formMakers[] = {
        &Intern::makePresidentialPardonForm,
        &Intern::makeRobotomyRequestForm,
        &Intern::makeShrubberyCreationForm
    };
    
    while(i != 3)
    {
        if (this->form[i].compare(form) == 0)
        {
            std::cout << "The intern creates the form : " << form << std::endl;
            return (this->*formMakers[i])(target);
        }
        i++;
    }
    std::cout << "The form does not exist" << std::endl;
    return NULL;
}
