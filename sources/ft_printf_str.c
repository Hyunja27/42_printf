/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:33:45 by spark             #+#    #+#             */
/*   Updated: 2020/10/22 21:40:32 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_str(t_set *set, va_list l)
{
	set->strs.str_body = va_arg(l, char*);
	set->lenths.total_len = \
	((int)ft_strlen(set->strs.str_body) > set->lenths.width) ? \
		(int)ft_strlen(set->strs.str_body) : set->lenths.width;
	if (!(set->strs.str_flaged = malloc(sizeof(char) * \
		(set->lenths.total_len + 1))))
		return ;
	ft_flag_setter(set);

	printf("\n\n<body : %s>\n\n",set->strs.str_body);
	printf("\n\n<flaged :%s>\n\n",set->strs.str_flaged);
	
	ft_body_setter_str(set);
	
	//int i = 0;
	//while(set->strs.str_flaged[i])
		//printf("[%c]",set->strs.str_flaged[i++]);
	set->rt_byte += write(1, set->strs.str_flaged, ft_strlen(set->strs.str_flaged));
}
