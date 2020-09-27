/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:48:49 by mschimme          #+#    #+#             */
/*   Updated: 2019/10/28 22:51:08 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_get_int_long(t_fword *container, char *buff)
{
	long int			res;

	res = (long int)va_arg(*container->variative, long int);
	if (!res)
		return (buff + container->precision);
	return (ft_intoa((long long int)res, buff, container->precision));
}
