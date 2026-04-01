/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:11:30 by etorun            #+#    #+#             */
/*   Updated: 2026/04/01 19:48:26 by etorun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "Çok düşük grade(150000) yaratılıyor." << std::endl;
	try 
	{
		Bureaucrat worstOne("Badboy", 150000);
	} 
	catch (const std::exception& e) 
	{
	    std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "Ali grade(150) yaratılıyor." << std::endl;
		Bureaucrat ali("Ali", 150);
		Bureaucrat Copy_character(ali);
		std::cout << "Copy Char test: " <<Copy_character<< std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try 
	{
		Bureaucrat mehmet("Mehmet", 1);
		std::cout << "Mehmet'in gradesi yükseltmeye çalışılıyor." << std::endl;
		mehmet.increment();
	} 
	catch (const std::exception& e) 
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}