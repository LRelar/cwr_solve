/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:08:08 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/14 00:06:38 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Forbidden MACRO (used in ft_hopper right after second if)
**	#define CPY_FST ft_memcpy((void *)ar[2], (t_cv *)ar[0]->CNT, \
**	ar[0]->C_S)
**	#define CPY_LST(x) ft_memcpy((x) + ar[0]->C_S, (t_cv *)ar[1]->CNT, \
**	ar[1]->C_S);
*/

typedef const void	t_cv;

#define SZF sizeof

int	g_gnl_read;

/*
**	Former 5th string of ft_hopper.
**		ft_memcpy(ft_memcpy((void *)ar[2], (CV *)ar[0]->CNT, ar[0]->C_S) + \
**				ar[0]->C_S, (CV *)ar[1]->CNT, ar[1]->C_S);
*/

/*
** ft_lstmk doest 3 things (according to it's flag _fl_).
** For flag > 1 it creates new empy list (with no fluff).
** If flag == 2 it creates LST with content of size INT to write in a FD num.
** If flag == 3 it creates LST with content of size BUFF_SIZE + 1 for BuffList.
** Successfull creation of LST returns 0.
** If list creation is failed or memory allocation for content is failed,
** It's considered as critical error, function frees any of memory allocated.
** Flag == 0 means it's time to destroy fd-lists constraction.
*/

static int			ft_lstmk(int fl, t_list **lst, int val, t_list **fd_lst)
{
	if (fl > 1)
	{
		if (!(*lst = ft_lstnew(NULL, 0)))
		{
			ft_lstdel(fd_lst, &ft_del);
			return (-1);
		}
		if ((fl == 2) && !((*lst)->CNT = ft_memalloc(SZF(int))))
		{
			ft_lstdel(fd_lst, &ft_del);
			*lst = NULL;
			return (-1);
		}
		if ((fl == 3) && !((*lst)->CNT = ft_memalloc(BUFF_SIZE + 1)))
		{
			ft_lstdel(fd_lst, &ft_del);
			*lst = NULL;
			return (-1);
		}
		(*lst)->C_S = SZF(int);
		(*(int *)((*lst)->CNT)) = val;
		return (0);
	}
	ft_lstdel(lst, &ft_del);
	return (-1);
}

/*
** ft_fdr does 3 things:
** Creates fd_lsts if no list of a given fd is found.
** Links them together (in the way, opposite to ft_lstadd), new list is being
** added to the end of the chain.
** Picks up propper list, scanning first 4 bytes of lst->content.
*/

static t_list		*ft_fdr(t_list **fd_lst, int fd, t_list *last, \
								t_list *pr)
{
	if (fd == -1)
		return (NULL);
	if (!(*fd_lst))
	{
		if (ft_lstmk(2, fd_lst, fd, fd_lst) == -1)
			return (NULL);
		return (*fd_lst);
	}
	else
	{
		while (last)
		{
			if (*(int *)(last->CNT) == fd)
				return (last);
			if (last->next == NULL)
				pr = last;
			last = last->next;
		}
		if (ft_lstmk(2, &(pr->next), fd, fd_lst) == -1)
			return (NULL);
		return (pr->next);
	}
}

/*
** ft_rs (ft_remain scanner) does few things.
** It searches '\n' or '\0' in given fd_list.
** If both of them are found, it choses the closest to beginning of the string.
** It creates substring for *line, modding fd_list->content and ->content_size.
** bgy[0] - pointer to slide along the fd_list->content. It tries to point at
** '\n' or '\0' in it.
** bgy[1] - pointer to a new version of fd_list->content, created after
** *line substring is substracted.
** bgy[2] - pointer to search for '\0'. Sole purpose pointer to give its value
** to bgy[0] if a '\0' closer to fd_list->content is found.
** Function returns 0 if something found in fd_lst->content is found.
** Otherwise it returns 2. Why not?!
*/

static int			ft_rs(char **line, t_list *rem, t_list **fd_lst)
{
	void			*bgy[3];

	bgy[0] = ft_memchr((t_cv *)rem->CNT + SZF(int), '\n', rem->C_S - SZF(int));
	if ((bgy[0]) && (bgy[0] += 1))
	{
		if (!((*line) = ft_memalloc(bgy[0] - rem->CNT - SZF(int))))
			return (ft_lstmk(2, fd_lst, 0, fd_lst));
		ft_memcpy((void *)(*line), (t_cv *)rem->CNT + SZF(int), bgy[0] - \
													rem->CNT - 1 - SZF(int));
		if (*(char *)(bgy[0] - 1) == '\0' && (bgy[0] - 1) != rem->CNT + \
																	SZF(int))
			bgy[0] -= 1;
		g_gnl_read = (int)(bgy[0] - rem->CNT - SZF(int) - 1);
		rem->C_S -= (bgy[0] - rem->CNT - SZF(int));
		if (!(bgy[1] = (ft_memalloc(rem->C_S))))
			return (ft_lstmk(2, fd_lst, 0, fd_lst));
		ft_memcpy(bgy[1] + SZF(int), (t_cv *)bgy[0], rem->C_S - SZF(int));
		*(int *)bgy[1] = *(int *)rem->CNT;
		free(rem->CNT);
		rem->CNT = bgy[1];
		return (0);
	}
	return (2);
}

