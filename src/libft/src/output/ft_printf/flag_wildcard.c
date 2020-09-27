/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_wildcard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:14:26 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/30 21:26:45 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t				ft_proc_wildcard_dummy(t_format *formstat, uint8_t iswidth)
{
	if (!(iswidth))
		formstat->sight += 1;
	return (1);
}

/*
**			ft_proc_wildcard
**	iswidth == 1	-	function was called by flag_width.
**	iswidth == 0	-	function was called by flag_precision.
*/

inline static void	ft_called_by_width(t_fword *format, int variative)
{
	if (variative < 0)
	{
		format->ftp_width = &ft_width_right;
		format->filler = ' ';
		variative = (variative + (variative == INT32_MIN)) * -1;
	}
	format->width = variative;
}

inline static void	ft_called_by_precision(t_format *formstat, \
												t_fword *format, int variative)
{
	formstat->sight += 1;
	if (variative < 0)
	{
		format->flags = 0;
		variative = 0;
	}
	format->precision = variative;
}

uint8_t				ft_proc_wildcard(t_format *formstat, \
							t_fword *format, uint8_t iswidth)
{
	int				variative;

	if (formstat->access_key == 2)
		ft_err_mixed_input();
	if (!(formstat->access_key))
		formstat->access_key = 1;
	variative = va_arg((formstat->cur_ap), int);
	if (iswidth)
	{
		ft_called_by_width(format, variative);
	}
	else
	{
		ft_called_by_precision(formstat, format, variative);
	}
	return (1);
}
