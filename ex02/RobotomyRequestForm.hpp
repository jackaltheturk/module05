/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:21 by etorun            #+#    #+#             */
/*   Updated: 2025/11/22 22:20:54 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
	private:
	
	const std::string name;
	bool isSigned;
	const int signRequired;
	const int execRequired;
	
	public:
	
	RobotomyRequestForm();
	RobotomyRequestForm(std::string Name, int SignRequired, int ExecRequired);
	RobotomyRequestForm(const RobotomyRequestForm &sample);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();
	std::string getName() const;
	bool getIsSigned() const;
	int getSignRequired() const;
	int getExecRequired() const;
	void beSigned(const Bureaucrat& bureaucrat);
	void execute(Bureaucrat const & executor) const;
	class GradeTooHighException : public std::exception
	{
		public:
		const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
		const char* what() const throw();
	};
};

 std::ostream& operator<<(std::ostream& outstream, const RobotomyRequestForm& RobotomyRequestForm);
#endif