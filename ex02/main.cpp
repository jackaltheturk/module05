/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:11:30 by etorun            #+#    #+#             */
/*   Updated: 2025/11/22 23:05:28 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat ali("ali", 150);        
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
	try 
	{
		for(int i = 2; i >= 0; i--)
			ali.increment();
	} 
	catch (const Bureaucrat::GradeTooLowException& error) 
	{
	    std::cout << error.what() << std::endl;
	} 
	catch (const Bureaucrat::GradeTooHighException& error) 
	{
	    std::cout << error.what() << std::endl;
	}
	        
	Form a23("a23",10 ,149);
	Form c11("c11",148 ,149);
	std::cout << "ali's info: " << ali << std::endl;
	std::cout<< a23 << std::endl;

	ali.signForm(a23);

	std::cout<< a23 << std::endl;
	std::cout << "---------- Part two -----------\n" << std::endl;
	std::cout<< c11 << std::endl;
    ali.signForm(c11);
	std::cout<< c11 << std::endl;
	return 0;
}