/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:15:56 by spark             #+#    #+#             */
/*   Updated: 2020/10/18 17:55:36 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_int(t_set *set, va_list l)
{
	int		num_len;
	int		total_len;
	int		rt_byte;
	char	*rt;

	rt_byte = 0;
	set->num = va_arg(l, int);
	num_len = ft_int_len(set->num);
	total_len = (num_len > set->width) ? num_len : set->width;
	total_len = (total_len > set->precision) ? total_len : set->precision;
	rt_byte += total_len;
	if (!(rt = malloc(sizeof(char) * (total_len + 1))))
		return (0);
	ft_flag_setter(rt, set, total_len);
	rt = ft_body_setter(rt, set, total_len);

	return (rt_byte);
}
