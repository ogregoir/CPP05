/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:21:25 by marvin            #+#    #+#             */
/*   Updated: 2024/07/28 19:21:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Joe")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy){
    this->sign = copy.GetSign();
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy){
	if(this != &copy)
		this->sign = copy.sign;
	return *this;
}

std::string  PresidentialPardonForm::GetTarget(){
    return this->target;
}

void    PresidentialPardonForm::execute(Bureaucrat const &employed) const
{
    if(employed.GetGrade() > this->GetGradeEx())
		throw GradeTooLowException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	
}