/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:15:56 by spark             #+#    #+#             */
/*   Updated: 2020/10/18 21:37:57 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_int(t_set *set, va_list l)
{
	int		num_len;
	int		total_len;
	int		rt_byte;

	rt_byte = 0;
	set->num = va_arg(l, int);
	num_len = ft_int_len(set->num);
	set->lenths.total_len = \
	(num_len > set->lenths.width) ? num_len : set->lenths.width;
	total_len = \
	(total_len > set->lenths.precision) ? total_len : set->lenths.precision;
	rt_byte += total_len;
	if (!(set->strs.str_flaged = malloc(sizeof(char) * (total_len + 1))))
		return (0);
	ft_flag_setter(set);
	ft_body_setter(set);
	return (rt_byte);
}
