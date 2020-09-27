/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_substring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:10:25 by kokeefe           #+#    #+#             */
/*   Updated: 2020/09/13 22:08:11 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline uint8_t	ft_create_varinote(t_fword *format, \
																ssize_t arg_num)
{
	if (!(format->vari_cont))
	{
		if (!(format->vari_cont = \
								(t_varitype *)ft_memalloc(sizeof(t_varitype))))
			return (1);
	}
	format->vari_cont->vari_num = (int)arg_num;
	format->vari_cont->vari_interval = 1;
	return (0);
}

uint8_t					ft_get_and_check_nbr(const char *start, \
						const char *end, long long *result, t_format *formstat)
{
	if (ft_antoi(start, end, result))
		return ((formstat->errflag = \
								ft_err_varoverflow("arg_num", __func__)));
	else
	{
		if (*result < INT32_MIN || *result > INT32_MAX)
			return ((formstat->errflag = \
								ft_err_varoverflow("arg_num", __func__)));
	}
	return (0);
}

uint8_t					ft_flag_subst_dummy(t_format *formstat, \
													t_fword *format)
{
	const char			*ptr;
	const char			*start;
	const char			*end;
	long long			arg_num;

	start = formstat->sight;
	if (!(ft_memchr("123456789", *start, 9)))
		return (0);
	ptr = start;
	while (ft_memchr("1234567890", *++ptr, 10))
		;
	end = ptr;
	if (*end != '$')
		return (0);
	formstat->sight = end;
	ft_get_and_check_nbr(start, end, &arg_num, formstat);
	if (ft_create_varinote(format, arg_num))
		formstat->errflag = ft_err_malloc("format->vari_cont", __func__);
	return (1);
}

/*
**	I wish I had time... I could've built communication between this ft
**	and the one, calculating width... :C
*/

/*
**	This one creates preprocesses for sub_ap va_list to be valiable at proper
**	invocation of n$
*/

uint8_t					ft_flag_subst(t_format *formstat, \
													t_fword *format)
{
	const char			*ptr;
	const char			*start;
	const char			*end;
	long long			arg_num;

	start = formstat->sight;
	if (!(ft_memchr("123456789", *start, 9)))
		return (0);
	ptr = start;
	while (ft_memchr("123456789", *++ptr, 9))
		;
	end = ptr;
	if (*end != '$')
		return (0);
	formstat->sight = end;
	ft_get_and_check_nbr(start, end, &arg_num, formstat);
	va_copy(format->var_sub, formstat->ref_ap);
	format->variative = &(format->var_sub);
	format->vari_num = arg_num;
	return (1);
}
