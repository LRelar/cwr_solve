/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 13:05:49 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/30 21:22:03 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				add_whole_part(t_fword *container, t_float_calc *f)
{
	char				*temp;
	int					len_num;
	int					i;

	f->pointer = f->end;
	init_fraction_part(container, f);
	len_num = get_length_double(f->whole, f);
	f->num_whole = (char *)malloc(sizeof(char) * len_num + 1);
	f->num_whole = ft_intoa_float(f->whole, f->num_whole, 0);
	i = -1;
	while (f->num_whole[++i])
	{
		shift_string_left(f->float_string);
		temp = f->end - 1;
		temp[0] = f->num_whole[i];
	}
	if ((container->hash && container->precision == 0)
		|| container->precision > 0)
	{
		shift_string_left(f->float_string);
		temp = f->end - 1;
		temp[0] = '.';
	}
}

static void				add_fraction_part(t_fword *container, t_float_calc *f)
{
	int					i;
	char				*temp;

	i = -1;
	while (f->num_fraction[++i])
	{
		shift_string_left(f->float_string);
		temp = f->end - 1;
		temp[0] = f->num_fraction[i];
	}
	while (container->precision > i++)
	{
		shift_string_left(f->float_string);
		temp = f->end - 1;
		temp[0] = '0';
	}
}

static void				add_m_d_e(t_fword *container,
						t_float_calc *f, long double number)
{
	f->whole = (long long)number;
	f->fraction = number - f->whole;
	add_whole_part(container, f);
	if (container->precision > 0)
		add_fraction_part(container, f);
	check_minus_hash_precision_zero(container, f);
	check_filler_zero_plus(container, f);
	check_space_flag(container, f);
	check_width_length_sign(container, f);
}

char					*ft_form_double(t_fword *container, \
						long double number, t_float_calc *f)
{
	f->num = (long double)number;
	if (check_error_float(f))
		return (return_error_float(f, container));
	init_float_calc(f, number);
	if (container->precision)
		f->length = f->length + container->precision + 1;
	if (container->space_plus == 2 || f->sign_bit
		|| (container->precision == 0 && container->hash))
		f->length++;
	f->float_string = (char *)malloc(sizeof(char) * f->length + 1);
	f->float_string[f->length] = '\0';
	add_filler_signe_double(container, f, &number);
	add_m_d_e(container, f, number);
	free(f->num_whole);
	free(f->num_fraction);
	return (f->float_string);
}

char					*ft_get_float_default(t_fword *container, char parent)
{
	long double			number;
	t_float_calc		f;

	ft_bzero(&f, sizeof(f));
	f.flag = parent;
	number = (long double)va_arg(*container->variative, double);
	return (ft_form_double(container, number, &f));
}
