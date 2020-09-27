/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:08:56 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/27 18:09:10 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t					ft_flag_plus_dummy(const char *ptr)
{
	if (*ptr == '+')
		return (1);
	return (0);
}

uint8_t					ft_flag_plus(const char *ptr, t_fword *format)
{
	if (*ptr == '+')
	{
		format->space_plus = 2;
		return (1);
	}
	return (0);
}
