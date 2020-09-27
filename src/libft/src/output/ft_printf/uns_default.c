/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:03:59 by mschimme          #+#    #+#             */
/*   Updated: 2019/10/28 09:53:13 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_get_uns_default(t_fword *container, char *buff)
{
	unsigned int	res;

	res = (unsigned int)va_arg(*container->variative, unsigned int);
	if (!res)
		return (buff + container->precision);
	return (ft_uintoa((unsigned long long int)res, buff, container->precision));
}
