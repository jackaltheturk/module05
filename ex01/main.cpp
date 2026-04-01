/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:11:30 by etorun            #+#    #+#             */
/*   Updated: 2026/04/01 19:56:46 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Form a300("a23",300 ,149);
	}
	catch(const std::exception& e)
	{
		std::cout << "Form creation has been failed!!" << std::endl;
		std::cerr << e.what() << std::endl << std::endl;
	}
	
	try
	{
		Form a23("a23",149 ,149);
		Bureaucrat ali("ali", 150);        
		std::cout << "ali's info: " << ali << std::endl;
		std::cout << "Form a23's info: " << a23 << std::endl;
		ali.signForm(a23);
		std::cout << "Ali nin gradesi arttırılıyor" << std::endl;
		ali.increment();
		ali.signForm(a23);
	    std::cout<< "Form a23 last status: " << a23 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}