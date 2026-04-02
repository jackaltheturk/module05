/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:35 by etorun            #+#    #+#             */
/*   Updated: 2026/04/02 13:11:34 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150) {};

Bureaucrat::Bureaucrat(std::string Name, int Grade): _name(Name), _grade(Grade)
{
	if (Grade > 150)
		throw GradeTooLowException();
	else if (Grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &sample) : _name(sample.getName()) ,_grade(sample.getGrade())	{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
		_grade = copy.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(){};

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}
void Bureaucrat::increment()
{
	if(_grade > 1)
		_grade = _grade - 1;
	else	
		throw GradeTooHighException();
}

void Bureaucrat::decrement()
{
	if (_grade < 150)
		_grade = _grade + 1;
	else
		throw GradeTooLowException();
}
void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& error)
	{
		std::cout << _name << " couldn’t sign " << form.getName() << ", because " << error.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	form.execute(*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

std::ostream& operator<<(std::ostream& outstream, const Bureaucrat& bureaucrat)
{
	outstream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return outstream;
}
