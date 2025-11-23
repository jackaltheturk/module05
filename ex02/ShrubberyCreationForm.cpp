/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:21 by etorun            #+#    #+#             */
/*   Updated: 2025/11/22 22:20:54 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): name("Default"), isSigned(false), signRequired(150), execRequired(150){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string Name, int SignRequired, int ExecRequired): name(Name), signRequired(SignRequired), execRequired(ExecRequired)
{
	isSigned = false;
	if (SignRequired < 1)
    	throw GradeTooHighException();
	else if (SignRequired > 150)
    	throw GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &sample) : name(sample.name), isSigned(sample.isSigned), signRequired(sample.signRequired), execRequired(sample.execRequired){};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
		isSigned = copy.getIsSigned();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){};

std::string ShrubberyCreationForm::getName() const { return name;}

bool ShrubberyCreationForm::getIsSigned() const { return isSigned;}

int ShrubberyCreationForm::getSignRequired() const {return signRequired;}

int ShrubberyCreationForm::getExecRequired() const {return execRequired;}

void ShrubberyCreationForm::beSigned(const Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() <= getSignRequired())
		isSigned = true;
	else 
		throw GradeTooLowException();
};

const char* ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& outstream, const ShrubberyCreationForm& ShrubberyCreationForm)
{
	outstream << "ShrubberyCreationForm name is : " << ShrubberyCreationForm.getName() << std::endl 
	<< "ShrubberyCreationForm sign required grade is : " << ShrubberyCreationForm.getSignRequired()<< std::endl 
	<< "ShrubberyCreationForm execute required grade is: " << ShrubberyCreationForm.getExecRequired() << std::endl
	<< "ShrubberyCreationForm status is: " << ShrubberyCreationForm.getIsSigned()<< std::endl;
	return outstream;
}