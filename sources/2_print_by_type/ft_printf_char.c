/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:32:33 by spark             #+#    #+#             */
/*   Updated: 2020/11/09 18:05:45 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_char(t_set *set, va_list l)
{
	set->chr = (unsigned char)va_arg(l, int);
	if (!(set->strs.str_body = malloc(sizeof(char) * 2)))
		return ;
	set->strs.str_body[0] = set->chr;
	set->strs.str_body[1] = 0;
	set->lenths.total_len = \
	(1 > set->lenths.width) ? 1 : set->lenths.width;
	if (!(set->strs.str_flaged = malloc(sizeof(char) * \
		(set->lenths.total_len + 2))))
		return ;
	ft_flag_setter(set);
	ft_body_setter_str(set);
	set->rt_byte += write(1, set->strs.str_flaged, set->lenths.total_len);
	ft_free_va(2, set->strs.str_flaged, set->strs.str_body);
}
