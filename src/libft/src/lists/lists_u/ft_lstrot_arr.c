/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrot_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:40:20 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:23:02 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Sister function to ft_lstrot_rec. It allocates mamory though and uses
**	arrays in order to rotate t_list chain. Def-ly uses less mamory than
**	sister as the memory consumed only 1 stack-frame for both funtions
**	+ 8 * amount of t_list chain elements bytes.
**	SAFE FUNCTION.
**	HOW TO USE:
** if (ft_lstrot_arr(&ptr))
**		CATCH_ERROR
**	Where: t_list *ptr - a pointer to the chain head.
*/

inline static t_list	*ft_lstrot_swap(t_list **array, t_list *head, \
																size_t amount)
{
	size_t				i;

	i = 0;
	while (i != amount)
	{
		array[i++] = head;
		head = head->next;
	}
	while (i)
	{
		i--;
		array[i]->next = array[i - 1];
	}
	array[i]->next = NULL;
	return (array[amount - 1]);
}

uint8_t					ft_lstrot_arr(t_list **alst)
{
	t_list				*ptr;
	size_t				counter;
	t_list				**array;

	if (alst && *alst)
	{
		ptr = *alst;
		counter = 0;
		while (ptr)
		{
			counter++;
			ptr = ptr->next;
		}
		if (!(array = (t_list **)ft_memalloc((counter + 1) * sizeof(ptr))))
			return (2);
		*alst = ft_lstrot_swap(array, *alst, counter);
		free(array);
		return (0);
	}
	return (1);
}
