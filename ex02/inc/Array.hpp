/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:09 by lud-adam          #+#    #+#             */
/*   Updated: 2026/02/13 09:00:58 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T> class Array
{
	public:
		T* array;
		unsigned int size();
		Array(void)
		{
			std::cout << "Array Constructor called" << std::endl;
			array = NULL;
		}
		Array(unsigned int n)
		{
			std::cout << "Array Unsigned int Constructor called" << std::endl;
			try 
			{
				array = new T [n];
			}
			catch(std::exception &e)
			{
				std::cout << "Error: " << e.what() << std::endl;
				return ;
			}
		}
		Array(const Array& other)
		{
			std::cout << "Array Copy Constructor called" << std::endl;
			if (this != &other)
			{

			}
		}
		~Array(void)
		{
			std::cout << "Array Destructor called" << std::endl;
		}
		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				if (other.array)
				{
					// for (int i = 0; other.array[i] != 0)

				}
				
			}
		}
};

# endif
