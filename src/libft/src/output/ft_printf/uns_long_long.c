/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_long_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:48:49 by mschimme          #+#    #+#             */
/*   Updated: 2019/10/28 22:55:45 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char						*ft_get_uns_long_long(t_fword *container, \
																	char *buff)
{
	unsigned long long int	res;

	res = (unsigned long long int)va_arg(*container->variative, \
													unsigned long long int);
	if (!res)
		return (buff + container->precision);
	return (ft_uintoa((unsigned long long int)res, buff, container->precision));
}
