/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:35 by etorun            #+#    #+#             */
/*   Updated: 2025/11/21 22:00:19 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"



Bureaucrat::Bureaucrat(): name("Default"), grade(150) {};

Bureaucrat::Bureaucrat(std::string Name, int Grade): name(Name), grade(Grade)
{
	if (Grade > 150)
		throw GradeTooLowException();
	else if (Grade < 1)
		throw GradeTooHighException();
};

Bureaucrat::Bureaucrat(const Bureaucrat &sample) : name(sample.getName()) ,grade(sample.getGrade())	{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this != &copy)
		grade = copy.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(){};

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}