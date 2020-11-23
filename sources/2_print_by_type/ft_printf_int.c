/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:15:56 by spark             #+#    #+#             */
/*   Updated: 2020/11/23 16:11:52 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ex_va_arg_setter_d_i(t_set *set, va_list l)
{
	if (set->ex.l == 1)
		set->num = va_arg(l, long);
	else if (set->ex.ll == 1)
		set->num = va_arg(l, long long);
	else if (set->ex.h == 1)
		set->num = (short int)va_arg(l, int);
	else if (set->ex.hh == 1)
		set->num = (signed char)va_arg(l, int);
	else
		set->num = va_arg(l, int);
}

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

void			ft_printf_int(t_set *set, va_list l)
{
	int		num_len;

	if ((set->type == 'd') || (set->type == 'i'))
		ex_va_arg_setter_d_i(set, l);
	else if ((set->type == 'u') || (set->type == 'o') || \
	(set->type == 'x') || (set->type == 'X'))
		ex_va_arg_setter_u(set, l);
	if (set->flags.ull_on == 0)
		num_len = ft_int_len(set->num);
	else
		num_len = ft_int_len(set->num_ull);
	set->lenths.total_len = \
	(num_len >= set->lenths.width) ? num_len : set->lenths.width;
	set->lenths.total_len = \
	(set->lenths.total_len >= set->lenths.precision) ? \
	set->lenths.total_len : set->lenths.precision;
	if (!(set->strs.str_flaged = malloc(sizeof(char) * \
		(set->lenths.total_len + 2))))
		return ;
	set->strs.str_flaged[set->lenths.total_len + 1] = 0;
	ft_flag_setter(set);
	ft_body_setter_int(set);
	ft_left_setter(set);
	ft_free_va(1, set->strs.str_flaged);
}
