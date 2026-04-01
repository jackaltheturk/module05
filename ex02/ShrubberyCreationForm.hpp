/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 21:14:58 by etorun            #+#    #+#             */
/*   Updated: 2026/04/01 21:15:03 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
	
	const std::string name;
	bool isSigned;
	const int signRequired;
	const int execRequired;
	
	public:
	
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string Name, int SignRequired, int ExecRequired);
	ShrubberyCreationForm(const ShrubberyCreationForm &sample);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();
	std::string getName() const;
	bool getIsSigned() const;
	int getSignRequired() const;
	int getExecRequired() const;
	void beSigned(const Bureaucrat& bureaucrat);
	void execute(Bureaucrat const & executor) const;
	
	class NotSigned : public std::exception
	{
		public:
		const char* what() const throw();
	};
};

 std::ostream& operator<<(std::ostream& outstream, const ShrubberyCreationForm& ShrubberyCreationForm);

 #endif