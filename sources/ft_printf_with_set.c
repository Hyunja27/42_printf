/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_with_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:47:57 by spark             #+#    #+#             */
/*   Updated: 2020/10/18 16:43:29 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_with_set(t_set *set, va_list l)
{
	int rt_byte;

	rt_byte = 0;
	if (set->type == 'd' || set->type == 'i' || set->type == 'u')
		rt_byte += ft_printf_int(set, l);
	return (rt_byte);
}
