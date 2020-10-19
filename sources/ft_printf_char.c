/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:32:33 by spark             #+#    #+#             */
/*   Updated: 2020/10/19 21:56:40 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_char(t_set *set, va_list l)
{
	set->chr = va_arg(l, int);
	if (!(set->strs.str_body = malloc(sizeof(char) * 2)))
		return ;
	set->strs.str_body[0] = set->chr;
	set->strs.str_body[1] = 0;
	set->lenths.total_len = \
	((int)ft_strlen(set->strs.str_body) > set->lenths.width) ? \
		(int)ft_strlen(set->strs.str_body) : set->lenths.width;
	if (!(set->strs.str_flaged = malloc(sizeof(char) * \
		(set->lenths.total_len + 1))))
		return ;
	ft_flag_setter(set);
	ft_body_setter_str(set);
	
	//int i = 0;
	//while(set->strs.str_flaged[i])
		//printf("[%c]",set->strs.str_flaged[i++]);
	set->rt_byte += write(1, set->strs.str_flaged, ft_strlen(set->strs.str_flaged));
}
