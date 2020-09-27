/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 00:09:51 by mschimme          #+#    #+#             */
/*   Updated: 2019/02/12 16:32:25 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use NULL and size_t, thus we need libft.h in order to include stdlib.h
*/

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*sub_res;

	sub_res = dst;
	while (*src != '\0' && 0 < len)
	{
		*dst++ = *src++;
		--len;
	}
	while (0 < len)
	{
		*dst++ = '\0';
		--len;
	}
	return (sub_res);
}
