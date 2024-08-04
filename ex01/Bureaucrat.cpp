/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 03:18:12 by marvin            #+#    #+#             */
/*   Updated: 2024/08/04 03:18:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 03:18:04 by marvin            #+#    #+#             */
/*   Updated: 2024/08/04 03:18:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:06:56 by marvin            #+#    #+#             */
/*   Updated: 2024/07/22 13:06:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("John Doe"), grade(150) {
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name)
{
	if(this != &copy)
		this->grade = copy.grade;
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &copy)
{
	if(&copy != this)
		this->grade = copy.grade;
	return (*this);
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

std::string	 Bureaucrat::GetName(void) const {
	return	this->name;
}

int			Bureaucrat::GetGrade(void) const {
	return this->grade;
}

void		Bureaucrat::upGrade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	else
		grade--;
}

void		Bureaucrat::downGrade()
{
	if(grade + 1 > 150)
		throw GradeTooLowException();  
	else
		grade++;
}

void	Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->GetName() << " signed " << form.GetName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->GetName() << "  couldn't sign " << form.GetName() << std::endl;
	}
}

std::ostream& operator <<(std::ostream &os, const Bureaucrat &employed) 
{
	os << employed.GetName() << ", bureaucrat grade" << employed.GetGrade();
	return (os);
}