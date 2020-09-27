/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_default_support_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:13:49 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/30 22:17:37 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						get_length_double(long double number, t_float_calc *f)
{
	int					length;
	int					length2;
	long double			number2;

	length = 1;
	length2 = 1;
	f->whole_add_one = 0;
	if (number < 0)
		number *= (-1);
	number2 = number;
	while ((number /= 10) >= 1)
		length++;
	while ((number2 /= 10) > 1)
		length2++;
	if (length2 < length)
		f->whole_add_one = 1;
	return (length);
}

void					shift_string_left(char *string)
{
	int					i;

	i = 0;
	while (string[++i])
		string[i - 1] = string[i];
}

char					*get_zero_line(int zero_length)
{
	char				*zero_line;
	int					i;

	zero_line = (char *)malloc(sizeof(char) * zero_length + 1);
	i = 0;
	zero_line[zero_length] = '\0';
	while (i < zero_length)
	{
		zero_line[i] = '0';
		i++;
	}
	return (zero_line);
}

int						check_rounding(t_fword *container, t_float_calc *f,
						unsigned long long fract, int len_num)
{
	unsigned long long	num;
	int					i;
	int					flag;

	flag = 0;
	if (f->whole_add_one && f->iter == 0)
	{
		i = 0;
		num = 1;
		while (++i < len_num)
			num *= 10;
		fract = fract - num;
		f->fraction = fract;
		f->pow = 0;
		f->iter = 0;
		f->whole += 1;
		init_fraction_part(container, f);
		flag = 1;
	}
	if (container->precision == 0 && fract)
		f->whole++;
	return (flag);
}

void					init_fraction_part(t_fword *container, t_float_calc *f)
{
	int					len_num;
	unsigned long long	fract;
	char				*temp;

	fract = f->fraction * ft_pow_ull(10, container->precision + 1, f);
	if (fract % 10 >= 5)
		f->fraction += 1 / (long double)ft_pow_ull(10, container->precision, f);
	fract = f->fraction * ft_pow_ull(10, container->precision, f);
	if (!f->pow)
		f->pow = 1;
	f->iter /= f->pow;
	len_num = get_length_double(fract, f);
	if (!check_rounding(container, f, fract, len_num))
	{
		f->zero_line = get_zero_line(f->iter);
		f->num_fraction = (char *)malloc(sizeof(char) * len_num);
		f->num_fraction = ft_intoa_float(fract, f->num_fraction, 0);
		temp = ft_strjoin(f->zero_line, f->num_fraction);
		ft_memdel((void **)&(f->zero_line));
		free(f->num_fraction);
		f->num_fraction = temp;
	}
}
