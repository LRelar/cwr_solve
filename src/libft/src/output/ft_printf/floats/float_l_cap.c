/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_l_cap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:17:56 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/28 22:18:06 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_get_float_l_cap(t_fword *container, char parent)
{
	long double			number;
	t_float_calc		f;

	ft_bzero(&f, sizeof(f));
	f.flag = parent;
	number = (long double)va_arg(*container->variative, long double);
	return (ft_form_double(container, number, &f));
}
