/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:21:11 by marvin            #+#    #+#             */
/*   Updated: 2024/07/28 19:21:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class   Bureaucrat;

class   PresidentialPardonForm : public AForm
{
    private :
        const std::string target;

    public :
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &copy);
        ~PresidentialPardonForm();
        std::string GetTarget();

        void    execute(Bureaucrat const &employed) const;
        PresidentialPardonForm(const std::string &target);

};