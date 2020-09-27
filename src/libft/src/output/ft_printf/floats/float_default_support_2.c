/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_default_support_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:15:32 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/30 20:39:08 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					init_float_calc(t_float_calc *f, long double number)
{
	unsigned short int	*ptr;

	f->float_string = NULL;
	f->sign = NULL;
	f->length = get_length_double(number, f);
	f->mant = (size_t *)&(f->num);
	ptr = (unsigned short int *)(f->mant + 1);
	f->exp = *ptr;
	f->sign_bit = ((*ptr - f->exp) > 0);
	f->nan = 0;
	f->inf_m = 0;
	f->inf_p = 0;
	f->iter = 0;
	f->pow = 0;
}

unsigned long long		ft_pow_ull(unsigned long long a, unsigned int power, \
						t_float_calc *f)
{
	unsigned long long	temp;

	f->pow++;
	temp = a;
	if (power == 0)
		return (1);
	while (--power)
	{
		if (a * f->fraction < 1)
			f->iter++;
		a *= temp;
	}
	return (a);
}

int						check_error_float(t_float_calc *f)
{
	uint64_t			raw_value;
	double				nbd;
	int					err;

	err = 0;
	nbd = (double)f->num;
	raw_value = *(uint64_t *)&nbd;
	if (((raw_value >> 52) & 0xFFF) == 0xFFF)
	{
		if (raw_value & 0x000FFFFFFFFFFFFF)
			f->nan = 1;
		else
			f->inf_m = 1;
		err = 1;
	}
	else if (((raw_value >> 52) & 0xFFF) == 0x7FF)
	{
		if (raw_value & 0x000FFFFFFFFFFFFF)
			f->nan = 1;
		else
			f->inf_p = 1;
		err = 1;
	}
	return (err);
}

char					*return_error_float(t_float_calc *f, t_fword *container)
{
	if (f->nan && f->flag == 'f')
		return (f->float_string = ft_strdup("nan"));
	if (f->nan && f->flag == 'F')
		return (f->float_string = ft_strdup("NAN"));
	if (f->inf_m && f->flag == 'f')
		return (f->float_string = ft_strdup("-inf"));
	if (f->inf_m && f->flag == 'F')
		return (f->float_string = ft_strdup("-INF"));
	if (f->inf_p && f->flag == 'f' && container->space_plus == 2)
		return (f->float_string = ft_strdup("+inf"));
	if (f->inf_p && f->flag == 'F' && container->space_plus == 2)
		return (f->float_string = ft_strdup("+INF"));
	if (f->inf_p && f->flag == 'f')
		return (f->float_string = ft_strdup("inf"));
	if (f->inf_p && f->flag == 'F')
		return (f->float_string = ft_strdup("INF"));
	return (NULL);
}

void					add_filler_signe_double(t_fword *container,
						t_float_calc *f, long double *number)
{
	int					i;

	i = -1;
	while (++i < f->length)
		f->float_string[i] = container->filler;
	if (f->sign_bit)
	{
		f->float_string[f->length - 1] = '-';
		f->sign = &(f->float_string[f->length - 1]);
		*number = *number * (-1);
	}
	else if ((*number > 0 && container->space_plus == 2)
		|| (container->space_plus == 2 && !(f->sign_bit)))
	{
		f->float_string[f->length - 1] = '+';
		f->sign = &(f->float_string[f->length - 1]);
	}
	f->end = &(f->float_string[f->length]);
}
