/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_short_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:48:49 by mschimme          #+#    #+#             */
/*   Updated: 2019/10/28 22:54:25 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_get_uns_short_short(t_fword *container, char *buff)
{
	unsigned char	res;

	res = (unsigned char)va_arg(*container->variative, unsigned int);
	if (!res)
		return (buff + container->precision);
	return (ft_uintoa((unsigned long long int)res, buff, container->precision));
}
