/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etorun <etorun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 21:11:30 by etorun            #+#    #+#             */
/*   Updated: 2026/04/01 16:40:49 by etorun           ###   ########.fr       */
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
	std::cout << "Ali grade(150) yaratılıyor." << std::endl;
	Bureaucrat ali("Ali", 150);        
	try 
	{
		std::cout << "Ali'nin gradesi düşürülmeye çalışılıyor." << std::endl;
		ali.decrement();
	} 
	catch (const std::exception& e) 
	{
		std::cout << e.what() << std::endl;
	} 
	std::cout << "Last status: " << ali << std::endl;
	std::cout << "Veli grade(2) yaratılıyor." << std::endl;
	Bureaucrat veli = Bureaucrat("Veli",2);
	try
	{
		std::cout << "Veli(2) grade yükseltiliyor." << std::endl;
		veli.increment();
		std::cout << "Promoted veli says: " << veli << std::endl;
		std::cout << "Veli'nin gradesi ikici kez yükseltilmeye çalışılıyor." << std::endl;
		veli.increment();
		std::cout << "NonPromoted veli says: " << veli << std::endl;
		//This line of the code will never run. Left intentionally to demostrate.
	}
	catch (const std::exception& e) 
	{
	    std::cout << e.what() << std::endl;
	}
	std::cout << "Last status: " << veli << std::endl;
	return 0;
}