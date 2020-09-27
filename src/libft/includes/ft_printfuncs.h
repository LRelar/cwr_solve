/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfuncs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycorrupt <ycorrupt@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:35:43 by kokeefe           #+#    #+#             */
/*   Updated: 2020/07/02 22:53:31 by ycorrupt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFUNCS_H
# define FT_PRINTFUNCS_H
# include "ft_printf.h"

int					ft_printf(const char *format, ...);
int					ft_printf_fd(int fd, const char *format, ...);
void				filling_mainbuf(const char *data, size_t length, \
									int flag, int fd);
void				ft_init_formstat(t_format *ptr, const char *src, int fd);
uint8_t				ft_seach_anchors(t_format *formstat);
uint8_t				ft_check_colour(t_format *formstat);
uint8_t				ft_check_form_word(t_format *formstat);
uint8_t				ft_antoi(const char *start, const char *end, \
																long long *res);
char				*ft_intoa(long long int num, char *buff, size_t shift);
char				*ft_uintoa(unsigned long long int num, char *buff, \
													size_t shift);
char				*ft_uintoa_base(unsigned long long int num, char **buff, \
													uint8_t base, size_t shift);
uint8_t				ft_parse_format(t_format *formstat);
void				ft_skip_va_arg_float(va_list *bogey);
void				ft_skip_va_arg_int(va_list *bogey);
uint8_t				ft_wipe_structs(t_format *formstat, t_fword *format, \
														const char *callername);
uint8_t				ft_check_sub_ovf(int *result, int a, int b);
uint8_t				ft_check_add_ovf(int *result, int a, int b);
void				ft_prepare_va_list(t_format *formstat, int number, \
																va_list *var);
char				*ft_intoa_float(long long int num, char *buff, \
																size_t shift);
void				shift_string_left(char *string);
int					get_length_double(long double number, t_float_calc *f);
void				add_filler_signe_double(t_fword *container, \
					t_float_calc *f, long double *number);
char				*return_error_float(t_float_calc *f, t_fword *container);
int					check_error_float(t_float_calc *f);
unsigned long long	ft_pow_ull(unsigned long long a, unsigned int power, \
					t_float_calc *f);
void				init_float_calc(t_float_calc *f, long double number);
char				*ft_form_double(t_fword *container, long double number,
															t_float_calc *f);
char				*get_zero_line(int zero_length);
void				init_fraction_part(t_fword *container, t_float_calc *f);
void				ft_printmem(const char *addr, size_t size, int fl, int fd);
void				check_filler_zero_spase(t_fword *container,
					t_float_calc *f);
int					length_prec_whole_check(t_fword *container,
					t_float_calc *f);
void				check_space_flag(t_fword *container, t_float_calc *f);
void				add_plus_hash_num_prec(t_float_calc *f);
void				check_width_length_sign(t_fword *container,
					t_float_calc *f);
char				*init_temp_string(int *length, t_float_calc *f,
					t_fword *container, int *i2);
void				check_filler_zero_plus(t_fword *container,
					t_float_calc *f);
void				check_minus_hash_precision_zero(t_fword *container,
					t_float_calc *f);
void				shift_right_add_space(t_float_calc *f, int length);

/*
**				Funcions to SCAN Format string for format words, and scan'em.
*/

uint8_t				ft_scan_string(t_format *scanstat);
uint8_t				ft_scan_form_word(t_format *formstat);
void				ft_check_vari_cont_chain(t_format *formstat);

/*
**				Functions to parse Format word in format string.
*/

uint8_t				ft_flag_hash(const char *ptr, t_fword *format);
uint8_t				ft_flag_minus(const char *ptr, t_fword *format);
uint8_t				ft_flag_plus(const char *ptr, t_fword *format);
uint8_t				ft_flag_precision(t_format *formstat, t_fword *format);
uint8_t				ft_flag_space(const char *ptr, t_fword *format);
uint8_t				ft_flag_subst(t_format *formstat, t_fword *format);
uint8_t				ft_flag_type(t_format *formstat, t_fword *formword);
uint8_t				ft_flag_zero(const char *ptr, t_fword *format);
uint8_t				ft_flag_width(t_format *formstat, t_fword *format);
uint8_t				ft_proc_wildcard(t_format *formstat, \
									t_fword *format, uint8_t iswidth);
