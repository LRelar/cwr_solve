/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:43:21 by kokeefe           #+#    #+#             */
/*   Updated: 2020/09/13 21:37:21 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline uint8_t	ft_set_existing_anchor(t_format *formstat, \
						const char *braceptr, const char *pcsignptr)
{
	if (braceptr)
	{
		formstat->sight = braceptr;
		formstat->parse_sight = &ft_check_colour;
		return (0);
	}
	if (pcsignptr)
	{
		formstat->sight = pcsignptr;
		formstat->parse_sight = &ft_check_form_word;
		return (0);
	}
	formstat->sight = NULL;
	formstat->parse_sight = NULL;
	return (1);
}

uint8_t					ft_seach_anchors(t_format *formstat)
{
	const char			*ptr;
	const char			*endptr;
	const char			*braceptr;
	const char			*pcsignptr;

	ptr = formstat->sight;
	endptr = formstat->end;
	braceptr = ft_memchr((const void *)ptr, '{', endptr - ptr);
	pcsignptr = ft_memchr((const void *)ptr, '%', endptr - ptr);
	if (braceptr && pcsignptr)
	{
		if (braceptr < pcsignptr)
		{
			formstat->sight = braceptr;
			formstat->parse_sight = &ft_check_colour;
		}
		else if (pcsignptr < braceptr)
		{
			formstat->sight = pcsignptr;
			formstat->parse_sight = &ft_check_form_word;
		}
		return (0);
	}
	return (ft_set_existing_anchor(formstat, braceptr, pcsignptr));
}

/*
**				ft_approach_anchor
** If we have found an anchor (anchor, valid color word or format word)
** we, write to the buffer, everything that was between the current
** marker position and sight (indicating the beginning of the anchor
** closest to the marker).
** There is a check for overflow ptr-> result. If this happened, we
** do not write anything to the buffer.
*/

static uint8_t			ft_approach_anchor(t_format *ptr)
{
	ssize_t				piece_len;
	ssize_t				overflow;

	piece_len = ptr->sight - ptr->marker;
	overflow = (ssize_t)(ptr->result) + piece_len;
	if (overflow < INT32_MIN || overflow > INT32_MAX)
		ptr->errflag = 1;
	if (ptr->errflag)
		return (1);
	ptr->result = overflow;
	filling_mainbuf(ptr->marker, (size_t)piece_len, 0, ptr->fd);
	ptr->marker += piece_len;
	return (0);
}

uint8_t					ft_parse_format(t_format *formstat)
{
	while (*(formstat->marker))
	{
		if (!(ft_seach_anchors(formstat)))
		{
			if (ft_approach_anchor(formstat))
				return (1);
			if (formstat->parse_sight(formstat))
				return (1);
			continue ;
		}
		formstat->sight = formstat->end;
		ft_approach_anchor(formstat);
	}
	return (0);
}
