/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_minus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:08:34 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/27 18:08:50 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t					ft_flag_minus_dummy(const char *ptr)
{
	if (*ptr == '-')
		return (1);
	return (0);
}

uint8_t					ft_flag_minus(const char *ptr, t_fword *format)
{
	if (*ptr == '-')
	{
		format->ftp_width = &ft_width_right;
		return (1);
	}
	return (0);
}
