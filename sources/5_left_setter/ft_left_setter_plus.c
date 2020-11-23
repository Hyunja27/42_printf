/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_setter_plus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:35:52 by spark             #+#    #+#             */
/*   Updated: 2020/11/22 15:02:37 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_left_setter_plus_2_2(t_set *set)
{
	int		padding;
	char	*tmp_flaged;
	char	*tmp_body;

	tmp_flaged = set->strs.str_flaged;
	tmp_body = set->strs.str_body;
	padding = 0;
	if ((set->flags.lefted == 1) & (set->lenths.precision > 0))
	{
		ft_memmove(tmp_flaged, tmp_body, ft_strlen(tmp_body));
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
	else
	{
		padding = ft_strlen(tmp_flaged) - ft_strlen(tmp_body);
		ft_memmove(tmp_flaged + padding, tmp_body, ft_strlen(tmp_body));
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
}

static void		ft_left_setter_plus_2(t_set *set)
{
	int		padding;
	char	*tmp_flaged;
	char	*tmp_body;

	tmp_flaged = set->strs.str_flaged;
	tmp_body = set->strs.str_body;
	padding = 0;
	if (set->pre_is_zero == 1)
	{
		padding = ft_strlen(tmp_flaged) - 1;
		padding = (padding < 0) ? 0 : padding;
		if (set->flags.lefted == 0)
			ft_memmove(tmp_flaged + padding, tmp_body, 1);
		else
			ft_memmove(tmp_flaged, tmp_body, 1);
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
	else if ((set->flags.lefted == 1) && (set->lenths.precision == 0))
	{
		padding = ft_strlen(tmp_flaged) - 1;
		ft_memmove(tmp_flaged + padding, tmp_body, 1);
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
	else
		ft_left_setter_plus_2_2(set);
}

static void		ft_left_setter_plus_3(t_set *set)
{
	int		padding;
	char	*tmp_flaged;
	char	*tmp_body;

	tmp_flaged = set->strs.str_flaged;
	tmp_body = set->strs.str_body;
	padding = 0;
	if (set->flags.plus_flag == 1)
	{
		padding = ft_strlen(tmp_flaged) - ft_strlen(tmp_body);
		padding = (padding < 0) ? 0 : padding;
		if (padding == 0)
			ft_memmove(tmp_flaged, tmp_body, ft_strlen(tmp_body));
		else
			ft_memmove(tmp_flaged + padding, tmp_body, ft_strlen(tmp_body));
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
	else
	{
		padding = ft_strlen(tmp_flaged) - ft_strlen(tmp_body);
		ft_memmove(tmp_flaged + padding, tmp_body, ft_strlen(tmp_body));
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
}

void			ft_left_setter_plus(t_set *set)
{
	int		padding;
	char	*tmp_flaged;
	char	*tmp_body;

	tmp_flaged = set->strs.str_flaged;
	tmp_body = set->strs.str_body;
	padding = 0;
	if ((set->num == 0) && (set->precision_yn == 1))
		ft_left_setter_plus_2(set);
	else if (set->flags.lefted == 1)
	{
		ft_memmove(tmp_flaged, tmp_body, ft_strlen(tmp_body));
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
	else if ((set->flags.zeroflag == 1) && (set->num == 0))
	{
		ft_memmove(tmp_flaged, tmp_body, ft_strlen(tmp_body));
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
	else
		ft_left_setter_plus_3(set);
}
