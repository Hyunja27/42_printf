/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_double_e.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:15:56 by spark             #+#    #+#             */
/*   Updated: 2020/11/22 16:33:02 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				plus_adder(t_set *set, char *target)
{
	char	*tmp;

	if ((set->f.d >= 0) && (set->f.s_bit.sign == 0))
	{
		if (!(tmp = ft_strjoin("+", target)))
			return ;
		free(target);
		set->strs.str_body = tmp;
	}
}

static void				ft_printf_double_e_4(t_set *set)
{
	char	*be_free;

	if ((ft_strlen(set->strs.str_body) >= 2) && (set->lenths.precision == 0) \
	&& (set->f.d < 0) && (set->precision_yn == 1))
	{
		set->strs.str_body[1] = (set->strs.str_body[1] != '.') ? 0 : \
		set->strs.str_body[1];
		set->e_expond = (set->flags.shap_flag == 0) ? set->e_expond + 1 \
		: set->e_expond;
	}
	ft_flag_setter_double(set);
	ft_expond_adder(set);
	be_free = set->strs.str_body;
	if ((set->flags.zeroflag == 0) || (set->flags.lefted == 1))
	{
		if (set->flags.plus_flag == 1)
			plus_adder(set, set->strs.str_body);
		ft_minus_adder(set, set->strs.str_body);
	}
	if ((set->flags.spaceflag == 1) && (set->f.s_bit.sign == 0) \
	&& set->flags.plus_flag == 0)
		ft_space_adder(set);
	ft_body_setter_double(set);
	set->rt_byte += ft_putstr_fd(set->strs.str_flaged, 1);
}

void					ft_printf_double_e_2(t_set *set)
{
	int		i;
	int		j;
	char	*tmp_bigint;

	if (set->lenths.precision > 6)
	{
		tmp_bigint = ft_bigint(set);
		i = ft_strlen(tmp_bigint) - 1;
		j = ft_strlen(set->strs.str_body) - 1;
		set->strs.str_body[j--] = tmp_bigint[i--];
		set->strs.str_body[j--] = tmp_bigint[i--];
		free(tmp_bigint);
	}
	i = ft_strlen(set->strs.str_body) - 1;
	if ((set->flags.shap_flag == 0) && (set->type == 'g' || set->type == 'G'))
	{
		while (set->strs.str_body[i] == '0')
		{
			set->strs.str_body[i--] = 0;
			set->e_expond += (set->lenths.precision == 0) ? 1 : 0;
			set->lenths.precision--;
		}
		set->strs.str_body[i] = (set->strs.str_body[i] == '.') ? 0 : \
		set->strs.str_body[i];
	}
}

void					ft_printf_double_e_3(t_set *set)
{
	set->lenths.total_len = ((set->lenths.precision) > \
	(set->lenths.width)) ? (set->lenths.precision) : (set->lenths.width);
	set->lenths.total_len = \
	(set->lenths.total_len > (int)ft_strlen(set->strs.str_body) + 4) ? \
		set->lenths.total_len : (int)ft_strlen(set->strs.str_body) + 4;
	free(set->strs.str_flaged);
	if (!(set->strs.str_flaged = malloc(sizeof(char) * \
	(set->lenths.total_len + 2))))
		return ;
	set->strs.str_flaged[set->lenths.total_len + 1] = 0;
	set->strs.str_flaged[set->lenths.total_len] = 0;
}

void					ft_printf_double_e(t_set *set, va_list l)
{
	if (set->type != 'g' && set->type != 'G')
		set->f.d = va_arg(l, double);
	else
		set->e_expond = 0;
	if (set->precision_yn == 0)
	{
		if (set->type != 'g' && set->type != 'G')
			set->strs.str_body = ft_dtoa_e(set, \
			(set->f.d), 6, set->lenths.width);
		else
			set->strs.str_body = ft_dtoa_e(set, (set->f.d), \
		set->lenths.precision, set->lenths.width);
	}
	else if ((set->precision_yn == 1) && (set->lenths.precision == 0))
		set->strs.str_body = ft_dtoa_e(set, (set->f.d), 0, set->lenths.width);
	else
		set->strs.str_body = ft_dtoa_e(set, (set->f.d), \
		set->lenths.precision, set->lenths.width);
	ft_printf_double_e_2(set);
	ft_printf_double_e_3(set);
	ft_printf_double_e_4(set);
	ft_free_va(2, set->strs.str_flaged, set->strs.str_body);
}
