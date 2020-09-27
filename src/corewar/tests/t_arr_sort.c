/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_arr_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 13:16:00 by mschimme          #+#    #+#             */
/*   Updated: 2020/08/23 22:35:13 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

/*
**	Lunch key:	sh ./t_compiler.sh t_arr_sort "./src/prep_rout/prep_battle.c ./src/serv/proxies.c ./src/serv/cyc_cycsol_cmp.c ./src/serv/manage_world.c"
*/

void		ft_populate_cycles(t_vasa **head, size_t amount)
{
	size_t	i = 0;

	ft_printf("Initial set\n");
	while (i != amount)
	{
		ft_lstadd((t_list **)head, ft_lstnew_r(NULL, 0));
		(*head)->gen.cyc_sol = (size_t)arc4random();
		ft_printf("%zu\t", (*head)->gen.cyc_sol);
		i++;
		(*head)->content_size = (size_t)i;
	}
	DEBend()
}

void		ft_check_output(t_world *nexus)
{
	t_vasa	*ptr = nexus->cyc.cyc_to_dump;
	uint8_t	flag = 0;
	
	DEBmesst("Sorted elements:") DEBend()
	while (ptr)
	{
		ft_printf("%zu\t", ptr->gen.cyc_sol);
		if (ptr->next && ptr->gen.cyc_sol > ptr->next->gen.cyc_sol)
			flag = 1;
		ptr = ptr->next;
	}
	DEBend()
	if (flag)
		DEBmesst("Sorting failed \n")
}

void		ft_test_cyc_sol(void)
{
	t_world	nexus;
	size_t	amount = 10;

	ft_bzero(&nexus, sizeof(nexus));
	ft_populate_cycles(&nexus.cyc.cyc_to_dump, amount);
	ft_prep_battle(&nexus, 5);
	ft_check_output(&nexus);
}

int			main(void)
{
	int		amount = 10;
	t_list	*str_arr = ft_memalloc(amount * sizeof(t_list));
	t_list	**arr_ptr = ft_memalloc((amount + 1) * sizeof(t_list *));
	t_list	*head = NULL;
	
	ft_printf("Given values:\n");
	for (int i = 0; i < amount; i++)
	{
		str_arr[i].content_size = (size_t)arc4random();
		arr_ptr[i] = &str_arr[i];
		ft_printf("%zu\t", str_arr[i].content_size);
	}
	DEBend()
	ft_srt_listarr_bubble(&head, arr_ptr, amount, ft_lst_cntsz_left_grt_right);
	ft_printf("Sorted output (L -> M:)\n");
	for (t_list *ptr = head; ptr; ptr = ptr->next)
	{
		ft_printf("%zu\t", ptr->content_size);
	}
	DEBend()

	ft_test_cyc_sol();
	return (0);
}