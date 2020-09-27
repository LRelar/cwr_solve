/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfalif_libft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:09:54 by ycorrupt          #+#    #+#             */
/*   Updated: 2020/09/13 22:22:47 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFALIF_LIBFT_H
# define SFALIF_LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

/*
**	Frobidden macro:
**	# define SIZE(type, n) sizeof(type) * (n)
*/

typedef struct	s_array
{
	void		**ptr;
	size_t		len;
	size_t		max;
}				t_array;

int				ft_isspace(int c);
long long int	ft_atoix(char *str);
int				ft_isdigit(int c);
int				ft_charinstr(const char *str, char c);
int				ft_strendwith(char *str, char *end);
int				str_num_eq(long num, char *str);
int				ft_mod(long int num);
char			*ft_strreplace(char const *str, char *orig, char *sub);
char			*ft_strreplacefirst(char const *str, char *orig, char *sub);
char			*ft_strreplacelast(char const *str, char *orig, char *sub);
void			ft_strtolower_pr(char *str);
char			*ft_strstrlst(const char *haystack, const char *needle);
int				ft_isnumber(char *str);
long long		ft_maxint(unsigned char bytes, int unsig);
long long		ft_atoil(const char *str);

#endif
