/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:02:40 by hyunja            #+#    #+#             */
/*   Updated: 2020/11/20 02:36:01 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
void	ft_width_detecter(t_set *set);
void	ft_precision_detecter(t_set *set);
void	ft_pharse_str(t_set *set);
void	ft_wid_pre_seperater(t_set *set);
void	ft_printf_with_set(t_set *set, va_list l);
void	ft_printf_int(t_set *set, va_list l);
void	ft_flag_setter(t_set *set);
void	ft_body_setter_int (t_set *set);
void	ft_body_setter_str(t_set *set);
void	ft_body_setter_hex(t_set *set);
void	ft_body_setter_ptr(t_set *set);
void	ft_body_setter_double(t_set *set);
void	ft_left_setter(t_set *set);
void	ft_left_setter_hex(t_set *set);
void	ft_left_setter_plus(t_set *set);
void	ft_flag_setter_double(t_set *set);
void	ft_printf_double_g(t_set *set, va_list l);
void	ft_printf_str(t_set *set, va_list l);
void	ft_printf_char(t_set *set, va_list l);
void	ft_printf_hex(t_set *set, va_list l);
void	ft_printf_oct(t_set *set, va_list l);
void	ft_printf_ptr(t_set *set, va_list l);
void	ft_printf_per(t_set *set);
void	ft_printf_uni(t_set *set, va_list l);
void	ft_printf_double(t_set *set, va_list l);
char	*ft_dtoa(t_set *set, double n, int pre, int wid);
char	*ft_dtoa_e(t_set *set, double n, int pre, int wid);
char	*ft_dtoa_e_big(t_set *set, double n, int pre, int wid);
void	ft_printf_double_e(t_set *set, va_list l);
char	*ft_zero_maker(t_set *set, int pre, int wid);
char	ft_array_round(t_set *set, char *str, int pre);
char	*ft_manti_to_a(t_set *set, double manti, char *base, int pre);
char	*ft_manti_to_a_e(t_set *set, double manti, char *base, int pre);
char	*ft_e_manti_array(t_set *set, int pre);
void	ft_expond_adder(t_set	*set);
char	*ft_bigint(t_set *set);
int		ft_ilencal(long long n);
void	ft_space_adder(t_set *set);
void	ft_minus_adder(t_set *set, char *target);

void	ft_set_clear(t_set *set);

#endif
