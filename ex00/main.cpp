/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:11:30 by etorun            #+#    #+#             */
/*   Updated: 2025/11/21 22:51:49 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat ali("Ali", 150);        
	try 
	{
	   ali.decrement();
	} 
	catch (const Bureaucrat::GradeTooLowException& error) 
	{
	    std::cout << error.what() << std::endl;
	} 
	catch (const Bureaucrat::GradeTooHighException& error) 
	{
	    std::cout << error.what() << std::endl;
	}
	std::cout << ali;	
	return 0;
}