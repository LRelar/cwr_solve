/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_short.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:48:49 by mschimme          #+#    #+#             */
/*   Updated: 2019/10/28 22:46:43 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_get_hex_short(t_fword *container, char **buff)
{
	unsigned short int	res;

	res = (unsigned short int)va_arg(*container->variative, unsigned int);
	if (!res)
		return (*buff + container->precision);
	return (ft_uintoa_base((unsigned long long int)res, buff, \
												16, container->precision));
}
