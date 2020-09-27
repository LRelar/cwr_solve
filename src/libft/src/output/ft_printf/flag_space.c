/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:10:07 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/27 18:10:17 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uint8_t					ft_flag_space_dummy(const char *ptr)
{
	if (*ptr == ' ')
		return (1);
	return (0);
}

uint8_t					ft_flag_space(const char *ptr, t_fword *format)
{
	if (*ptr == ' ')
	{
		if (format->space_plus != 2)
			format->space_plus = 1;
		return (1);
	}
	return (0);
}
