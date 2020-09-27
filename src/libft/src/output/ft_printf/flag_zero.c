/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:14:56 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/27 18:15:09 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t					ft_flag_zero_dummy(const char *ptr)
{
	if (*ptr == '0')
		return (1);
	return (0);
}

uint8_t					ft_flag_zero(const char *ptr, t_fword *format)
{
	if (*ptr == '0')
	{
		if (format->ftp_width != &ft_width_right)
			format->filler = '0';
		return (1);
	}
	return (0);
}
