/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:44:46 by kokeefe           #+#    #+#             */
/*   Updated: 2020/09/13 21:37:28 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

/*
** A stripped down version of parse_format, whose task:
** 1. Determine the number of available variations, as correctly specified in%,
** so called through * or incorrectly executed%.
** 2. Determine the sequence in working with options (if used)
** at least one n $, then there is no room for * and% without n $.
*/

/*
**				ft_search_formword
** Analog (derivative) of ft_seach_anchors.
*/

inline static uint8_t	ft_search_formword(t_format *scanstat)
{
	const char			*ptr;
	const char			*endptr;
	const char			*pcsignptr;

	ptr = scanstat->sight;
	endptr = scanstat->end;
	pcsignptr = (char *)ft_memchr((const void *)ptr, '%', endptr - ptr);
	if (pcsignptr)
	{
		scanstat->sight = pcsignptr;
		return (0);
	}
	scanstat->sight = scanstat->marker;
	return (1);
}

/*
** 				ft_scan_string
** The analogue (derivative) of ft_parse_format.c
** Creeps (due to) the function stored in
*/

uint8_t					ft_scan_string(t_format *scanstat)
{
	while (!(ft_search_formword(scanstat)))
	{
		if (ft_scan_form_word(scanstat))
			return (1);
	}
	ft_check_vari_cont_chain(scanstat);
	return (0);
}
