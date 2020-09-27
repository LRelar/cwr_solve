/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:06:16 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/27 18:07:18 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t					ft_flag_hash_dummy(const char *ptr)
{
	if (*ptr == '#')
		return (1);
	return (0);
}

uint8_t					ft_flag_hash(const char *ptr, t_fword *format)
{
	if (*ptr == '#')
	{
		format->hash = 1;
		return (1);
	}
	return (0);
}
