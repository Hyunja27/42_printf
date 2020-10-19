/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_with_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:47:57 by spark             #+#    #+#             */
/*   Updated: 2020/10/19 19:14:56 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_with_set(t_set *set, va_list l)
{
	if (set->type == 'd' || set->type == 'i' || set->type == 'u')
		ft_printf_int(set, l);
	if (set->type == 's')
		ft_printf_str(set, l);
}
