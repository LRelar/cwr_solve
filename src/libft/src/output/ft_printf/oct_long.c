/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:48:49 by mschimme          #+#    #+#             */
/*   Updated: 2019/10/28 22:52:00 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_get_oct_long(t_fword *container, char **buff)
{
	unsigned long int	res;

	res = (unsigned long int)va_arg(*container->variative, unsigned long int);
	if (!res)
		return (*buff + container->precision);
	return (ft_uintoa_base((unsigned long long int)res, buff, 8, \
														container->precision));
}
