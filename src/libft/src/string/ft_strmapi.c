/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:52:10 by mschimme          #+#    #+#             */
/*   Updated: 2019/03/02 22:19:27 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	bogey;
	char	*pocket;

	if (!s || !f)
		return (NULL);
	bogey = 0;
	if (!(pocket = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[bogey] != '\0')
	{
		pocket[bogey] = f(bogey, s[bogey]);
		bogey++;
	}
	return (pocket);
}
