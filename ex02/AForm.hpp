/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:21 by etorun            #+#    #+#             */
/*   Updated: 2026/04/02 13:09:04 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
	private:
	
	const std::string _name;
	bool _isSigned;
	const int _signRequired;
	const int _execRequired;
	
	public:
	
	AForm();
	AForm(std::string Name, int SignRequired, int ExecRequired);
	AForm(const AForm &sample);
	AForm& operator=(const AForm& copy);
	virtual ~AForm();
	std::string getName() const;
	bool getIsSigned() const;
	int getSignRequired() const;
	int getExecRequired() const;
	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const& executor) const = 0;
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

 std::ostream& operator<<(std::ostream& outstream, const AForm& AForm);
#endif