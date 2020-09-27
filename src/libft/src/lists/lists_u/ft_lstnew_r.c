/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 21:05:13 by mschimme          #+#    #+#             */
/*   Updated: 2019/11/30 14:55:04 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This function creates new list and _links_ given content with it. It does
**	not dupes content data as it is done my standard ft_lstnew.
*/

t_list		*ft_lstnew_r(void const *content, size_t content_size)
{
	t_list	*result;

	if (!(result = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	result->content = (void *)content;
	if (content)
		result->content_size = content_size;
	return (result);
}
