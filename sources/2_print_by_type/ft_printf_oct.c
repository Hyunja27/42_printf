/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_oct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:52:38 by hyunja            #+#    #+#             */
/*   Updated: 2020/11/22 18:03:37 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_printf_oct_print(t_set *set)
{
	if ((set->num == 0) && (set->precision_yn == 1) && \
	(set->lenths.precision == 0) && (set->lenths.width == 0))
		return ;
	else
		ft_left_setter_hex(set);
}

void			ft_printf_oct(t_set *set, va_list l)
{
	long long		num_len;

	set->num_ull = va_arg(l, unsigned long long);
	set->va_str = ft_ltoa(set->num_ull);
	set->strs.str_body = ft_convert_base(set->va_str, "0123456789", \
	"01234567");
	num_len = (long long)ft_strlen(set->strs.str_body);
	set->lenths.total_len = \
	(num_len > set->lenths.width) ? num_len : set->lenths.width;
	set->lenths.total_len = \
	(set->lenths.total_len > set->lenths.precision) ? \
	set->lenths.total_len : set->lenths.precision;
	if (!(set->strs.str_flaged = malloc(sizeof(char) * \
		(set->lenths.total_len + 1))))
		return ;
	ft_flag_setter(set);
	ft_body_setter_hex(set);
	ft_printf_oct_print(set);
	ft_free_va(1, set->strs.str_flaged);
}
