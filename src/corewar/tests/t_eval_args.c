/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_eval_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 22:01:06 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 14:28:24 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>

int				main(void)
{
	t_world		nexus;
	t_carry		carry;
	t_dvasa		*tree = NULL;
	t_dvasa		*vacant = NULL;

	ft_bzero(&nexus, sizeof(nexus));
	ft_bzero(&carry, sizeof(carry));
	nexus.arena[0] = 14;
	nexus.arena[1] = 0xE4;
	nexus.arena[6] = 10;
	op_lldi(&nexus, &carry, tree, &vacant);
	return (0);
}