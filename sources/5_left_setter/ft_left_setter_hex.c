/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_setter_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:35:52 by spark             #+#    #+#             */
/*   Updated: 2020/11/25 00:02:37 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_shap_adder_f(t_set *set)
{
	if (((set->flags.shap_flag == 1) && (set->type == 'o')) && \
	(set->lenths.precision + 1 <= (int)ft_strlen(set->strs.str_body)))
		set->strs.str_flaged[0] = '0';
	else if ((set->flags.shap_flag == 1) && ((set->type == 'x') \
	|| (set->type == 'X')))
	{
		set->strs.str_flaged[0] = '0';
		set->strs.str_flaged[1] = 'x';
	}
}

static void	ft_left_setter_hex_2(t_set *set)
{
	set->strs.str_body = set->strs.str_flaged;
	if ((set->num_ull != 0) && (set->flags.zeroflag == 1) \
	&& (set->flags.add == 0))
		ft_shap_adder_f(set);
	if (set->type == 'X')
	{
		while (*set->strs.str_body)
		{
			*set->strs.str_body = ft_toupper(*set->strs.str_body);
			set->strs.str_body++;
		}
	}
	set->rt_byte += ft_putstr_fd(set->strs.str_flaged, 1);
}

void		ft_left_setter_hex(t_set *set)
{
	int		padding;

	if ((set->precision_yn == 1) && (set->lenths.precision == 0)\
	&& (set->num_ull == 0))
		;
	else if ((set->flags.lefted == 0) && (ft_strlen(set->strs.str_flaged) \
	> ft_strlen(set->strs.str_body)))
	{
		padding = ft_strlen(set->strs.str_flaged) - \
		ft_strlen(set->strs.str_body);
		ft_memmove(set->strs.str_flaged + padding, set->strs.str_body,\
		ft_strlen(set->strs.str_body));
	}
	else if (ft_strlen(set->strs.str_body) >= ft_strlen(set->strs.str_flaged))
		ft_memmove(set->strs.str_flaged, set->strs.str_body, \
		ft_strlen(set->strs.str_body) + 1);
	else if ((set->num_ull != 0) && (set->flags.zeroflag == 1) \
	&& ((set->flags.lefted == 1)) && (set->flags.shap_flag == 1))
		ft_memmove(set->strs.str_flaged + 2, set->strs.str_body, \
		ft_strlen(set->strs.str_body));
	else
		ft_memmove(set->strs.str_flaged, set->strs.str_body, \
		ft_strlen(set->strs.str_body));
	free(set->strs.str_body);
	ft_left_setter_hex_2(set);
}
