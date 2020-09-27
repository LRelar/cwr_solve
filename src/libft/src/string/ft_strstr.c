/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 00:10:15 by mschimme          #+#    #+#             */
/*   Updated: 2019/02/12 15:50:02 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use NULL, thus we need libft.h in order to include stdlib.h
*/

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*camel;
	const char	*eye;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0')
	{
		camel = haystack;
		eye = needle;
		while (*eye != '\0' && *camel == *eye)
		{
			++eye;
			++camel;
		}
		if (*eye == '\0')
			return ((char*)haystack);
		++haystack;
	}
	return (NULL);
}
