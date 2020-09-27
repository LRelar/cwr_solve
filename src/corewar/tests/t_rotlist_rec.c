/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rotlist_rec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:22:35 by mschimme          #+#    #+#             */
/*   Updated: 2020/06/30 17:36:34 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

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

static uint8_t			ft_lstrot_arr(t_list **alst)
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
		free (array);
		return (0);
	}
	return (1);
}


static t_list *ft_rotlist_rec(t_list *current, t_list *prev)
{
	t_list *new_head;
	
	if (current->next)
	{
		new_head = ft_rotlist_rec(current->next, current);
		current->next = prev;
		return (new_head);
	}
	current->next = prev;
	return (current);
}

int main(void)
{
	t_list		*head;
	head = NULL;
	
	for (int i = 0; i < 10; i++)
	{
		ft_lstadd(&head, ft_lstnew_r(&i, i));
	}
	// head = ft_rotlist_rec(head, NULL);
	ft_lstrot_arr(&head);
	DEBmesst("Did it work!?") DEBend()
	return (0);
}