/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:21 by etorun            #+#    #+#             */
/*   Updated: 2026/04/01 19:35:37 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Bureaucrat;

class Form
{
	private:
	
	const std::string name;
	bool isSigned;
	const int signRequired;
	const int execRequired;
	
	public:
	
	Form();
	Form(std::string Name, int SignRequired, int ExecRequired);
	Form(const Form &sample);
	Form& operator=(const Form &copy);
	~Form();
	std::string getName() const;
	bool getIsSigned() const;
	int getSignRequired() const;
	int getExecRequired() const;
	void beSigned(const Bureaucrat& bureaucrat);
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

 std::ostream& operator<<(std::ostream& outstream, const Form& Form);
#endif