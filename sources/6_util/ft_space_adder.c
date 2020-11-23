/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_adder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:22:41 by hyunja            #+#    #+#             */
/*   Updated: 2020/11/20 01:34:42 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_space_adder(t_set *set)
{
	if (((set->flags.lefted == 1) || (set->f.d == 0)) && \
	(set->lenths.precision != 0))
	{
		if (!((set->f.d == 0) && (set->lenths.precision == 0) && \
		(set->flags.lefted == 0)))
			set->rt_byte += write(1, " ", 1);
		set->strs.str_flaged[ft_strlen(set->strs.str_flaged) - 1] = 0;
	}
	else if (((ft_strlen(set->strs.str_body) >= \
	ft_strlen(set->strs.str_flaged)) && set->num >= 0) || \
	(set->flags.lefted == 1))
	{
		set->rt_byte += write(1, " ", 1);
	}
}
