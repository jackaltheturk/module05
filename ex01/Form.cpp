/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:35 by etorun            #+#    #+#             */
/*   Updated: 2026/04/02 13:08:13 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Default"), _isSigned(false), _signRequired(150), _execRequired(150){}

Form::Form(std::string Name, int SignRequired, int ExecRequired): _name(Name), _signRequired(SignRequired), _execRequired(ExecRequired)
{
	_isSigned = false;
	if (SignRequired < 1)
    	throw GradeTooHighException();
	else if (SignRequired > 150)
    	throw GradeTooLowException();
}

Form::Form(const Form &sample) : _name(sample._name), _isSigned(sample._isSigned), _signRequired(sample._signRequired), _execRequired(sample._execRequired){};

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
		_isSigned = copy.getIsSigned();
	return *this;
}

Form::~Form(){};

std::string Form::getName() const { return _name;}

bool Form::getIsSigned() const { return _isSigned;}

int Form::getSignRequired() const {return _signRequired;}

int Form::getExecRequired() const {return _execRequired;}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if(bureaucrat.getGrade() <= getSignRequired())
		_isSigned = true;
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
