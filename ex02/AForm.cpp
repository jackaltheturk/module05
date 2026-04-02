/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:35 by etorun            #+#    #+#             */
/*   Updated: 2026/04/02 13:10:13 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("Default"), _isSigned(false), _signRequired(150), _execRequired(150){}

AForm::AForm(std::string Name, int SignRequired, int ExecRequired): _name(Name), _signRequired(SignRequired), _execRequired(ExecRequired)
{
	_isSigned = false;
	if (SignRequired < 1)
    	throw GradeTooHighException();
	else if (SignRequired > 150)
    	throw GradeTooLowException();
}

AForm::AForm(const AForm &sample) : _name(sample._name), _isSigned(sample._isSigned), _signRequired(sample._signRequired), _execRequired(sample._execRequired){};

AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
		_isSigned = copy.getIsSigned();
	return *this;
}

AForm::~AForm(){};

std::string AForm::getName() const { return _name;}

bool AForm::getIsSigned() const { return _isSigned;}

int AForm::getSignRequired() const {return _signRequired;}

int AForm::getExecRequired() const {return _execRequired;}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() <= getSignRequired())
		_isSigned = true;
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
