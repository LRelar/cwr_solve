/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:42:07 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/28 22:58:47 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_initfword(t_fword *ptr, t_format *formstat)
{
	ft_bzero((void *)ptr, sizeof(t_fword));
	ptr->filler = ' ';
	ptr->variative = &formstat->cur_ap;
	ptr->ftp_type = &ft_place_default;
	ptr->ftp_width = &ft_width_left;
}

uint8_t					ft_parse_form_word(t_fword *formword, \
													t_format *formstat)
{
	(formstat->sight) += 1;
	if (ft_flag_hash(formstat->sight, formword))
		return (ft_parse_form_word(formword, formstat));
	else if (ft_flag_minus(formstat->sight, formword))
		return (ft_parse_form_word(formword, formstat));
	else if (ft_flag_plus(formstat->sight, formword))
		return (ft_parse_form_word(formword, formstat));
	else if (ft_flag_space(formstat->sight, formword))
		return (ft_parse_form_word(formword, formstat));
	else if (ft_flag_zero(formstat->sight, formword))
		return (ft_parse_form_word(formword, formstat));
	else if (ft_flag_subst(formstat, formword))
		return (ft_parse_form_word(formword, formstat));
	else if (ft_flag_width(formstat, formword))
		return (ft_parse_form_word(formword, formstat));
	else if (ft_flag_precision(formstat, formword))
		return (ft_parse_form_word(formword, formstat));
	else if (ft_flag_length(formstat, formword))
		return (ft_parse_form_word(formword, formstat));
	else if (ft_flag_type(formstat, formword))
		return (formstat->errflag);
	return (formstat->errflag);
}

uint8_t					ft_check_form_word(t_format *formstat)
{
	t_fword				curfield;

	ft_initfword(&curfield, formstat);
	if (ft_parse_form_word(&curfield, formstat))
		return (1);
	if (curfield.ftp_type(formstat, &curfield) && formstat->errflag)
		return (ft_wipe_structs(NULL, &curfield, NULL));
	ft_wipe_structs(NULL, &curfield, NULL);
	return (0);
}
