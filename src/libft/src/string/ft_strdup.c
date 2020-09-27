/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:00:43 by mschimme          #+#    #+#             */
/*   Updated: 2019/02/22 18:54:40 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We use NULL, thus we need libft.h in order to include stdlib.h
** 	What the hex going on!? First we count length with ft_strlen, adding +1 to
** include \0, then we do memcpy and return it with casting into char *.
*/

char		*ft_strdup(const char *s1)
{
	char	*sub_res;

	if (!(sub_res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	return (ft_strcpy(sub_res, s1));
}
