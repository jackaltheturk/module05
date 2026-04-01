/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:11:30 by etorun            #+#    #+#             */
/*   Updated: 2026/04/01 22:05:36 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try 
	{	
		Bureaucrat ali("ali", 140);
		ShrubberyCreationForm form55("agac");
		std::cout << form55<< std::endl; 
		ali.signForm(form55);
		std::cout << form55<< std::endl;
		ali.executeForm(form55);
		   
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
}