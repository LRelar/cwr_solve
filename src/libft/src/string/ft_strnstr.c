/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 23:22:36 by mschimme          #+#    #+#             */
/*   Updated: 2019/03/07 21:14:36 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*camel;
	const char	*eye;
	size_t		cash;

	if (*needle == '\0')
		return ((char*)haystack);
	while (*haystack != '\0' && len != 0)
	{
		camel = haystack;
		eye = needle;
		cash = len;
		while (*eye != '\0' && *camel == *eye && cash != 0)
		{
			++eye;
			++camel;
			--cash;
		}
		if (*eye == '\0')
			return ((char*)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}
