/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 21:14:58 by etorun            #+#    #+#             */
/*   Updated: 2026/04/02 13:29:02 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
	
	const std::string _target;
	
	public:
	
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string Name);
	ShrubberyCreationForm(const ShrubberyCreationForm &sample);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();
	
	void execute(Bureaucrat const & executor) const;
	std::string getTarget() const;
	class NotSigned : public std::exception
	{
		public:
		const char* what() const throw();
	};
};

 std::ostream& operator<<(std::ostream& outstream, const ShrubberyCreationForm& ShrubberyCreationForm);

 #endif