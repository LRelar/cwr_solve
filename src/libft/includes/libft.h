/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:02:42 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/26 13:58:53 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
**	vasa.h  In Lingua in aeternum - contaier.
**	Defines contents of union u_generic, used in t_envel to give
**	t_envel contents context meaning...
*/

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include "ft_printf.h"
# include "sfalif_libft.h"

# define MHZERO 0x0101010101010101UL
# define DHZERO 0x8080808080808080UL
# define BUFF_SIZE 56
# define C_S content_size
# define CNT content

extern int			g_gnl_read;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef int			t_datacmp_rout(void *a, void *b);

/*
** Function prototypes taken in Mojave MacOS version (variable names slightly
** vary from version to version..
*/

uint8_t				ft_ctrl_detect(void *src, size_t length);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_calloc(size_t count, size_t size);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_bzero(void *s, size_t n);
int					ft_atoi(const char *str);
long long			ft_atol_r(const char *str, uint8_t *status);
long long			ft_atoll(const char *str);
char				*ft_itoa(int n);
char				*ft_itoal(long long int num);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strnlen(const char *str, size_t maxlen);
size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,\
									size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strtolower(char *str);
char				*ft_strtoupper(char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char(*f)(unsigned int, char));
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
size_t				ft_strchrcount(const char *s, int c);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstnew_r(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newlist);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_del(void *content, size_t size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					get_next_line(const int fd, char **line);
void				ft_replace_cnt(t_list *old, t_list **donor, void *new);
uint8_t				ft_wdetect(const char *str, size_t length);
size_t				ft_wstrlen(const char *str);
int					ft_wipegnl(t_list **fdl, t_list *first, \
												t_list*second, t_list *third);
int					ft_strcasecmp(const char *s1, const char *s2);

t_list				*ft_lstrot_rec(t_list *current, t_list *prev);
uint8_t				ft_lstrot_arr(t_list **alst);

void				ft_dlstadd(t_dlist **alst, t_dlist *new, uint8_t flag);
void				ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
t_dlist				*ft_dlstnew_r(void const *content, size_t content_size);
t_dlist				*ft_dlstnew(void const *content, size_t content_size);
void				ft_dlstwipe_ring(t_dlist **alst, \
												void (*del)(void *, size_t));
void				ft_dlstwipe(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstdelone(t_dlist **alst, void (*del)(void*, size_t));

void				ft_srt_bubble_intarr(int *array, size_t size, \
														t_datacmp_rout *cmp);
void				ft_srt_listarr_bubble(t_list **head, t_list **arr_ptr, \
											size_t length, t_datacmp_rout *cmp);
void				ft_srt_bubble_genarr(void **array, size_t size, \
														t_datacmp_rout *cmp);

int					ft_intp_left_grt_right(void *a, void *b);
int					ft_intp_left_lsr_right(void *a, void *b);
int					ft_lst_cntsz_left_grt_right(void *a, void *b);
int					ft_lst_cntsz_left_lsr_right(void *a, void *b);

void				ft_dlstadd(t_dlist **alst, t_dlist *new, uint8_t flag);
void				ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t));
t_dlist				*ft_dlstnew_r(void const *content, size_t content_size);
t_dlist				*ft_dlstnew(void const *content, size_t content_size);
void				ft_dlstwipe_ring(t_dlist **alst, void (*del)(void *, \
																	size_t));
void				ft_dlstwipe(t_dlist **alst, void (*del)(void *, size_t));
void				ft_dlstdelone(t_dlist **alst, void (*del)(void*, size_t));

#endif
