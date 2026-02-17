/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 11:09:13 by lud-adam          #+#    #+#             */
/*   Updated: 2026/02/12 18:46:32 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <iostream>

static void	print(const std::string& str);
static void	sumString(std::string& str);
static int sumInt(int& a);
static void	t_iter_with_string_function(void);
static void	t_iter_with_int_function(void);
static void	t_iter_with_const_string_function(void);

int main(void) 
{
	t_iter_with_int_function();
	t_iter_with_string_function();
	t_iter_with_const_string_function();
	return 0;
}

static void	t_iter_with_int_function(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_iter_with_int_function" << std::endl;
	int	array[10];
	const int	length = 10;
	for (int i = 0; i < 10; i++)
	{
		array[i] = i;
	}
	iter(array, length, sumInt);
	for (int i = 0; i < length; i++)
	{
	  std::cout << array[i] << std::endl;
	}
}

static void	t_iter_with_string_function(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_iter_with_string_function" << std::endl;
	std::string	array[10];
	int	length = 10;
	for (int i = 0; i < 10; i++)
	{
		array[i] = "School: ";
	}
	iter(array, length, &sumString);
	for (int i = 0; i < length; i++)
	{
	  std::cout << array[i] << std::endl;
	}
}

static void	t_iter_with_const_string_function(void)
{
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << "Test : t_iter_with_const_string_function" << std::endl;
	const std::string days[] = {"mon", "tue", "wed", "thur","fri", "sat", "sun"};
	iter(days, 7, print);
}

static int sumInt(int& a)
{
	return (a += 10);
}

static void	sumString(std::string& str)
{
	str += "42";
}

static void	print(const std::string& str)
{
	std::cout << str << std::endl;
}
