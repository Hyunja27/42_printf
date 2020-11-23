/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:52:38 by hyunja            #+#    #+#             */
/*   Updated: 2020/11/23 16:14:48 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ex_va_arg_setter_u(t_set *set, va_list l)
{
	set->flags.ull_on = 1;
	if (set->ex.l == 1)
		set->num_ull = va_arg(l, unsigned long);
	else if (set->ex.ll == 1)
		set->num_ull = va_arg(l, unsigned long long);
	else if (set->ex.h == 1)
		set->num_ull = (unsigned short int)va_arg(l, int);
	else if (set->ex.hh == 1)
		set->num_ull = (unsigned char)va_arg(l, int);
	else
		set->num_ull = va_arg(l, unsigned int);
}

static void		ft_printf_hex_print(t_set *set)
{
	if ((set->num == 0) && (set->precision_yn == 1) && \
	(set->lenths.precision == 0) && (set->lenths.width == 0))
		return ;
	else
		ft_left_setter_hex(set);
}

void			ft_printf_hex(t_set *set, va_list l)
{
	long long		num_len;

	ex_va_arg_setter_u(set, l);
	if (set->flags.ull_on == 0)
		set->va_str = ft_ultoa(set->num);
	else
		set->va_str = ft_ultoa(set->num_ull);
	set->strs.str_body = ft_convert_base_u(set->va_str, "0123456789", \
	"0123456789abcdef");
	num_len = (long long)ft_strlen(set->strs.str_body);
	set->lenths.total_len = \
	(num_len > set->lenths.width) ? num_len : set->lenths.width;
	set->lenths.total_len = \
	(set->lenths.total_len > set->lenths.precision) ? \
	set->lenths.total_len : set->lenths.precision;
	free(set->strs.str_flaged);
	if (!(set->strs.str_flaged = malloc(sizeof(char) * \
		(set->lenths.total_len + 2))))
		return ;
	set->strs.str_flaged[set->lenths.total_len + 1] = 0;
	set->strs.str_flaged[set->lenths.total_len] = 0;
	ft_flag_setter(set);
	ft_body_setter_hex(set);
	ft_printf_hex_print(set);
	ft_free_va(1, set->strs.str_flaged);
}
