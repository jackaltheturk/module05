/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:21 by etorun            #+#    #+#             */
/*   Updated: 2026/04/02 13:50:44 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45),_target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string Target ): AForm("RobotomyRequestForm", 72, 45),_target(Target)  {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &sample) : AForm(sample), _target(sample._target){};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
	{	
		AForm::operator=(copy);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){};

const char* RobotomyRequestForm::NotSigned::what() const throw()
{
	return "Form is not signed!";
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{

}

std::string RobotomyRequestForm::getTarget() const {return _target;}

std::ostream& operator<<(std::ostream& outstream, const RobotomyRequestForm& RobotomyRequestForm)
{
	outstream << "RobotomyRequestForm name is : " << RobotomyRequestForm.getName() << std::endl 
	<< "RobotomyRequestForm sign required grade is : " << RobotomyRequestForm.getSignRequired()<< std::endl 
	<< "RobotomyRequestForm execute required grade is: " << RobotomyRequestForm.getExecRequired() << std::endl
	<< "RobotomyRequestForm status is: " << RobotomyRequestForm.getIsSigned()<< std::endl;
	return outstream;
}