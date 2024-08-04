/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:19:49 by marvin            #+#    #+#             */
/*   Updated: 2024/07/28 19:19:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Joe")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    (void)copy;
    return *this;
}

void    ShrubberyCreationForm::execute(Bureaucrat const &employed) const
{
    if(employed.GetGrade() > this->GetGradeEx())
		throw GradeTooLowException();
    std::string files;
    files = target + "_shrubbery";
    std::ofstream outputFile(files.c_str());
    outputFile << "      *" << std::endl;
    outputFile << "     ***" << std::endl;
    outputFile << "    *****" << std::endl;
    outputFile << "   *******" << std::endl;
    outputFile << "  *********" << std::endl;
    outputFile << " ***********" << std::endl;
    outputFile << "**************" << std::endl;
    outputFile << "     |  |     " << std::endl;
    std::cout << "The big tree is created" << std::endl;
}

std::string     ShrubberyCreationForm::GetTarget(){
    return this->target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
