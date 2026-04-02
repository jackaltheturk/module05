/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 16:26:17 by etorun            #+#    #+#             */
/*   Updated: 2026/04/02 17:59:24 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

class Intern
{
	private:
	
	static AForm* presidentialForm(const std::string target);
	static AForm* robotomyForm(const std::string target);
	static AForm* treeMakerForm(const std::string target);
	
	public:
	
	Intern();
	Intern(const Intern &sample);
	Intern& operator=(const Intern &copy);
	~Intern();
	AForm* makeForm(std::string const &type, std::string const &target);
	class NoNameException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};
#endif