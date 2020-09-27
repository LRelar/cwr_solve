/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 19:07:47 by mschimme          #+#    #+#             */
/*   Updated: 2019/03/01 19:54:30 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	const char	*bogey;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == '\0')
		return (ft_strnew(0));
	bogey = s + ft_strlen(s) - 1;
	while (*bogey == ' ' || *bogey == '\t' || *bogey == '\n')
		bogey--;
	return (ft_strsub(s, 0, bogey - s + 1));
}
