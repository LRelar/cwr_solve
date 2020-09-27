/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:09:55 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 22:06:06 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t			ft_flag_precision_dummy(t_format *formstat)
{
	const char	*ptr;
	const char	*start;

	start = formstat->sight;
	if (*start != '.')
		return (0);
	ptr = start;
	if (*(ptr + 1) == '*')
	{
		return (ft_proc_wildcard_dummy(formstat, 0));
	}
	while (ft_memchr("1234567890", *++ptr, 10))
		;
	formstat->sight = ptr - 1;
	return (1);
}

uint8_t			ft_flag_precision(t_format *formstat, \
													t_fword *format)
{
	const char	*ptr;
	const char	*start;
	const char	*end;
	long long	arg_num;

	start = formstat->sight;
	if (*start != '.')
		return (0);
	format->flags = 1;
	ptr = start;
	if (*(ptr + 1) == '*')
		return (ft_proc_wildcard(formstat, format, 0));
	while (ft_memchr("1234567890", *++ptr, 10))
		;
	end = ptr;
	formstat->sight = end - 1;
	if (ft_antoi(start + 1, end, &arg_num))
		formstat->errflag = ft_err_varoverflow("arg_num", __func__);
	if (arg_num < INT32_MIN || arg_num > INT32_MAX)
		formstat->errflag = ft_err_varoverflow("arg_num", __func__);
	format->precision = (int)arg_num;
	return (1);
}
