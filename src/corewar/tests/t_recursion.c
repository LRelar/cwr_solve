/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:07:28 by mschimme          #+#    #+#             */
/*   Updated: 2020/05/06 08:57:31 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deblib.h>

static void ft_nope(int *i)
{
	static int k;

	if (k < 3)
		*i = 2;
	k++;
}

static void ft_recurstion(void)
{
	static int i;

	DEBintt(i) DEBend()
	i++;
	if (i == 3)
		ft_nope(&i);
	if (i < 5)
		ft_recurstion();
}

int main(void)
{
	ft_recurstion();
}