/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 08:33:22 by lud-adam          #+#    #+#             */
/*   Updated: 2026/02/13 09:03:07 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <iostream>
#include <exception>

template <typename T> class Array
{
	public:
		T*				array;
		unsigned int	len;
		Array(void)
		{
			std::cout << "Array Constructor called" << std::endl;
			array = NULL;
			this->len = 0;
		}
		Array(unsigned int n)
		{
			std::cout << "Array Unsigned int Constructor called" << std::endl;
			try 
			{
				this->array = new T [n];
				explicit_bzero(this->array, sizeof(T) * n);
				this->len = n;
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
			if (this != &other && other.array)
			{
				try
				{
					this->array = new T [other.len];
					explicit_bzero(this->array, sizeof(T) * other.len);
					this->len = other.len;
				}
				catch(std::exception &e)
				{
					std::cout << "Error: " << e.what() << std::endl;
					return ;
				}
				for (unsigned int i = 0; i < other.size() ; i++)
				{
					this->array[i] = other.array[i];
				}
			}
		}
		~Array(void)
		{
			std::cout << "Array Destructor called" << std::endl;
		}
		Array& operator=(const Array& other)
		{
			if (this != &other && other.array)
			{
				try
				{
					delete [] this->array;
					this->array = new T [other.len];
					explicit_bzero(this->array, sizeof(T) * other.len);
					this->len = other.len;
				}
				catch(std::exception &e)
				{
					std::cout << "Error: " << e.what() << std::endl;
					return (*this);
				}
				this->len = other.len;
				if (other.array)
				{
					for (unsigned int i = 0; i < other.size() ; i++)
					{
						this->array[i] = other.array[i];
					}
				}
			}
			return (*this);
		}
		T& operator[](unsigned int index)
		{
			if (index >= this->len || index < 0)	
				throw std::out_of_range("Out of range");
			return (this->array[index]);
		}
		unsigned int size(void) const
		{
			return (this->len);
		}
};
