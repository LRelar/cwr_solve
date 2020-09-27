/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_default_support_4.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:21:10 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/30 22:22:11 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					shift_right_add_space(t_float_calc *f, int length)
{
	while (--length)
		f->float_string[length] = f->float_string[length - 1];
	f->float_string[length] = ' ';
}

void					check_minus_hash_precision_zero(t_fword *container,
						t_float_calc *f)
{
	char				*temp;

	if (f->num < 0 && container->hash && container->precision == 0)
	{
		temp = ft_strjoin("-", f->float_string);
		free(f->float_string);
		f->float_string = temp;
	}
}

void					check_filler_zero_plus(t_fword *container,
						t_float_calc *f)
{
	char				*temp;
	int					i1;
	int					i2;
	int					length;

	length = 0;
	i1 = 0;
	if (length < container->width && container->filler == '0'
		&& container->space_plus == 2)
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
}

char					*init_temp_string(int *length, t_float_calc *f,
						t_fword *container, int *i2)
{
	char				*temp;

	*i2 = 1;
	*length = ft_strlen(f->float_string);
	temp = (char *)malloc(sizeof(char) * container->width + 1);
	temp[container->width] = '\0';
	temp[0] = (f->num > 0) ? '+' : '-';
	return (temp);
}
