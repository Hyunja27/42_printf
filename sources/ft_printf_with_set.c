/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_with_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:47:57 by spark             #+#    #+#             */
/*   Updated: 2020/10/20 20:51:58 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_with_set(t_set *set, va_list l)
{
	if (set->type == 'd' || set->type == 'i' || set->type == 'u')
		ft_printf_int(set, l);
	else if (set->type == 's')
		ft_printf_str(set, l);
	else if (set->type == 'c')
		ft_printf_char(set, l);
	else if ((set->type == 'x') || (set->type == 'X'))
		ft_printf_hex(set, l);
}
