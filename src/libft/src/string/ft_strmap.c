/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:53:40 by mschimme          #+#    #+#             */
/*   Updated: 2019/03/02 22:19:31 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*pocket;
	char	*bogey;

	if (!s || !f)
		return (NULL);
	if (!(pocket = ft_strnew(ft_strlen(s))))
		return (NULL);
	bogey = pocket;
	while (*s != '\0')
		*bogey++ = f(*s++);
	return (pocket);
}
