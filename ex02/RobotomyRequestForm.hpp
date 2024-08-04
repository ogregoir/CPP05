/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:19:55 by marvin            #+#    #+#             */
/*   Updated: 2024/07/28 19:19:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private :
        const std::string   target;

    public :
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &copy);
        ~RobotomyRequestForm();
        void    execute(Bureaucrat const &employed) const;
        std::string GetTarget();
        RobotomyRequestForm(const std::string &target);
};