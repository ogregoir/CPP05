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
#include "Intern.hpp"

int main() {
    Intern intern;
    Bureaucrat employed("Joe", 1);
    std::string target = "Bender";

    AForm* form1 = intern.makeForm("robotomy request", target);
    if (form1) {
        form1->execute(employed);
        delete form1;
    }

    AForm* form2 = intern.makeForm("presidential pardon", target);
    if (form2) {
        form2->execute(employed);
        delete form2;
    }

    AForm* form3 = intern.makeForm("shrubbery creation", target);
    if (form3) {
        form3->execute(employed);
        delete form3;
    }

    AForm* form4 = intern.makeForm("unknown form", target);
    if (form4) {
        delete form4;
    }

    return 0;
}
