/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:48:14 by marvin            #+#    #+#             */
/*   Updated: 2024/07/25 15:48:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main() {
    try {
        Bureaucrat john("John", 70);
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Wall-e");
        PresidentialPardonForm pardon("Athur");

        john.signForm(shrubbery);
        john.signForm(robotomy);
        john.signForm(pardon);

        john.executeForm(shrubbery);
        john.executeForm(robotomy);
        john.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
