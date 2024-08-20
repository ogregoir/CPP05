/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:07:30 by marvin            #+#    #+#             */
/*   Updated: 2024/07/22 13:07:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <cctype>
# include <iostream>
# include <exception>
# include <stdlib.h>
# include "AForm.hpp"

class AForm;

class Bureaucrat 
{
	private :
		const std::string	name;
		int					grade;

	public :

		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat&		operator=(const Bureaucrat &copy);
		~Bureaucrat();

		Bureaucrat(std::string name, int grade);

		class GradeTooHighException : public std::exception
		{
			public :
				const char * what() const throw() {
					return "Grade too high!";
				}
		};
		
		class GradeTooLowException : public std::exception
		{
			public :
				const char * what() const throw() {
					return "Grade too low!";
				}
		};

		std::string			GetName() const;
		int					GetGrade() const;
		void				downGrade();
		void				upGrade();

		void 				executeForm(AForm const &form);
		void				signForm(AForm &form) const;

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &employed);