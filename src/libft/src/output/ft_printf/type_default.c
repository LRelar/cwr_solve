/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_default.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <mschimme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:30:05 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/28 22:45:29 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	This function is executed IF and only if parsing format word we didn't
**	find known format type (c, s, f et cetera...);
**	This function is ought to iterate va_arg, place
*/

char					*ft_get_variat(t_format *formstat, char *buffer)
{
	if (formstat->sight == formstat->end)
	{
		formstat->marker = formstat->end;
		return (NULL);
	}
	if (!(*(formstat->sight) & (1 << 7)))
		buffer[0] = *formstat->sight++;
	else if ((*formstat->sight & (15 << 4)) == (15 << 4))
	{
		*(uint32_t *)buffer = *(uint32_t *)(formstat->sight);
		formstat->sight += 4;
	}
	else if ((*formstat->sight & (14 << 4)) == (14 << 4))
	{
		ft_memcpy((void *)&buffer[0], (void *)formstat->sight, 3);
		formstat->sight += 3;
	}
	else if ((*formstat->sight & (6 << 5)) == (6 << 5))
	{
		*(uint16_t *)buffer = *(uint16_t *)(formstat->sight);
		formstat->sight += 2;
	}
	return (&buffer[0]);
}

uint8_t					ft_place_default(t_format *formstat, \
													t_fword *format)
{
	char				*variat;
	char				buffer[9];
	size_t				dims[2];

	if (formstat->errflag)
		return (1);
	*(uint64_t *)buffer = 0;
	buffer[8] = 0;
	variat = ft_get_variat(formstat, &buffer[0]);
	if (!variat)
		return (1);
	else
	{
		dims[0] = ft_strlen(variat);
		dims[1] = dims[0];
		format->ftp_width(formstat, format, &dims[0], variat);
		formstat->marker = formstat->sight;
	}
	return (0);
}
