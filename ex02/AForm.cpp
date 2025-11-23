/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:35 by etorun            #+#    #+#             */
/*   Updated: 2025/11/22 22:40:52 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("Default"), isSigned(false), signRequired(150), execRequired(150){}

AForm::AForm(std::string Name, int SignRequired, int ExecRequired): name(Name), signRequired(SignRequired), execRequired(ExecRequired)
{
	isSigned = false;
	if (SignRequired < 1)
    	throw GradeTooHighException();
	else if (SignRequired > 150)
    	throw GradeTooLowException();
}

AForm::AForm(const AForm &sample) : name(sample.name), isSigned(sample.isSigned), signRequired(sample.signRequired), execRequired(sample.execRequired){};

AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
		isSigned = copy.getIsSigned();
	return *this;
}

AForm::~AForm(){};

std::string AForm::getName() const { return name;}

bool AForm::getIsSigned() const { return isSigned;}

int AForm::getSignRequired() const {return signRequired;}

int AForm::getExecRequired() const {return execRequired;}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() <= getSignRequired())
		isSigned = true;
	else 
		throw GradeTooLowException();
};

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& outstream, const AForm& AForm)
{
	outstream << "AForm name is : " << AForm.getName() << std::endl 
	<< "AForm sign required grade is : " << AForm.getSignRequired()<< std::endl 
	<< "AForm execute required grade is: " << AForm.getExecRequired() << std::endl
	<< "AForm status is: " << AForm.getIsSigned()<< std::endl;
	return outstream;
}
