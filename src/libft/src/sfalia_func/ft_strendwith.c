/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendwith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfalia-f <sfalia-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:09:38 by sfalia-f          #+#    #+#             */
/*   Updated: 2020/01/26 17:29:52 by sfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strendwith(char *str, char *end)
{
	int e_count;
	int s_count;

	e_count = ft_strlen(end);
	s_count = ft_strlen(str);
	if (e_count > s_count || ft_strcmp(str + (s_count - e_count), end))
		return (0);
	return (1);
}
