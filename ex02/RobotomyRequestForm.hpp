/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:21 by etorun            #+#    #+#             */
/*   Updated: 2026/04/02 15:52:44 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
	
	const std::string _target;
	
	public:
	
	RobotomyRequestForm();
	RobotomyRequestForm(std::string Name);
	RobotomyRequestForm(const RobotomyRequestForm &sample);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();
	
	void execute(Bureaucrat const & executor) const;
	std::string getTarget() const;
	class NotSigned : public std::exception
	{
		public:
		const char* what() const throw();
	};
};

 std::ostream& operator<<(std::ostream& outstream, const RobotomyRequestForm& RobotomyRequestForm);

 #endif