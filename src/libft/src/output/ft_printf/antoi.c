/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   antoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokeefe <kokeefe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:20:03 by kokeefe           #+#    #+#             */
/*   Updated: 2019/10/28 22:22:22 by kokeefe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**				ft_antoi
** Interval implementation of atoi that does not check state validity
** submitted line interval (the presence of an integer in it is presumed.)
** Returns status	(0) - if the work was completed without errors.
**					(-1) - if the work is performed with overflow up.
**					(1) - if the work is done with overflow down.
*/

uint8_t			ft_antoi(const char *start, const char *end, long long *res)
{
	*res = 0;
	while (start != end)
	{
		*res = (*res * 10) + (*start - '0');
		start += 1;
		if (*res > 223372036854775807 && *start == '9')
			return (1);
	}
	return (0);
}
