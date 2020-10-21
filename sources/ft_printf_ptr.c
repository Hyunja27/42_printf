/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 00:31:47 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/21 11:48:43 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_ptr(t_set *set, va_list l)
{
	int				i;
	int				num_len;
	i = 0;
	set->val = va_arg(l, void*);
	set->strs.str_body = ft_print_memory(set->val, 16);
	num_len = ft_strlen(set->strs.str_body);
	set->lenths.total_len = \
	(num_len > set->lenths.width) ? num_len : set->lenths.width;
	if (!(set->strs.str_flaged = malloc(sizeof(char) * \
		(set->lenths.total_len + 1))))
		return ;
	ft_flag_setter(set);
	ft_body_setter_str(set);
	set->rt_byte += write(1, set->strs.str_flaged, \
	ft_strlen(set->strs.str_flaged));
}
