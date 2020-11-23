/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 00:31:47 by hyunja            #+#    #+#             */
/*   Updated: 2020/11/20 21:12:36 by spark            ###   ########.fr       */
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
		(set->lenths.total_len + 2))))
		return ;
	set->strs.str_flaged[set->lenths.total_len + 1] = 0;
	set->strs.str_flaged[set->lenths.total_len] = 0;
	ft_flag_setter(set);
	ft_body_setter_ptr(set);
	set->rt_byte += write(1, set->strs.str_flaged, \
	ft_strlen(set->strs.str_flaged));
	ft_free_va(2, set->strs.str_flaged, set->strs.str_body);
}
