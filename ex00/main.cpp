/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:11:30 by etorun            #+#    #+#             */
/*   Updated: 2025/11/21 21:57:48 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try 
	{
		Bureaucrat ali("Ali", 200);        
	    Bureaucrat erman("Erman", -10); 
	} 
	catch (const Bureaucrat::GradeTooLowException& error) 
	{
	    std::cout << error.what() << std::endl;
	} catch (const Bureaucrat::GradeTooHighException& error) 
	{
	    std::cout << error.what() << std::endl;
	}
		return 0;
}