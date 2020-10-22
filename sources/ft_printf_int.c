/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:15:56 by spark             #+#    #+#             */
/*   Updated: 2020/10/22 20:53:27 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_int(t_set *set, va_list l)
{
	int		num_len;

	if ((set->type == 'd') || (set->type == 'i'))
		set->num = va_arg(l, int);
	else if (set->type == 'u')
		set->num = va_arg(l, unsigned int);
	num_len = ft_int_len(set->num);
	set->lenths.total_len = \
	(num_len > set->lenths.width) ? num_len : set->lenths.width;
	set->lenths.total_len = \
	(set->lenths.total_len > set->lenths.precision) ? \
	set->lenths.total_len : set->lenths.precision;
	if (!(set->strs.str_flaged = malloc(sizeof(char) * \
		(set->lenths.total_len + 1))))
		return ;
	ft_flag_setter(set);
	ft_body_setter_int(set);
	ft_left_setter(set);
}
