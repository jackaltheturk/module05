/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:21 by etorun            #+#    #+#             */
/*   Updated: 2026/04/02 15:57:23 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5),_target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string Target ): AForm("PresidentialPardonForm", 25, 5),_target(Target)  {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &sample) : AForm(sample), _target(sample._target){};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
	{	
		AForm::operator=(copy);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){};

const char* PresidentialPardonForm::NotSigned::what() const throw()
{
	return "Form is not signed!";
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw NotSigned();
	if (executor.getGrade() > getExecRequired())
		throw GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
	
std::string PresidentialPardonForm::getTarget() const {return _target;}

std::ostream& operator<<(std::ostream& outstream, const PresidentialPardonForm& PresidentialPardonForm)
{
	outstream << "PresidentialPardonForm name is : " << PresidentialPardonForm.getName() << std::endl 
	<< "PresidentialPardonForm sign required grade is : " << PresidentialPardonForm.getSignRequired()<< std::endl 
	<< "PresidentialPardonForm execute required grade is: " << PresidentialPardonForm.getExecRequired() << std::endl
	<< "PresidentialPardonForm status is: " << PresidentialPardonForm.getIsSigned()<< std::endl;
	return outstream;
}