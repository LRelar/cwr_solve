/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cost_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 11:21:43 by mschimme          #+#    #+#             */
/*   Updated: 2020/05/08 11:35:20 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>


void ft_give_string(char **ptr)
{
	*ptr = "Go Fuck yourself!\n";
	char *kek = "LOL LOL PIZDABOL!";
}

void ft_printstring(char *ptr)
{
	DEBtextt(ptr)
}

int main (void)
{
	char *ptr;

	ft_give_string(&ptr);

	ft_printstring(ptr);
	return (0);
}