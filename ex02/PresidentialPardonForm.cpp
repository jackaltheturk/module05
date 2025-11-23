/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:21 by etorun            #+#    #+#             */
/*   Updated: 2025/11/22 22:20:54 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(): name("Default"), isSigned(false), signRequired(150), execRequired(150){}

PresidentialPardonForm::PresidentialPardonForm(std::string Name, int SignRequired, int ExecRequired): name(Name), signRequired(SignRequired), execRequired(ExecRequired)
{
	isSigned = false;
	if (SignRequired < 1)
    	throw GradeTooHighException();
	else if (SignRequired > 150)
    	throw GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &sample) : name(sample.name), isSigned(sample.isSigned), signRequired(sample.signRequired), execRequired(sample.execRequired){};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
		isSigned = copy.getIsSigned();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){};

std::string PresidentialPardonForm::getName() const { return name;}

bool PresidentialPardonForm::getIsSigned() const { return isSigned;}

int PresidentialPardonForm::getSignRequired() const {return signRequired;}

int PresidentialPardonForm::getExecRequired() const {return execRequired;}

void PresidentialPardonForm::beSigned(const Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() <= getSignRequired())
		isSigned = true;
	else 
		throw GradeTooLowException();
};

const char* PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& outstream, const PresidentialPardonForm& PresidentialPardonForm)
{
	outstream << "PresidentialPardonForm name is : " << PresidentialPardonForm.getName() << std::endl 
	<< "PresidentialPardonForm sign required grade is : " << PresidentialPardonForm.getSignRequired()<< std::endl 
	<< "PresidentialPardonForm execute required grade is: " << PresidentialPardonForm.getExecRequired() << std::endl
	<< "PresidentialPardonForm status is: " << PresidentialPardonForm.getIsSigned()<< std::endl;
	return outstream;
}