/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:21 by etorun            #+#    #+#             */
/*   Updated: 2026/04/02 13:34:32 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137),_target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string Target ): AForm("ShrubberyCreationForm", 145, 137),_target(Target)  {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &sample) : AForm(sample), _target(sample._target){};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{	
		AForm::operator=(copy);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){};

const char* ShrubberyCreationForm::NotSigned::what() const throw()
{
	return "Form is not signed!";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw NotSigned();
	if (executor.getGrade() > getExecRequired())
		throw GradeTooLowException();
	std::ofstream outFile((getTarget() + "_shrubbery").c_str());
	if (!outFile)
        std::cerr << "output file can't be created" << std::endl;
	outFile <<
	"       00000000\n"
	"      000e000p00\n"
	"     000a00000000\n"
	"     000000p0l00\n"
	"       00000000\n"
	"         |||\n"
	"         |||\n"
	"         |||\n";
}

std::string ShrubberyCreationForm::getTarget() const {return _target;}

std::ostream& operator<<(std::ostream& outstream, const ShrubberyCreationForm& ShrubberyCreationForm)
{
	outstream << "ShrubberyCreationForm name is : " << ShrubberyCreationForm.getName() << std::endl 
	<< "ShrubberyCreationForm sign required grade is : " << ShrubberyCreationForm.getSignRequired()<< std::endl 
	<< "ShrubberyCreationForm execute required grade is: " << ShrubberyCreationForm.getExecRequired() << std::endl
	<< "ShrubberyCreationForm status is: " << ShrubberyCreationForm.getIsSigned()<< std::endl;
	return outstream;
}