/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 21:14:58 by etorun            #+#    #+#             */
/*   Updated: 2026/04/01 21:41:50 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
	
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string Name, int SignRequired, int ExecRequired);
	ShrubberyCreationForm(const ShrubberyCreationForm &sample);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();
	
	void execute(Bureaucrat const & executor) const;
	
	class NotSigned : public std::exception
	{
		public:
		const char* what() const throw();
	};
};

 std::ostream& operator<<(std::ostream& outstream, const ShrubberyCreationForm& ShrubberyCreationForm);

 #endif