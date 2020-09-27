/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns_long_long_cap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:48:49 by mschimme          #+#    #+#             */
/*   Updated: 2019/10/28 22:54:08 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*ft_get_uns_long_cap(t_fword *container, char *buff)
{
	unsigned int	res;

	res = (unsigned int)va_arg(*container->variative, unsigned int);
	if (!res)
		return (buff + container->precision);
	return (ft_uintoa((unsigned long long int)res, buff, container->precision));
}
