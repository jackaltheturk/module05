/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:11:30 by etorun            #+#    #+#             */
/*   Updated: 2026/04/02 17:49:56 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern acemi;
		Bureaucrat ali("Ali",3);
		AForm* yeniform = acemi.makeForm("RobotomyRequestyuForm","osman");
		ali.signForm(*yeniform);
		ali.executeForm(*yeniform);
		delete(yeniform);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	
}