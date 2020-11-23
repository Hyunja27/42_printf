/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body_setter_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:59:02 by spark             #+#    #+#             */
/*   Updated: 2020/10/25 11:39:18 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_body_setter_str_pres_2(t_set *set)
{
	int		padding;
	int		sm;
	int		tmp_body;
	int		prsc;

	prsc = set->lenths.precision;
	tmp_body = (int)ft_strlen(set->strs.str_body);
	padding = set->lenths.total_len;
	sm = (prsc >= tmp_body) ? tmp_body : prsc;
	if ((sm == prsc) && ((set->lenths.width) > padding))
	{
		padding = set->lenths.total_len - sm;
		ft_memmove(set->strs.str_flaged + padding, set->strs.str_body, prsc);
	}
	else if ((padding >= prsc) && (set->flags.lefted == 0))
	{
		padding = set->lenths.total_len - sm;
		ft_memmove(set->strs.str_flaged + padding, set->strs.str_body, sm);
	}
	else if ((padding >= prsc) && (set->flags.lefted == 1))
		ft_memmove(set->strs.str_flaged, set->strs.str_body, tmp_body);
	else
		ft_memmove(set->strs.str_flaged, set->strs.str_body, tmp_body);
}

static void				ft_body_setter_str_pres_1(t_set *set)
{
	int		padding;
	int		sm;
	int		tmp_body;
	int		prsc;

	prsc = set->lenths.precision;
	tmp_body = (int)ft_strlen(set->strs.str_body);
	padding = set->lenths.total_len;
	sm = (prsc >= tmp_body) ? tmp_body : prsc;
	if ((sm == tmp_body) && ((set->lenths.width) < sm))
	{
		free(set->strs.str_flaged);
		set->strs.str_flaged = ft_strdup(set->strs.str_body);
	}
	else
		ft_body_setter_str_pres_2(set);
}

void					ft_body_setter_ptr(t_set *set)
{
	int		padding;
	int		tmp_body;

	tmp_body = (int)ft_strlen(set->strs.str_body);
	if (set->flags.just_bd == 1)
		ft_memmove(set->strs.str_flaged, set->strs.str_body, tmp_body);
	else if ((set->precision_yn != 0))
		ft_body_setter_str_pres_1(set);
	else
	{
		padding = set->lenths.total_len;
		if ((padding > tmp_body) && (set->flags.lefted == 0))
		{
			padding = set->lenths.total_len - tmp_body;
			ft_memmove(set->strs.str_flaged + padding, set->strs.str_body, \
			ft_strlen(set->strs.str_body) + 1);
		}
		else if ((padding > tmp_body) && (set->flags.lefted == 1))
			ft_memmove(set->strs.str_flaged, set->strs.str_body, \
			ft_strlen(set->strs.str_body));
		else
			ft_memmove(set->strs.str_flaged, set->strs.str_body, \
			ft_strlen(set->strs.str_body) + 1);
	}
	free(set->va_str);
}