/*
** ft_rs processes cases when either are yet in search of '\0' or '\n' or
** ened up to come to an end of file without finding these symbols.
** In first case functiong concatenates apropriate fd_list->content (ar[0])
** with BUFF->content (ar[1]).
** In second case it transferes rem to *line, preparing fd_list for next use
** or destroing whole chain (depends on status of other elements of chain).
*/

/*
**	replaced by ft_replace_cnt:
**		free(ar[0]->CNT);
**		ar[0]->CNT = (void *)ar[2];
**		ar[0]->C_S += ar[1]->C_S;
**		ft_lstdelone(&ar[1], &ft_del);
*/

static int			ft_hopper(t_list **ar, t_list **fdl, char **lin, size_t fl)
{
	if (fl == 1)
	{
		if (!(ar[2] = (t_list *)ft_memalloc(ar[0]->C_S + ar[1]->C_S)))
			return (ft_lstmk(2, fdl, 0, fdl));
		ft_memcpy(ft_memcpy((void *)ar[2], (t_cv *)ar[0]->CNT, ar[0]->C_S) + \
								ar[0]->C_S, (t_cv *)ar[1]->CNT, ar[1]->C_S);
		ft_replace_cnt(ar[0], &ar[1], (void *)ar[2]);
		return (get_next_line(*(const int *)(ar[0]->CNT), lin));
	}
	if (!((*lin) = (char *)ft_memalloc(ar[0]->C_S - SZF(int) + 1)))
		return (ft_lstmk(2, fdl, 0, fdl));
	ft_memcpy((void *)(*lin), (t_cv *)ar[0]->CNT + SZF(int), ar[0]->C_S - \
																	SZF(int));
	ft_bzero(ar[0]->CNT + SZF(int), ar[0]->C_S - SZF(int));
	g_gnl_read = (int)(ar[0]->C_S) - (int)SZF(int);
	ar[0]->C_S = SZF(int);
	ar[2] = *fdl;
	fl += ar[2]->C_S - SZF(int);
	while ((ar[2] = ar[2]->next))
		fl += ar[2]->C_S - SZF(int);
	if (fl == 0)
		ft_lstdel(fdl, &ft_del);
	ft_lstdelone(&ar[1], &ft_del);
	return (1);
}

/*
** Nexus function. Gets proper fd_lst, evalueates result of remain scanner.
** Creates buffer (if required).
** Destrois list chain (like in Hopper) when needed.
** pl[0] - for proper fd_list.
** pl[1] - for buffer list.
** pl[2] - points at fdl when need to evaluate chain of lits state.
** ss[0] - holds return of remain scanner.
** ss[1] - is used to calculate chain of lists state. If it's evaluated to
** == 0, that means we're processing last of file descriptors given, thus
** chain of lists is ought to be destroyed (freed). Otherwise there are
** file descriptors that've not reached the end of file.
*/

int					get_next_line(const int fd, char **line)
{
	static t_list	*fdl;
	t_list			*pl[3];
	int				ss[2];

	if (!((pl[0] = ft_fdr(&fdl, fd, fdl, fdl)) && !(BUFF_SIZE < 1) && \
			((ss[0] = ft_rs(line, pl[0], &fdl)) != -1)))
		return (-1);
	if (ss[0] == 0)
		return (1);
	if ((pl[2] = fdl) && (ft_lstmk(3, &pl[1], 0, &fdl) == -1))
		return (-1);
	if ((ss[1] = read(fd, pl[1]->CNT, BUFF_SIZE)) == -1)
		return (ft_wipegnl(&fdl, pl[0], pl[1], pl[2]));
	if ((pl[1]->C_S = (size_t)ss[1]) != 0)
		return (ft_hopper(pl, &fdl, line, 1));
	if (pl[0]->C_S - SZF(int) == 0 && !(*line = NULL))
	{
		pl[1]->C_S += pl[2]->C_S - SZF(int);
		while ((pl[2] = pl[2]->next))
			pl[1]->C_S += pl[2]->C_S - SZF(int);
		if (pl[1]->C_S == 0)
			ft_lstdel(&fdl, &ft_del);
		return (ft_lstmk(0, &pl[1], 0, NULL) + 1);
	}
	return (ft_hopper(pl, &fdl, line, 0));
}
