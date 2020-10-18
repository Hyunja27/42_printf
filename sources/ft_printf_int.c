/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:15:56 by spark             #+#    #+#             */
/*   Updated: 2020/10/19 01:23:23 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_int(t_set *set, va_list l)
{
	int		num_len;
	int		rt_byte;

	rt_byte = 0;
	set->num = va_arg(l, int);
	num_len = ft_int_len(set->num);
	set->lenths.total_len = \
	(num_len > set->lenths.width) ? num_len : set->lenths.width;
	set->lenths.total_len = \
	(set->lenths.total_len > set->lenths.precision) ? \
	set->lenths.total_len : set->lenths.precision;
	rt_byte += set->lenths.total_len;
	if (!(set->strs.str_flaged = malloc(sizeof(char) * \
		(set->lenths.total_len + 1))))
		return (0);
	ft_flag_setter(set);
	ft_body_setter(set);
	ft_left_setter(set);
	return (rt_byte);
}
