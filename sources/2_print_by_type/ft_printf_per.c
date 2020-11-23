/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_per.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:32:33 by spark             #+#    #+#             */
/*   Updated: 2020/11/22 19:23:33 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_per(t_set *set)
{
	char	*be_free;

	if (!(set->strs.str_body = malloc(sizeof(char) * 2)))
		return ;
	set->strs.str_body[0] = '%';
	set->strs.str_body[1] = 0;
	set->precision_yn = 0;
	set->lenths.precision = 0;
	set->lenths.total_len = \
	((int)ft_strlen(set->strs.str_body) > set->lenths.width) ? \
		(int)ft_strlen(set->strs.str_body) : set->lenths.width;
	if (!(set->strs.str_flaged = malloc(sizeof(char) * \
		(set->lenths.total_len + 1))))
		return ;
	ft_flag_setter(set);
	ft_body_setter_str(set);
	be_free = set->strs.str_flaged;
	while (*set->strs.str_flaged)
		set->rt_byte += write(1, set->strs.str_flaged++, 1);
	free(be_free);
	ft_free_va(1, set->strs.str_body);
}
