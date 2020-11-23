/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body_setter_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:59:02 by spark             #+#    #+#             */
/*   Updated: 2020/11/22 17:29:05 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		space_adder(t_set *set)
{
	if ((set->lenths.precision == 0 && (set->rt_byte > 0)) && \
	((set->type != 'e') && (set->type != 'E')))
		set->strs.str_flaged[ft_strlen(set->strs.str_flaged) - 1] = 0;
	else if ((set->strs.str_flaged[0] != ' ') && (set->rt_byte == 0))
		set->strs.str_flaged[0] = ' ';
}

static void		minus_adder(t_set *set, char *target)
{
	char	*tmp;

	if (set->f.s_bit.sign == 1)
	{
		if (((ft_db_len(set, set->f.d, set->lenths.precision, \
		set->lenths.width) < (int)ft_strlen(set->strs.str_flaged)) && \
		set->f.d != 0) || (set->f.d == 0 && set->lenths.precision == 0))
			set->strs.str_flaged[0] = '-';
		else
		{
			if (!(tmp = ft_strjoin("-", target)))
				return ;
			free(target);
			set->strs.str_flaged = ft_strdup(tmp);
			free(tmp);
		}
	}
}

static void		plus_adder(t_set *set, char *target)
{
	char	*tmp;

	if ((set->f.d >= 0) && (set->f.s_bit.sign == 0))
	{
		if (((ft_db_len(set, set->f.d, set->lenths.precision, \
		set->lenths.width) < (int)ft_strlen(set->strs.str_flaged)) && \
		set->f.d != 0) || (set->f.d == 0 && set->lenths.precision == 0))
			set->strs.str_flaged[0] = '+';
		else if (set->flags.plus_flag == 1)
		{
			if (!(tmp = ft_strjoin("+", target)))
				return ;
			free(target);
			set->strs.str_flaged = ft_strdup(tmp);
			free(tmp);
		}
	}
}

static void		ft_body_setter_double_2(t_set *set)
{
	int		padding;
	int		tmp_body;

	tmp_body = (int)ft_strlen(set->strs.str_body);
	padding = set->lenths.total_len;
	if ((set->flags.zeroflag == 1) && set->flags.lefted == 0)
	{
		if (set->flags.plus_flag == 1)
			plus_adder(set, set->strs.str_flaged);
		minus_adder(set, set->strs.str_flaged);
	}
	if ((set->flags.spaceflag == 1) && (set->f.s_bit.sign == 0)\
	&& set->flags.plus_flag == 0)
		space_adder(set);
	free(set->va_str);
}

void			ft_body_setter_double(t_set *set)
{
	int		padding;
	int		tmp_body;

	padding = set->lenths.total_len;
	tmp_body = (int)ft_strlen(set->strs.str_body);
	if ((int)ft_strlen(set->strs.str_flaged) <= tmp_body)
		ft_memmove_f(set->strs.str_flaged, set->strs.str_body, \
		ft_strlen(set->strs.str_body));
	else
	{
		if ((padding > tmp_body) && (set->flags.lefted == 0))
		{
			padding = set->lenths.total_len - tmp_body;
			ft_memmove_f(set->strs.str_flaged + padding, set->strs.str_body, \
			(int)ft_strlen(set->strs.str_body));
		}
		else if ((padding > tmp_body) && (set->flags.lefted == 1))
			ft_memmove_f(set->strs.str_flaged, set->strs.str_body, \
			(int)ft_strlen(set->strs.str_body));
		else
			ft_memmove_f(set->strs.str_flaged, set->strs.str_body, \
			(int)ft_strlen(set->strs.str_body));
	}
	ft_body_setter_double_2(set);
}
