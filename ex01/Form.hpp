/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:41:29 by marvin            #+#    #+#             */
/*   Updated: 2024/07/25 16:41:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private : 
		const std::string	name;
		const int			grade_exec;
		const int			grade_req;
		bool				sign;
	
	public :

		Form();
		Form(const AForm &copy);
		Form &operator=(const Form &copy);
		~Form();

		Form(std::string name, int grade_req, int grade_exec);

		class GradeTooHighException : public std::exception
		{
			public :
				const char * what() const throw() {
					return "Grade too high for sign AForm!";
				}
		};
		
		class GradeTooLowException : public std::exception
		{
			public :
				const char * what() const throw() {
					return "Grade too low for sign AForm!";
				}
		};

		std::string	GetName() const ;
		int			GetGradeEx() const ;
		int			GetGradeReq() const ;
		bool		GetSign() const ;

		void		beSigned(const Bureaucrat &employed);
};

std::ostream &operator <<(std::ostream &os, const AForm &doc);

