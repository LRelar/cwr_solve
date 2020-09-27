/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 22:52:48 by sfalia-f          #+#    #+#             */
/*   Updated: 2020/08/20 00:42:49 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplace(char const *str, char *orig, char *sub)
{
	char	*rez[3];
	int		len[2];

	if (!str || !orig || !sub)
		return (NULL);
	rez[0] = (char *)str;
	len[1] = ft_strlen(sub);
	rez[2] = 0;
	if (!(len[0] = ft_strlen(orig)))
		return (ft_strdup(str));
	while ((rez[0] = ft_strstr(rez[0], orig)))
		if (++rez[2])
			rez[0] += len[0];
	if (!(rez[0] = ft_strnew(ft_strlen(str) + (len[1] - len[0]) * (int)rez[2])))
		return (NULL);
	rez[1] = rez[0];
	while (*str)
	{
		rez[2] = ft_strstr(str, orig);
		rez[2] ? ft_strncpy(rez[0], str, rez[2] - str) : ft_strcat(rez[0], str);
		rez[0] += rez[2] ? (rez[2] - str) + len[1] : 0;
		rez[2] ? ft_strcat(rez[0] - len[1], sub) : (NULL);
		str += rez[2] ? rez[2] - str + len[0] : ft_strlen(str);
	}
	return (rez[1]);
}

char	*ft_strreplacefirst(char const *str, char *orig, char *sub)
{
	char	*rez[3];
	int		len[2];

	if (!str || !orig || !sub)
		return (NULL);
	rez[0] = (char *)str;
	len[0] = ft_strlen(orig);
	len[1] = ft_strlen(sub);
	if (!len[0] || !(rez[2] = ft_strstr(str, orig)))
		return (ft_strdup(str));
	rez[0] = ft_strnew(ft_strlen(str) + (len[1] - len[0]));
	rez[1] = rez[0];
	ft_strncpy(rez[0], str, rez[2] - str);
	rez[0] += rez[2] - str;
	ft_strcat(rez[0], sub);
	ft_strcat(rez[0] + len[1], rez[2] + len[0]);
	return (rez[1]);
}

char	*ft_strreplacelast(char const *str, char *orig, char *sub)
{
	char	*rez[3];
	int		len[2];

	if (!str || !orig || !sub)
		return (NULL);
	rez[0] = (char *)str;
	len[0] = ft_strlen(orig);
	len[1] = ft_strlen(sub);
	if (!len[0] || !(rez[2] = ft_strstr(str, orig)))
		return (ft_strdup(str));
	rez[0] = ft_strnew(ft_strlen(str) + (len[1] - len[0]));
	rez[1] = rez[2];
	while ((rez[2] = ft_strstr(rez[2], orig)))
		rez[1] = rez[2]++;
	rez[2] = rez[1];
	rez[1] = rez[0];
	ft_strncpy(rez[0], str, rez[2] - str);
	rez[0] += rez[2] - str;
	ft_strcat(rez[0], sub);
	ft_strcat(rez[0] + len[1], rez[2] + len[0]);
	return (rez[1]);
}
