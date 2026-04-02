/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 16:26:14 by etorun            #+#    #+#             */
/*   Updated: 2026/04/02 17:41:09 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){};

Intern::Intern(const Intern &sample) {(void)sample;}

Intern& Intern::operator=(const Intern &copy)
{
	(void)copy;
	return *this;
}

Intern::~Intern(){};

AForm* Intern::presidentialForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::robotomyForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::treeMakerForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(const std::string &type, const std::string &target)
{
	AForm *(*aform_makers[])(const std::string target) = {&presidentialForm, &robotomyForm, &treeMakerForm};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (type == forms[i])
		{
			std::cout << "Intern created a form type of the  <" << type << ">" << std::endl;
			return (aform_makers[i](target));
		}
	}

	std::cout << "Intern faied to create <" << type << "> type form." << std::endl;
	return (NULL);
}
