/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 00:31:47 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/21 09:17:46 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_ptr(t_set *set, va_list l)
{
	int				i;

	i = 0;
	set->val = va_arg(l, void*);
	set->strs.str_body = ft_print_memory(set->val, 16);
	
	// set->strs.str_body = ft_convert_base(set->va_str, "0123456789", \
	// "0123456789abcdef");
	// num_len = ft_strlen(set->strs.str_body);
	// set->lenths.total_len = \
	// (num_len > set->lenths.width) ? num_len : set->lenths.width;
	// if (!(set->strs.str_flaged = malloc(sizeof(char) * \
	// 	(set->lenths.total_len + 1))))
	// 	return ;
	// ft_flag_setter(set);
	// ft_body_setter_hex(set);
	// if (set->type == 'X')
	// 	while (set->strs.str_flaged[i])
	// 	{
	// 		set->strs.str_flaged[i] = ft_toupper(set->strs.str_flaged[i]);
	// 		i++;
	// 	}
	// set->rt_byte += write(1, set->strs.str_flaged, \
	// ft_strlen(set->strs.str_flaged));
}
