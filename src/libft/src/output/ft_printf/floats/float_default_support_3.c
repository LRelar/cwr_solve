/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_default_support_3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:06:59 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/30 22:21:44 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					check_width_length_sign(t_fword *container,
						t_float_calc *f)
{
	char				*temp;
	int					i1;
	int					i2;
	int					length;

	i1 = 0;
	length = 0;
	if (container->filler == '0' && f->num < 0 && length < container->width
		&& (container->ftp_width != &ft_width_right))
	{
		temp = init_temp_string(&length, f, container, &i2);
		while (++i1 <= container->width - length)
			temp[i1] = container->filler;
		while (f->float_string[i2])
		{
			temp[i1] = f->float_string[i2];
			i1++;
			i2++;
		}
		free(f->float_string);
		f->float_string = temp;
	}
	if (container->space_plus == 2 && container->hash && f->num > 0
		&& container->precision == 0)
		add_plus_hash_num_prec(f);
}

void					add_plus_hash_num_prec(t_float_calc *f)
{
	char				*temp;

	temp = ft_strjoin("+", f->float_string);
	free(f->float_string);
	f->float_string = temp;
}

void					check_space_flag(t_fword *container, t_float_calc *f)
{
	char				*temp;
	int					length;

	length = ft_strlen(f->float_string);
	if (container->space_plus == 1 && f->num >= 0
		&& f->float_string[length - 1] == container->filler && f->num >= 0
		&& length != container->width && length_prec_whole_check(container, f))
		shift_right_add_space(f, length);
	else if (container->space_plus == 1 && f->num >= 0
			&& (length < container->width || container->width < length
			|| length == container->width))
	{
		check_filler_zero_spase(container, f);
		temp = ft_strjoin(" ", f->float_string);
		free(f->float_string);
		f->float_string = temp;
	}
}

int						length_prec_whole_check(t_fword *container,
						t_float_calc *f)
{
	if (container->precision + 1 + (int)ft_strlen(f->num_whole) > f->length)
		return (1);
	else
		return (0);
}

void					check_filler_zero_spase(t_fword *container,
						t_float_calc *f)
{
	char				*temp;
	int					length;
	int					i;

	length = ft_strlen(f->float_string);
	if (container->space_plus == 1 && length < container->width
		&& container->filler == '0')
	{
		i = container->width - length - 1;
		while (i-- > 0)
		{
			temp = ft_strjoin("0", f->float_string);
			free(f->float_string);
			f->float_string = temp;
		}
	}
}
