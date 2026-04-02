/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:11:30 by etorun            #+#    #+#             */
/*   Updated: 2026/04/02 16:17:28 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try 
	{	
		Bureaucrat ali("Ali", 100);
		ShrubberyCreationForm form55("Home");
		std::cout << form55<< std::endl; 
		ali.signForm(form55);
		std::cout << form55<< std::endl;
		ali.executeForm(form55);
		   
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	
	try 
	{	
		Bureaucrat veli("Veli", 50);
		RobotomyRequestForm form23("Erman");
		std::cout << form23<< std::endl; 
		veli.signForm(form23);
		std::cout << form23<< std::endl;
		veli.executeForm(form23);
		   
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	
	try 
	{	
		Bureaucrat huseyin("Huseyin", 5);
		PresidentialPardonForm form11("Hasan");
		std::cout << form11<< std::endl; 
		huseyin.signForm(form11);
		std::cout << form11<< std::endl;
		huseyin.executeForm(form11);
		   
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
}