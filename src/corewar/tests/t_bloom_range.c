/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_bloom_range.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 12:10:18 by mschimme          #+#    #+#             */
/*   Updated: 2020/05/06 18:27:28 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deblib.h>
#include <string.h>

#define hasbetween(x,m,n) \
((~0UL / 255 * (127 + (n)) - ((x) & ~0UL / 255 * 127) & ~(x) & ((x) & ~0UL / 255 * 127) + ~0UL / 255 * (127 - (m))) & ~0UL / 255 * 128)

#define _PUSHUP_(x, n) ~0UL / 255 * (127 + (n)) - ((x) & ~0UL / 255 * 127)
#define _PLDWN_(x, m) ~(x) & ((x) & ~0UL / 255 * 127) + ~0UL / 255 * (127 - (m))
#define BYTEINRANGE(x, m, n) _PUSHUP_(x, n) & _PLDWN_(x, m) & ~0UL / 255 * 128


// int main (void)
// {
// 	char *buff = "What a day what a lovelyadsfja;nsgbja;flajewfeжопа пйцукзнехнегхнеъфыдлоавровтчбьмсячюё.ячсёсwahfkldsafjpvijaierl...Did it work?";
// 	size_t	*ptr = &buff[0];
// 	int n = strlen(&buff[0]);
// 	int k = n / sizeof(size_t);
// 	while (k--)
// 	{
// 		if (BYTEINRANGE(*ptr, 1, 31))
// 		{
// 			DEBtextt((char *)ptr);
// 			break ;
// 		}
// 		ptr++;
// 	}

// 	return (0);
// }

int main (void)
{
	// return (BYTEINRANGE(50, 40, 180));
	return (0 % 3);
}