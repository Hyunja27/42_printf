/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:35:52 by spark             #+#    #+#             */
/*   Updated: 2020/11/23 20:19:31 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_left_setter_4(t_set *set)
{
	char	*tmp_flaged;
	char	*tmp_body;

	tmp_flaged = set->strs.str_flaged;
	tmp_body = set->strs.str_body;
	if ((set->flags.lefted == 1) && (ft_strlen(tmp_flaged) \
		> ft_strlen(tmp_body)))
	{
		ft_memmove(tmp_flaged, tmp_body, ft_strlen(tmp_body));
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
	else if ((set->strs.str_flaged <= set->strs.str_body))
	{
		ft_memmove(tmp_flaged, tmp_body, ft_strlen(tmp_body) + 1);
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
	else
	{
		ft_memmove(tmp_flaged, tmp_body, ft_strlen(tmp_body));
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
}

static void		ft_left_setter_3(t_set *set)
{
	int		padding;
	char	*tmp_flaged;
	char	*tmp_body;

	tmp_flaged = set->strs.str_flaged;
	tmp_body = set->strs.str_body;
	padding = 0;
	if ((set->flags.lefted == 0) && (ft_strlen(tmp_flaged) \
	> ft_strlen(tmp_body)))
	{
		padding = ft_strlen(tmp_flaged) - ft_strlen(tmp_body);
		ft_memmove(tmp_flaged + padding, tmp_body, ft_strlen(tmp_body));
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
	else if ((set->flags.lefted == 1) && (ft_strlen(tmp_flaged) \
		> ft_strlen(tmp_body)))
	{
		ft_memmove(tmp_flaged, tmp_body, ft_strlen(tmp_body));
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
	else
		ft_left_setter_4(set);
}

static void		ft_left_setter_2(t_set *set)
{
	int					padding;
	char				*tmp_flaged;
	char				*tmp_body;
	int					tmp;

	tmp = (set->flags.ull_on == 1) ? (int)set->num_ull : set->num;
	tmp_body = set->strs.str_body;
	tmp_flaged = set->strs.str_flaged;
	padding = 0;
	if ((set->rt_byte == 0) && (tmp == 0) && (set->precision_yn == 1)\
	&& (set->lenths.precision == 0))
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	else if ((set->precision_yn == 1) && (set->lenths.width != 0) && \
	((tmp) == 0) && (ft_strlen(tmp_body) == 1) && (set->flags.lefted == 0))
	{
		padding = ft_strlen(tmp_flaged) - ft_strlen(tmp_body);
		ft_memmove(tmp_flaged + padding, tmp_body, ft_strlen(tmp_body));
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
	else
		ft_left_setter_3(set);
}

void			ft_left_setter(t_set *set)
{
	char	*tmp_flaged;

	if ((set->type == 'd') && (set->lenths.precision == 0) && (set->num == 0)\
	&& (set->precision_yn == 1) && (set->lenths.width == 0))
		set->rt_byte += write(1, set->strs.str_body, \
		ft_strlen(set->strs.str_body));
	else if (set->flags.just_bd == 1)
	{
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
	else
	{
		if ((set->flags.spaceflag == 1) && (set->lenths.total_len >= \
		set->lenths.width) && (set->flags.plus_flag == 0) && set->num >= 0)
		{
			set->rt_byte += write(1, " ", 1);
			set->strs.str_flaged[ft_strlen(set->strs.str_flaged) - 1] = 0;
		}
		if (set->flags.plus_flag == 1)
			ft_left_setter_plus(set);
		else
			ft_left_setter_2(set);
	}
	ft_free_va(1, set->strs.str_body);
}
