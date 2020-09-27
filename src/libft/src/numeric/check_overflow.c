/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:15:47 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/28 22:22:55 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t					ft_check_add_ovf(int *result, int a, int b)
{
	if (a > (INT_MAX - b))
		return (1);
	else
		*result = a + b;
	return (0);
}

uint8_t					ft_check_sub_ovf(int *result, int a, int b)
{
	if (a < 0 && b >= 0)
	{
		if (a < (INT_MIN + b))
			return (1);
	}
	else if (a >= 0 && b < 0)
	{
		if (a > (INT_MAX + b))
			return (1);
	}
	else
		*result = a - b;
	return (0);
}