uint8_t				ft_flag_length(t_format *formstat, t_fword *format);
uint8_t				ft_flag_hash_dummy(const char *ptr);
uint8_t				ft_flag_length_dummy(t_format *formstat);
uint8_t				ft_flag_minus_dummy(const char *ptr);
uint8_t				ft_flag_plus_dummy(const char *ptr);
uint8_t				ft_flag_precision_dummy(t_format *formstat);
uint8_t				ft_flag_space_dummy(const char *ptr);
uint8_t				ft_flag_subst_dummy(t_format *formstat, t_fword *format);
uint8_t				ft_flag_type_dummy(t_format *formstat, t_fword *format);
uint8_t				ft_flag_width_dummy(t_format *formstat);
uint8_t				ft_proc_wildcard_dummy(t_format *formstat, uint8_t iswidth);
uint8_t				ft_flag_zero_dummy(const char *ptr);

/*
**				Error (warning) functions.
*/

uint8_t				ft_err_varoverflow(char *variable, const char *call_func);
void				ft_err_mixed_input(void);
uint8_t				ft_err_malloc(char *variable, const char *call_func);
void				ft_err_broken_chain(void);

/*
**				Functions to execute variative printout.
*/

uint8_t				ft_place_dummy(t_format *formstat, \
													t_fword *format);
uint8_t				ft_place_default(t_format *formstat, \
													t_fword *format);
void				ft_width_right(t_format *formstat, t_fword *format, \
									size_t *dims, char *formatted_variative);
void				ft_width_left(t_format *formstat, t_fword *format, \
									size_t *dims, char *formatted_variative);
uint8_t				ft_place_float(t_format *formstat, \
													t_fword *format);
uint8_t				ft_place_float_cap(t_format *formstat, \
													t_fword *format);
uint8_t				ft_place_string(t_format *formstat, \
													t_fword *format);
uint8_t				ft_place_integer(t_format *formstat, \
													t_fword *format);
uint8_t				ft_place_unsigned(t_format *formstat, \
													t_fword *format);
uint8_t				ft_place_octal(t_format *formstat, \
													t_fword *format);
uint8_t				ft_place_hexal(t_format *formstat, \
													t_fword *format);
uint8_t				ft_place_hexal_cap(t_format *formstat, \
													t_fword *format);
uint8_t				ft_place_ptr(t_format *formstat, \
													t_fword *format);
uint8_t				ft_place_char(t_format *formstat, \
													t_fword *format);
uint8_t				ft_place_mem(t_format *formstat, t_fword *format);

/*
**				Functions, extracting value of required format, aka drill-TIPS.
*/

char				*ft_get_float_default(t_fword *container, char parent);
char				*ft_get_float_l_lc(t_fword *container, char parent);
char				*ft_get_float_l_cap(t_fword *container, char parent);
char				*ft_get_string_default(t_fword *container);
char				*ft_get_int_default(t_fword *container, char *buff);
char				*ft_get_int_long(t_fword *container, char *buff);
char				*ft_get_int_long_long(t_fword *container, char *buff);
char				*ft_get_int_short(t_fword *container, char *buff);
char				*ft_get_int_short_short(t_fword *container, char *buff);
char				*ft_get_int_long_cap(t_fword *container, char *buff);
char				*ft_get_uns_default(t_fword *container, char *buff);
char				*ft_get_uns_long_cap(t_fword *container, char *buff);
char				*ft_get_uns_long_long(t_fword *container, char *buff);
char				*ft_get_uns_long(t_fword *container, char *buff);
char				*ft_get_uns_short_short(t_fword *container, char *buff);
char				*ft_get_uns_short(t_fword *container, char *buff);
char				*ft_get_oct_default(t_fword *container, char **buff);
char				*ft_get_oct_long_cap(t_fword *container, char **buff);
char				*ft_get_oct_long_long(t_fword *container, char **buff);
char				*ft_get_oct_long(t_fword *container, char **buff);
char				*ft_get_oct_short_short(t_fword *container, char **buff);
char				*ft_get_oct_short(t_fword *container, char **buff);
char				*ft_get_hex_default(t_fword *container, char **buff);
char				*ft_get_hex_long_cap(t_fword *container, char **buff);
char				*ft_get_hex_long_long(t_fword *container, char **buff);
char				*ft_get_hex_long(t_fword *container, char **buff);
char				*ft_get_hex_short_short(t_fword *container, char **buff);
char				*ft_get_hex_short(t_fword *container, char **buff);
char				*ft_get_ptr(t_fword *container, char **buff);
void				*ft_get_mem(t_fword *container);

#endif
