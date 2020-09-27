/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 00:07:40 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 21:37:44 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t	size_s1;
	size_t	size_s2;

	size_s1 = ft_strlen(s1) + 1;
	size_s2 = ft_strlen(s2) + 1;
	if (size_s1 <= size_s2)
		return (ft_memcmp((const void *)s1, (const void *)s2, size_s1));
	else
		return (ft_memcmp((const void *)s1, (const void *)s2, size_s2));
}
