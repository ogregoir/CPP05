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

int main (void)
{
    try
        {
            Bureaucrat john("John Doe", 2);
            std::cout << john << std::endl;
            john.upGrade();
            std::cout << "After upgrade: " << john << std::endl;
            john.upGrade();
        }
        catch (const Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try
        {
            Bureaucrat jane("Jane Doe", 149);
            std::cout << jane << std::endl;
            jane.downGrade();
            std::cout << "After downgrade: " << jane << std::endl;
            jane.downGrade();
        }
        catch (const Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try
        {
            Bureaucrat invalid("Invalid Bureaucrat", 0);
        }
        catch (const Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try
        {
            Bureaucrat invalid("Invalid Bureaucrat", 151);
        }
        catch (const Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        return 0;
}