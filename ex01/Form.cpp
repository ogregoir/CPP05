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

#include "Form.hpp"

Form::Form() : name("Joe"), grade_exec(50), grade_req(100), sign(false)
{

}

Form::~Form() {

}

Form::Form(const AForm &copy) : name(copy.GetName()), grade_exec(copy.GetGradeEx()), grade_req(copy.GetGradeReq())
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

Form& Form::operator=(const Form &copy)
{
    if(this != &copy)
        this->sign = copy.sign;
    return *this;
}

Form::Form(std::string name, int grade_req, int grade_exec) : name(name), grade_exec(grade_exec), grade_req(grade_req), sign(false)
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

std::string     Form::GetName() const {
    return this->name;
}

int         Form::GetGradeEx() const {
    return this->grade_exec;
}

int         Form::GetGradeReq() const {
    return this->grade_req;
}

bool        Form::GetSign() const {
    return  this->sign;
}

std::ostream& operator <<(std::ostream &os, const AForm &doc) 
{
	os << doc.GetName() << ", Form grade to sign : " << doc.GetGradeReq() << ", Form grade to execute " << doc.GetGradeEx() << ", Signed: " << doc.GetSign();
	return (os);
}

void        Form::beSigned(const Bureaucrat &employed)
{
    if (employed.GetGrade() > GetGradeReq())
        throw GradeTooLowException();
    else
        this->sign = true;
}