/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:19:59 by marvin            #+#    #+#             */
/*   Updated: 2024/07/28 19:19:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Joe")
{
}
		
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

void    RobotomyRequestForm::execute(Bureaucrat const &employed) const
{
	if(employed.GetGrade() > this->GetGradeEx())
		throw GradeTooLowException();
	int count = 0;
	srand(time(NULL));
	count = std::rand();
	std::cout << "BRzzzzzzZ............" << std::endl;
	if((count % 2) == 0)
	{
		std::cout << target << " has been robotomized" << std::endl;
	}
	else
		std::cout << target << " hasn't been robotomized" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy){
	this->sign = copy.GetSign();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy){
	if(this != &copy)
		this->sign = copy.sign;
	return *this;
}

std::string		RobotomyRequestForm::GetTarget(){
    return this->target;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	
}