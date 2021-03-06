/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanya <tanya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 23:25:30 by sfalia-f          #+#    #+#             */
/*   Updated: 2020/08/20 00:40:17 by tanya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strtolower_pr(char *str)
{
	if (str)
		while (*str)
			if (*str >= 'A' && *str <= 'Z')
				*str += 0x20;
}
