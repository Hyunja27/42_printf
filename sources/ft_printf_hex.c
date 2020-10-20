/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:52:38 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/20 23:11:29 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_hex(t_set *set, va_list l)
{
	int		num_len;
	int		i;

	i = 0;
	set->num = va_arg(l, long long);
	set->va_str = ft_ltoa(set->num);
	set->strs.str_body = ft_convert_base(set->va_str, "0123456789", \
	"0123456789abcdef");
	num_len = ft_strlen(set->strs.str_body);
	set->lenths.total_len = \
	(num_len > set->lenths.width) ? num_len : set->lenths.width;
	if (!(set->strs.str_flaged = malloc(sizeof(char) * \
		(set->lenths.total_len + 1))))
		return ;
	ft_flag_setter(set);
	ft_body_setter_hex(set);
	if (set->type == 'X')
		while (set->strs.str_flaged[i])
		{
			set->strs.str_flaged[i] = ft_toupper(set->strs.str_flaged[i]);
			i++;
		}
	set->rt_byte += write(1, set->strs.str_flaged, \
	ft_strlen(set->strs.str_flaged));
}
