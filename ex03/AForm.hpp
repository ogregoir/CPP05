/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:41:29 by marvin            #+#    #+#             */
/*   Updated: 2024/07/25 16:41:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h> 

class Bureaucrat;

class AForm
{
	private : 
		const std::string	name;
		const int			grade_exec;
		const int			grade_req;
		bool				sign;
	
	public :

		AForm();
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		virtual ~AForm();

		AForm(std::string name, int grade_req, int grade_exec);

		class GradeTooHighException : public std::exception
		{
			public :
				const char * what() const throw() {
					return "Grade too high for sign form!";
				}
		};
		
		class GradeTooLowException : public std::exception
		{
			public :
				const char * what() const throw() {
					return "Grade too low for sign form!";
				}
		};

		std::string	GetName() const ;
		int			GetGradeEx() const ;
		int			GetGradeReq() const ;
		bool		GetSign() const ;

		virtual void 		execute(Bureaucrat const &executor) const = 0;
		virtual void		beSigned(const Bureaucrat &employed);
};

std::ostream &operator<<(std::ostream &os, const AForm &doc);

