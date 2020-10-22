/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_with_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:47:57 by spark             #+#    #+#             */
/*   Updated: 2020/10/22 22:58:23 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_with_set(t_set *set, va_list l)
{
	int *int_ptr;

	if (set->type == 'd' || set->type == 'i' || set->type == 'u')
		ft_printf_int(set, l);
	else if (set->type == 's')
		ft_printf_str(set, l);
	else if (set->type == 'c')
		ft_printf_char(set, l);
	else if ((set->type == 'x') || (set->type == 'X'))
		ft_printf_hex(set, l);
	else if (set->type == 'p')
		ft_printf_ptr(set, l);
	else if (set->type == 'n')
	{
		int_ptr = va_arg(l, int*);
		*int_ptr = set->rt_byte;
	}
	else
		set->strs.str_to_pharse++;
}
