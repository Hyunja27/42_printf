/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:08:28 by hyunja            #+#    #+#             */
/*   Updated: 2020/11/20 01:23:36 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_2(t_set *set, va_list l)
{
	while (*set->strs.str_to_pharse)
	{
		if ((*set->strs.str_to_pharse != '%'))
			set->rt_byte += write(1, set->strs.str_to_pharse, 1);
		else if (*(set->strs.str_to_pharse + 1) && \
		((*set->strs.str_to_pharse == '%') && \
		*(set->strs.str_to_pharse + 1) == '%'))
		{
			set->rt_byte += write(1, set->strs.str_to_pharse, 1);
			set->strs.str_to_pharse++;
		}
		else if ((*set->strs.str_to_pharse == '%'))
		{
			ft_pharse_str(set);
			ft_printf_with_set(set, l);
		}
		set->strs.str_to_pharse++;
		ft_set_clear(set);
	}
}

int			ft_printf(const char *str, ...)
{
	va_list		l;
	t_set		set;

	ft_set_clear(&set);
	set.list = &l;
	set.strs.str_to_pharse = str;
	set.rt_byte = 0;
	va_start(l, str);
	ft_printf_2(&set, l);
	va_end(l);
	return (set.rt_byte);
}
