/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body_setter_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:59:02 by spark             #+#    #+#             */
/*   Updated: 2020/11/09 15:38:11 by spark            ###   ########.fr       */
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
	if (set->flags.lefted == 1)
		ft_memmove(set->strs.str_flaged, set->strs.str_body, sm);
	else
	{
		padding = set->lenths.total_len - sm;
		ft_memmove(set->strs.str_flaged + padding, set->strs.str_body, sm);
	}
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
		ft_memmove_f(set->strs.str_flaged, set->strs.str_body, tmp_body + 1);
	else
		ft_body_setter_str_pres_2(set);
}

static void				ft_body_setter_str_2(t_set *set)
{
	int		padding;
	int		tmp_body;

	if (set->type == 'c')
		tmp_body = 1;
	else
		tmp_body = (int)ft_strlen(set->strs.str_body);
	padding = set->lenths.total_len;
	if ((padding > tmp_body) && (set->flags.lefted == 0))
	{
		padding = set->lenths.total_len - tmp_body;
		ft_memmove_f(set->strs.str_flaged + padding, set->strs.str_body, \
		tmp_body);
	}
	else if ((padding > tmp_body) && (set->flags.lefted == 1))
		ft_memmove_f(set->strs.str_flaged, set->strs.str_body, tmp_body);
	else
		ft_memmove_f(set->strs.str_flaged, set->strs.str_body, tmp_body);
	free(set->va_str);
}

void					ft_body_setter_str(t_set *set)
{
	int		tmp_body;

	if (set->type == 'c')
		tmp_body = 1;
	else
		tmp_body = (int)ft_strlen(set->strs.str_body);
	if ((set->flags.just_bd == 1) && (set->lenths.width < \
	set->lenths.precision))
	{
		if (((tmp_body > (int)ft_strlen(set->strs.str_flaged))\
		|| (set->flags.lefted == 1)) && \
		((set->lenths.width < set->lenths.precision)))
			ft_memmove_f(set->strs.str_flaged, set->strs.str_body, \
			tmp_body + 1);
		else
			ft_memmove_f(set->strs.str_flaged, set->strs.str_body, tmp_body);
		set->rt_byte += ft_putstr_fd(set->strs.str_body, 1);
	}
	else if ((set->precision_yn != 0))
		ft_body_setter_str_pres_1(set);
	else
		ft_body_setter_str_2(set);
	free(set->va_str);
}
