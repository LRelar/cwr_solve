/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 21:07:13 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 08:15:26 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_assholder(char **ptr)
{
	static char	array[256];
	int			i;

	if (*(size_t *)array != 506097522914230528UL)
	{
		i = 0;
		*ptr = array;
		while (i < 256)
		{
			if (i > '@' && i < '[')
			{
				array[i] = i + 32;
				i++;
				continue ;
			}
			array[i] = i;
			i++;
		}
	}
}

int			ft_strcasecmp(const char *s1, const char *s2)
{
	static char			*ptr;
	unsigned const char	*uns1;
	unsigned const char	*uns2;

	uns1 = (unsigned const char *)s1;
	uns2 = (unsigned const char *)s2;
	ft_assholder(&ptr);
	while ((*(ptr + *uns1)) == (*(ptr + *uns2)))
	{
		if (*uns1 == '\0')
			return (0);
		uns1++;
		uns2++;
	}
	return ((*(ptr + *uns1)) - (*(ptr + *uns2)));
}
