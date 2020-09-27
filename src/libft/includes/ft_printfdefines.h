/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfdefines.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschimme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:12:13 by mschimme          #+#    #+#             */
/*   Updated: 2020/09/13 22:19:45 by mschimme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFDEFINES_H
# define FT_PRINTFDEFINES_H
# include "ft_printf.h"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_varitype	t_varitype;
typedef struct s_format		t_format;
typedef struct s_fword		t_fword;

/*
**	Defines for function pointers, used in printf.
*/

typedef uint8_t			t_parse_anchor_rout(t_format *formstat);
typedef void			t_skip_va_arg_rout(va_list *bogey);
typedef	uint8_t			t_get_va_arg_rout(t_format *formstat, \
															t_fword *format);
typedef void			t_add_width_rout(t_format *formstat, t_fword *format, \
									size_t *dims, char *formatted_variative);
typedef char			*t_extract_arg_rout(t_fword *container);
typedef char			*t_extract_int_rout(t_fword *container, char *buff);
typedef char			*t_extract_oct_rout(t_fword *container, char **buff);
typedef char			*t_extract_hex_rout(t_fword *container, char **buff);
typedef char			*t_extract_float_rout(t_fword *container, char parent);
typedef void			*t_extract_vptr_rout(t_fword *container);
typedef void			t_printer_rout(const char *data, size_t length, \
															int flag, int fd);

/*
**	marker		-	Pointer to current position in format string for print-out;
**	access_key	-	Key for method to adress variative (in order == 1,
**				explicidly (with n$) == 2. Can't mix them together);
**	sight		-	Points to frowm where next format word or colour phase shall
**				be searched on.
**	parse_sight	-	Pointer to function, processing found sign of format word or
**				colour phrase (% or $).
**	ref_ap		Stores untouched version of va_list. Used to be cloned for job
*/

struct					s_format
{
	const char			*marker;
	const char			*end;
	const char			*sight;
	uint8_t				access_key;
	uint8_t				errflag;
	int					result;
	int					fd;
	va_list				ref_ap;
	va_list				cur_ap;
	t_parse_anchor_rout	*parse_sight;
	t_varitype			*first;
};

/*
**	space_plus	-	Indicates presence of "Space" or "Plus" flags.
**	zero_minux	-	Indicates presence of "Zer0" or "Minus" flags.
**	filler		-	Determines wich filler to use " " or "0";
**	variative	-	Pointer to struct, redy to give required variative
**				(points either to cur_ap of t_format, or to own var_sub);
**	var_sub		-	container for variative, determined by n$ flag.
**	ftp_typ		-	pointer to function, processing variative invocation
**	and its further interpretation.
**	ACHTUNG!!! BRAIN DAMAGE!
**	IN order to take va_list, that is stored in folded struct (i.e. t_format)
**	it's better to use this kind of construction: &(format.cur_ap). In order to
**	address to the argument of the folded struct, this ought to be done...:
**	(*ptr)->overflow_arg_area. YES, we dereference the pointer but keep on
**	using damn '->'. Fucking voodoo.
**	Thus we get the following porn:
**	##	formword->variative = formstat->cur_ap	##
**	##	(*ptr->variative)->fp_offset	##
**	where formword - f_word *, vairative - va_list *, formstat - t_format *,
**	cur_ap - va_list;
*/

struct					s_fword
{
	uint8_t				space_plus;
	uint8_t				hash;
	uint8_t				length_t;
	uint8_t				flags;
	t_get_va_arg_rout	*ftp_type;
	t_add_width_rout	*ftp_width;
	char				filler;
	int					width;
	int					precision;
	int					vari_num;
	va_list				*variative;
	va_list				var_sub;
	t_varitype			*vari_cont;
};

struct					s_varitype
{
	int					vari_num;
	int					vari_interval;
	t_skip_va_arg_rout	*iterator;
	t_varitype			*next;
};

typedef struct			s_float_calc
{
	char				*float_string;
	char				*sign;
	char				*end;
	int					length;
	long long			whole;
	long double			fraction;
	int					iter;
	int					pow;
	char				*zero_line;
	long long			ll_fraction;
	char				*pointer;
	char				*num_whole;
	char				*num_fraction;
	long double			num;
	size_t				*mant;
	unsigned short int	exp : 15;
	unsigned short int	sign_bit;
	char				flag;
	int					nan;
	int					inf_m;
	int					inf_p;
	int					whole_add_one;
}						t_float_calc;
#endif
