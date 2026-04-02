/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:11:30 by etorun            #+#    #+#             */
/*   Updated: 2026/04/02 18:19:17 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern acemi;
		Bureaucrat ali("Ali",1);
		AForm* pardonform = acemi.makeForm("PresidentialPardonForm","osman");
		AForm* roboform = acemi.makeForm("RobotomyRequestForm","hasan");
		AForm* treeform = acemi.makeForm("ShrubberyCreationForm","ev");
		ali.signForm(*pardonform);
		ali.signForm(*roboform);
		ali.signForm(*treeform);
		ali.executeForm(*pardonform);
		ali.executeForm(*roboform);
		ali.executeForm(*treeform);
		delete(pardonform);
		delete(roboform);
		delete(treeform);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}