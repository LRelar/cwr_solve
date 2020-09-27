/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 22:03:59 by mschimme          #+#    #+#             */
/*   Updated: 2019/10/28 22:44:22 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	We add 1 to "shift" parameter of ft_uintoa_base call cuz we need to have
**	our string-number started at buff[0][2] position (for buff[0][0-1] to be
**	left for 0x or 0X HEX prefixes).
*/

char				*ft_get_hex_default(t_fword *container, char **buff)
{
	unsigned int	res;

	res = (unsigned int)va_arg(*container->variative, unsigned int);
	return (ft_uintoa_base((unsigned long long int)res, buff, \
												16, container->precision));
}
