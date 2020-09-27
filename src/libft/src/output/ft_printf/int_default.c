/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:03:59 by mschimme          #+#    #+#             */
/*   Updated: 2019/10/28 22:49:14 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_get_int_default(t_fword *container, char *buff)
{
	int					res;

	res = (int)va_arg(*container->variative, int);
	if (!res)
		return (buff + container->precision);
	return (ft_intoa((long long int)res, buff, container->precision));
}
