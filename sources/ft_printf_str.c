/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:33:45 by spark             #+#    #+#             */
/*   Updated: 2020/10/23 18:31:04 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_str(t_set *set, va_list l)
{
	set->strs.str_body = va_arg(l, char*);
	if (set->strs.str_body == NULL)
		set->strs.str_body = ft_strdup("(null)");
	if (ft_strncmp(set->strs.str_body, "(null)", 6))
		set->lenths.total_len = ((int)ft_strlen(set->strs.str_body) > \
	set->lenths.width) ? (int)ft_strlen(set->strs.str_body) : set->lenths.width;
	else
		set->lenths.total_len = ((set->lenths.precision) > (set->lenths.width)) \
		? (set->lenths.precision) : set->lenths.width;
	if (!(set->strs.str_flaged = malloc(sizeof(char) * \
		(set->lenths.total_len + 1))))
		return ;
	ft_flag_setter(set);
	ft_body_setter_str(set);
	
	set->rt_byte += write(1, set->strs.str_flaged, ft_strlen(set->strs.str_flaged));
}
