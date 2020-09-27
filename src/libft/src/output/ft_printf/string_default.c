/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_default.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:39:53 by kokeefe           #+#    #+#             */
/*   Updated: 2020/09/14 01:17:50 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				ft_value_colour(const char *sight)
{
	if (!(ft_memcmp(sight, "{red}", 5)))
		return ((int)(sizeof("\x1b[31m") - sizeof("{red}")));
	if (!(ft_memcmp(sight, "{green}", 7)))
		return ((int)(sizeof("\x1b[32m") - sizeof("{green}")));
	if (!(ft_memcmp(sight, "{yellow}", 8)))
		return ((int)(sizeof("\x1b[33m") - sizeof("{yellow}")));
	if (!(ft_memcmp(sight, "{blue}", 6)))
		return ((int)(sizeof("\x1b[34m") - sizeof("{blue}")));
	if (!(ft_memcmp(sight, "{magneta}", 9)))
		return ((int)(sizeof("\x1b[35m") - sizeof("{magneta}")));
	if (!(ft_memcmp(sight, "{cyan}", 6)))
		return ((int)(sizeof("\x1b[36m") - sizeof("{cyan}")));
	if (!(ft_memcmp(sight, "{eoc}", 5)))
		return ((int)(sizeof("\x1b[0m") - sizeof("{eoc}")));
	return (0);
}

static uint8_t			ft_install_colour(char **res, const char **bogey, \
												const char *colour, int offset)
{
	size_t				length;

	length = ft_strlen(colour);
	ft_memcpy(*res, colour, length);
	*res += length;
	*bogey += offset;
	return (1);
}

static uint8_t			ft_pick_colour(char **res, const char **bogey)
{
	uint8_t				flag;

	flag = 0;
	if (!(ft_memcmp(*bogey, "{red}", 5)))
		flag = ft_install_colour(res, bogey, "\x1b[31m", 5);
	else if (!(ft_memcmp(*bogey, "{green}", 7)))
		flag = ft_install_colour(res, bogey, "\x1b[32m", 7);
	else if (!(ft_memcmp(*bogey, "{yellow}", 8)))
		flag = ft_install_colour(res, bogey, "\x1b[33m", 8);
	else if (!(ft_memcmp(*bogey, "{blue}", 6)))
		flag = ft_install_colour(res, bogey, "\x1b[34m", 6);
	else if (!(ft_memcmp(*bogey, "{magneta}", 9)))
		flag = ft_install_colour(res, bogey, "\x1b[35m", 9);
	else if (!(ft_memcmp(*bogey, "{cyan}", 6)))
		flag = ft_install_colour(res, bogey, "\x1b[36m", 6);
	else if (!(ft_memcmp(*bogey, "{eoc}", 5)))
		flag = ft_install_colour(res, bogey, "\x1b[0m", 5);
	return (flag);
}

static char				*ft_form_string(char *res, const char *varg, \
						size_t varglen)
{
	const char			*colour;
	const char			*bogey;
	char				*ptr;
	const char			*end;

	colour = varg;
	bogey = varg;
	ptr = res;
	end = varg + varglen;
	while (colour && (colour = ft_memchr(colour, '{', end - colour)))
	{
		ft_memcpy(ptr, bogey, colour - bogey);
		ptr += colour - bogey;
		if (!(ft_pick_colour(&ptr, &colour)))
			*ptr++ = *colour++;
		bogey = colour;
	}
	ft_memcpy(ptr, bogey, end - bogey);
	return (res);
}

char					*ft_get_string_default(t_fword *container)
{
	char				*variative;
	char				*sub;
	char				*endsub;
	int					extra_len;

	extra_len = 0;
	if (!(sub = (char *)va_arg(*container->variative, char *)))
		sub = "(null)";
	variative = sub;
	endsub = sub + ft_strlen((const char *)sub);
	while ((variative = ft_memchr((const void *)variative, '{', \
									endsub - variative)))
		extra_len += ft_value_colour(variative++);
	if (!(variative = (char *)ft_memalloc(endsub - sub + extra_len + 1)))
		return (NULL);
	return (ft_form_string(variative, sub, endsub - sub));
}
