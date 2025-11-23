/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:21 by etorun            #+#    #+#             */
/*   Updated: 2025/11/22 22:20:54 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(): name("Default"), isSigned(false), signRequired(150), execRequired(150){}

RobotomyRequestForm::RobotomyRequestForm(std::string Name, int SignRequired, int ExecRequired): name(Name), signRequired(SignRequired), execRequired(ExecRequired)
{
	isSigned = false;
	if (SignRequired < 1)
    	throw GradeTooHighException();
	else if (SignRequired > 150)
    	throw GradeTooLowException();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &sample) : name(sample.name), isSigned(sample.isSigned), signRequired(sample.signRequired), execRequired(sample.execRequired){};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
		isSigned = copy.getIsSigned();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){};

std::string RobotomyRequestForm::getName() const { return name;}

bool RobotomyRequestForm::getIsSigned() const { return isSigned;}

int RobotomyRequestForm::getSignRequired() const {return signRequired;}

int RobotomyRequestForm::getExecRequired() const {return execRequired;}

void RobotomyRequestForm::beSigned(const Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() <= getSignRequired())
		isSigned = true;
	else 
		throw GradeTooLowException();
};

const char* RobotomyRequestForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* RobotomyRequestForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& outstream, const RobotomyRequestForm& RobotomyRequestForm)
{
	outstream << "RobotomyRequestForm name is : " << RobotomyRequestForm.getName() << std::endl 
	<< "RobotomyRequestForm sign required grade is : " << RobotomyRequestForm.getSignRequired()<< std::endl 
	<< "RobotomyRequestForm execute required grade is: " << RobotomyRequestForm.getExecRequired() << std::endl
	<< "RobotomyRequestForm status is: " << RobotomyRequestForm.getIsSigned()<< std::endl;
	return outstream;
}