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
#include "Form.hpp"

int main (void)
{
    try
    {
        Bureaucrat john("John Doe", 42);
        std::cout << john << std::endl;
        Form    formA("FormA", 40, 20);
        
        std::cout << formA << std::endl;

        john.signForm(formA);

        std::cout << formA << std::endl;

        Bureaucrat Jane("Jane", 1);
        std::cout << Jane << std::endl;

        Form    formB("formB", 120, 150);
        std::cout << formB << std::endl;

        Jane.signForm(formB);

        std::cout << formB << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}