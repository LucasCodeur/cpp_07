/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:15:09 by lud-adam          #+#    #+#             */
/*   Updated: 2026/02/12 11:25:29 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <cstdlib>

template <typename t> void swap(t& ptr1, t& ptr2)
{
	t temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}

template <typename t> t min(t& ptr1, t& ptr2)
{
	if (ptr1 < ptr2)
		return (ptr1);
	return (ptr2);
}

template <typename t> t max(t& ptr1, t& ptr2)
{
	if (ptr1 > ptr2)
		return (ptr1);
	return (ptr2);
}

# endif
