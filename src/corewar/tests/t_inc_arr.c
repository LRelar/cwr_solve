/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_inc_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 22:40:33 by mschimme          #+#    #+#             */
/*   Updated: 2020/07/22 15:34:52 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>
/*
**	Проверял: Цикл корректно уложит адреса текущего значения ptr в
**	соответствующий элемент массива arr_ptr.

**	Результат: УСПЕШНО
*/

static void	ft_checkiterator_order(t_list **head, t_list **arr_ptr, size_t length)
{
	t_list	*ptr;
	size_t	bogey = 0;

	ptr = *head;

	if (!*arr_ptr)
	{
		while (ptr && bogey != length)
		{
			arr_ptr[bogey++] = ptr;
			ptr = ptr->next;
		}
	}
}

/*
**	Проверил: Цикл корректно уложит адреса текущего значения ptr в
**	соответствующий элемент массива arr_ptr без использования итератора (
**	инкрементом указателя).

**	Результат: УСПЕШНО. Сперва происходит разименовывание указателя bogey;
**	Затем происходит присвоение ему значения ptr, затем происходит итерация
**	к соседу текущего bogey.
*/
static void ft_checkincremetor_order(t_list **head, t_list **arr_ptr)
{
	t_list	**bogey = arr_ptr;
	t_list	*ptr = *head;

	while (ptr)
	{
		*bogey++ = ptr;
		ptr = ptr->next;
	}
	*bogey--;
	bogey++;
	bogey--;
}

int			main(void)
{
	t_list	array[20];
	t_list	*head = &array[0];
	t_list	**arr_ptr;

	ft_bzero(&array[0], sizeof(array));
	for (size_t i = 0; i != 20; i++)
		array[i].next = &array[i + 1];
	array[19].next = NULL;
	arr_ptr = ft_memalloc(20 * sizeof(t_list *));
	ft_checkiterator_order(&head, arr_ptr, 20);
	ft_bzero(arr_ptr, 20 * sizeof(t_list *));
	ft_checkincremetor_order(&head, arr_ptr);
}