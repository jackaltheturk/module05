/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:35 by etorun            #+#    #+#             */
/*   Updated: 2026/04/01 19:35:31 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("Default"), isSigned(false), signRequired(150), execRequired(150){}

Form::Form(std::string Name, int SignRequired, int ExecRequired): name(Name), signRequired(SignRequired), execRequired(ExecRequired)
{
	isSigned = false;
	if (SignRequired < 1)
    	throw GradeTooHighException();
	else if (SignRequired > 150)
    	throw GradeTooLowException();
}

Form::Form(const Form &sample) : name(sample.name), isSigned(sample.isSigned), signRequired(sample.signRequired), execRequired(sample.execRequired){};

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
		isSigned = copy.getIsSigned();
	return *this;
}

Form::~Form(){};

std::string Form::getName() const { return name;}

bool Form::getIsSigned() const { return isSigned;}

int Form::getSignRequired() const {return signRequired;}

int Form::getExecRequired() const {return execRequired;}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() <= getSignRequired())
		isSigned = true;
	else 
		throw GradeTooLowException();
};

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& outstream, const Form& Form)
{
	outstream << "Form name is : " << Form.getName() << std::endl 
	<< "Form sign required grade is : " << Form.getSignRequired()<< std::endl 
	<< "Form execute required grade is: " << Form.getExecRequired() << std::endl
	<< "Form status is: " << Form.getIsSigned()<< std::endl;
	return outstream;
}
