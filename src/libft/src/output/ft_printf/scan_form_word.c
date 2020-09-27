/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_form_word.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:44:11 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/28 23:07:03 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_initfword_dumb(t_fword *ptr)
{
	ft_bzero((void *)ptr, sizeof(t_fword));
}

static uint8_t			ft_seach_type(t_fword *formword, \
													t_format *formstat)
{
	(formstat->sight) += 1;
	if (ft_flag_hash_dummy(formstat->sight))
		return (ft_seach_type(formword, formstat));
	if (ft_flag_minus_dummy(formstat->sight))
		return (ft_seach_type(formword, formstat));
	if (ft_flag_plus_dummy(formstat->sight))
		return (ft_seach_type(formword, formstat));
	if (ft_flag_space_dummy(formstat->sight))
		return (ft_seach_type(formword, formstat));
	if (ft_flag_zero_dummy(formstat->sight))
		return (ft_seach_type(formword, formstat));
	if (ft_flag_subst_dummy(formstat, formword))
		return (ft_seach_type(formword, formstat));
	if (ft_flag_width_dummy(formstat))
		return (ft_seach_type(formword, formstat));
	if (ft_flag_precision_dummy(formstat))
		return (ft_seach_type(formword, formstat));
	if (ft_flag_length_dummy(formstat))
		return (ft_seach_type(formword, formstat));
	if (ft_flag_type_dummy(formstat, formword))
		return (formstat->errflag);
	return (formstat->errflag);
}

uint8_t					ft_scan_form_word(t_format *formstat)
{
	t_fword				curfield_dumb;

	ft_initfword_dumb(&curfield_dumb);
	ft_seach_type(&curfield_dumb, formstat);
	if (curfield_dumb.ftp_type(formstat, &curfield_dumb))
		return (ft_wipe_structs(formstat, &curfield_dumb, __func__));
	return (0);
}
