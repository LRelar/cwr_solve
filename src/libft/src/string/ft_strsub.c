/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:28:03 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 21:38:49 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;

	if (!s || !(sub_s = ft_strnew(len)))
		return (NULL);
	s = s + start;
	ft_memcpy((void *)sub_s, (const void *)s, len);
	return (sub_s);
}
