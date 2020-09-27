/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 18:48:32 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 22:05:31 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*pocket;

	if (__builtin_umull_overflow(count, size, &total))
		return ((void *)(size_t)ft_err_varoverflow("total", __func__) - 1);
	if (!(pocket = malloc(total)))
		return ((void *)(size_t)ft_err_malloc("pocket", __func__) - 1);
	ft_bzero(pocket, total);
	return (pocket);
}
