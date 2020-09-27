/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_overflow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:18:48 by mschimme          #+#    #+#             */
/*   Updated: 2020/07/03 16:59:30 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cwr.h>
#include <termios.h>
#include <unistd.h>

void clean_stdin()
{
		int stdin_copy = dup(STDIN_FILENO);
/* remove garbage from stdin */
tcdrain(stdin_copy);
tcflush(stdin_copy, TCIFLUSH);
close(stdin_copy);
}


int			main(void)
{
	int fd = 0;
	char buff[10];

	ft_bzero(buff, sizeof(buff));
	
	while(read(fd, buff, 9))
	{
		if (*(int *)&buff[0] == 033 || !ft_strcasecmp(&buff[0], "no\n"))
		{
			DEBmesst("Exiting with doing nothing\n")
			tcflush(STDIN_FILENO, TCIFLUSH);
			break;
		}
		else if (*(int *)&buff[0] == '\n' || !ft_strcasecmp(&buff[0], "yes\n"))
		{
			DEBmesst("Continuing cuz affirmative.")
			tcflush(STDIN_FILENO, TCIFLUSH);
			break;
		}
		else
		{
			DEBmesst("Incorrect input. Try again:\n")
			tcflush(STDIN_FILENO, TCIFLUSH);
			ft_bzero(buff, sizeof(buff));
		}
	}
	
	return (0);
}