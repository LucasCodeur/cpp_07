/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:09 by lud-adam          #+#    #+#             */
/*   Updated: 2026/02/12 18:40:48 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename A, typename B>
void iter(A* array, const int length, B func)
{
	std::cout << "REGULAR VERSION\n";
	if (!array || !func)
		return ;
	for (int i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

template <typename A, typename B>
void iter(const A* array, const int length, const B func)
{
	std::cout << "CONST VERSION\n";
	if (!array || !func)
		return ;
	for (int i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

# endif
