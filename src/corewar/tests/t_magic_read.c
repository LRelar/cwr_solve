/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_magic_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:28:04 by mschimme          #+#    #+#             */
/*   Updated: 2020/06/30 14:26:39 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>


int		main(void)
{
	uint8_t		*buff= "\000\xea\x83\xf3";
	
	RTP			container;
	FILE		*stream;
	stream = fopen("./tests/t_magic.txt", "w+");
	fwrite(&buff[0], 4, 1, stream);
	fclose(stream);
	stream = NULL;
	
	stream = fopen("./tests/t_magic.txt", "r");
	container = 0;
	fread(&container, 4, 1, stream);
	fclose(stream);
	
	RTP			swap;
	swap = _SW_ENDIAN(COREWAR_EXEC_MAGIC);
	if (swap != container)
		DEBmesst("OOPS!")
	DEBend();

	return (0);
}