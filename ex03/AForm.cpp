/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:55:52 by marvin            #+#    #+#             */
/*   Updated: 2024/07/27 15:55:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("Joe"), grade_exec(50), grade_req(100), sign(false)
{

}

AForm::~AForm() {

}

AForm::AForm(const AForm &copy) : name(copy.GetName()), grade_exec(copy.GetGradeEx()), grade_req(copy.GetGradeReq())
{
    if (GetGradeEx() < 1)
        throw GradeTooHighException();
    else if (GetGradeEx() > 150)
        throw GradeTooLowException();
    if (GetGradeReq() < 1)
        throw GradeTooHighException();
    else if (GetGradeReq() > 150)
        throw GradeTooLowException();
    this->sign = copy.GetSign();
}

AForm& AForm::operator=(const AForm &copy)
{
    if(this != &copy)
        this->sign = copy.sign;
    return *this;
}

AForm::AForm(std::string name, int grade_req, int grade_exec) : name(name), grade_exec(grade_exec), grade_req(grade_req), sign(false)
{
    if (GetGradeEx() < 1)
        throw GradeTooHighException();
    else if (GetGradeEx() > 150)
        throw GradeTooLowException();
    if (GetGradeReq() < 1)
        throw GradeTooHighException();
    else if (GetGradeReq() > 150)
        throw GradeTooLowException();
}

std::string     AForm::GetName() const {
    return this->name;
}

int         AForm::GetGradeEx() const {
    return this->grade_exec;
}

int         AForm::GetGradeReq() const {
    return this->grade_req;
}

bool        AForm::GetSign() const {
    return  this->sign;
}

std::ostream& operator <<(std::ostream &os, const AForm &doc) 
{
	os << doc.GetName() << ", Form grade to sign : " << doc.GetGradeReq() << ", Form grade to execute " << doc.GetGradeEx() << ", Signed: " << doc.GetSign();
	return (os);
}

void    AForm::execute(Bureaucrat const &employed) const
{
    if(employed.GetGrade() > this->GetGradeEx())
		throw GradeTooLowException();
}

void        AForm::beSigned(const Bureaucrat &employed)
{
    if (employed.GetGrade() > GetGradeReq())
        throw GradeTooLowException();
    else
        this->sign = true;
}