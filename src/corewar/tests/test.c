/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 22:40:49 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/26 13:38:17 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

static t_carry	*ft_init_carry(uint8_t op)
{
	static int	id;
	t_carry		*entry;

	entry = (t_carry *)ft_memalloc(sizeof(t_carry));
	entry->id = id++;
	entry->op = op;
	return (entry);
}

int				main(void)
{
	t_carry		*carry;
	t_vasa		*check;

	check = (t_vasa *)ft_lstnew_r((void *)ft_init_carry(1), sizeof(t_carry));
	ft_lstadd((t_list **)&check, ft_lstnew((void *)ft_init_carry(2),
	sizeof(t_carry)));
	return (0);
}
