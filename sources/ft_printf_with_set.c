/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_with_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:47:57 by spark             #+#    #+#             */
/*   Updated: 2020/10/17 17:47:30 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_with_set(s_set *set, va_list l)
{
	s_set *a;
	int total_len;

	if (set->type == 'd' || set->type == 'i' || set->type == 'u')
		ft_printf_int(set,l);
		
	total_len = 0;
	a = set;

	va_end(l);
}