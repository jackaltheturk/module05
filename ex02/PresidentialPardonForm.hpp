/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 20:28:21 by etorun            #+#    #+#             */
/*   Updated: 2026/04/02 13:46:07 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
	
	const std::string _target;
	
	public:
	
	PresidentialPardonForm();
	PresidentialPardonForm(std::string Name);
	PresidentialPardonForm(const PresidentialPardonForm &sample);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();
	
	void execute(Bureaucrat const & executor) const;
	std::string getTarget() const;
	class NotSigned : public std::exception
	{
		public:
		const char* what() const throw();
	};
};

 std::ostream& operator<<(std::ostream& outstream, const PresidentialPardonForm& PresidentialPardonForm);

 #endif