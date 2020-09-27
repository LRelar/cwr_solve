/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:14:47 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:40:31 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t					ft_flag_type_dummy(t_format *formstat, \
													t_fword *formword)
{
	formword->ftp_type = &ft_place_dummy;
	if (*formstat->sight == 'f' || *formstat->sight == 'F')
	{
		if (formword->vari_cont)
			formword->vari_cont->iterator = &ft_skip_va_arg_float;
	}
	else if (ft_memchr("cCspdDimoOuUxXbr", *(formstat->sight), 16))
	{
		if (formword->vari_cont)
			formword->vari_cont->iterator = &ft_skip_va_arg_int;
	}
	if (ft_memchr("cCspdDimoOuUxXbrf%", *(formstat->sight), 18))
		formstat->sight += 1;
	else
	{
		if (formword->vari_cont)
		{
			ft_memdel((void **)&(formword->vari_cont));
			formword->vari_cont = NULL;
		}
	}
	return (0);
}

inline static uint8_t	ft_check_valid_word(t_format *formstat, \
									t_fword *word, char type)
{
	if (ft_memchr("cCspdDimoOuUxXbrf", type, 17))
	{
		formstat->sight += 1;
		formstat->marker = formstat->sight;
		if ((type != '%') && word->vari_num)
			ft_prepare_va_list(formstat, word->vari_num, word->variative);
		return (1);
	}
	return (0);
}

/*
**		I DID'T ADD extra flag (%b and %r)
*/

inline static void		ft_pric_int_cap_ft(t_fword *formword, char type)
{
	if (type == 'D')
	{
		formword->ftp_type = &ft_place_integer;
		formword->length_t = 3;
	}
	else if (type == 'O')
	{
		formword->ftp_type = &ft_place_octal;
		formword->length_t = 3;
	}
	else if (type == 'U')
	{
		formword->ftp_type = &ft_place_unsigned;
		formword->length_t = 3;
	}
}

inline static void		ft_pick_int_ft(t_fword *formword, char type)
{
	if (type == 'c' || type == 'C')
		formword->ftp_type = &ft_place_char;
	else if (type == 's' || type == 'S')
		formword->ftp_type = &ft_place_string;
	else if (type == 'p')
		formword->ftp_type = &ft_place_ptr;
	else if (type == 'd' || type == 'i')
		formword->ftp_type = &ft_place_integer;
	else if (type == 'o')
		formword->ftp_type = &ft_place_octal;
	else if (type == 'u')
		formword->ftp_type = &ft_place_unsigned;
	else if (type == 'x')
		formword->ftp_type = &ft_place_hexal;
	else if (type == 'X')
		formword->ftp_type = &ft_place_hexal_cap;
	else if (type == 'm')
		formword->ftp_type = &ft_place_mem;
	else
		ft_pric_int_cap_ft(formword, type);
}

uint8_t					ft_flag_type(t_format *formstat, \
													t_fword *formword)
{
	char				type;

	type = *formstat->sight;
	if (formstat->errflag)
		return (1);
	if (ft_check_valid_word(formstat, formword, type))
	{
		if (type == 'f' || type == 'F')
			formword->ftp_type = &ft_place_float;
		else if (ft_memchr("cCspdDimoOuUxXbr", type, 16))
			ft_pick_int_ft(formword, type);
	}
	return (0);
}
