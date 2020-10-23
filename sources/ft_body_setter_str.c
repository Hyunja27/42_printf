/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body_setter_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:59:02 by spark             #+#    #+#             */
/*   Updated: 2020/10/23 18:07:01 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_body_setter_str_pres(t_set *set)
{
	int		padding;
	int		sm_padding;

	//printf("\n\n>>total_len :%d\n",set->lenths.total_len);
	// printf("\n\n>>body :%s\n",set->strs.str_body);
	padding = set->lenths.total_len;
	sm_padding = (set->lenths.precision >= (int)ft_strlen(set->strs.str_body)) ?\
	(int)ft_strlen(set->strs.str_body) : set->lenths.precision; 
	if ((padding == (int)ft_strlen(set->strs.str_body)) && set->precision_yn == 0)
	{
		ft_strlcpy(set->strs.str_flaged + padding, \
		set->strs.str_body, ft_strlen(set->strs.str_body) + 1);
	}
	else if ((padding == (int)ft_strlen(set->strs.str_body)) && set->precision_yn == 1)
	{
		ft_strlcpy(set->strs.str_flaged,\
		set->strs.str_body, set->lenths.precision + 1);
	}
	else if ((padding > set->lenths.precision) && (set->flags.lefted == 0))
	{
		padding = set->lenths.total_len - sm_padding;
		ft_strlcpy(set->strs.str_flaged + padding, \
		set->strs.str_body, sm_padding + 1);
	}
	else if ((padding > set->lenths.precision) && (set->flags.lefted == 1))
		ft_memmove(set->strs.str_flaged, set->strs.str_body, set->lenths.precision);
	else
	{
		ft_strlcpy(set->strs.str_flaged, set->strs.str_body, \
		set->lenths.precision + 1);
	}
	free(set->va_str);
}

void	ft_body_setter_str(t_set *set)
{
	int		padding;
	if ((set->precision_yn != 0))
		ft_body_setter_str_pres(set);
	else
	{
		padding = set->lenths.total_len;
		if ((padding > (int)ft_strlen(set->strs.str_body)) && (set->flags.lefted == 0))
		{
			padding = set->lenths.total_len - (int)ft_strlen(set->strs.str_body);
			ft_strlcpy(set->strs.str_flaged + padding, \
			set->strs.str_body, ft_strlen(set->strs.str_body) + 1);
		}
		else if ((padding > (int)ft_strlen(set->strs.str_body)) && (set->flags.lefted == 1))
		{
			ft_memmove(set->strs.str_flaged, set->strs.str_body, ft_strlen(set->strs.str_body));
		}
		else
		{
			ft_strlcpy(set->strs.str_flaged, set->strs.str_body, \
			ft_strlen(set->strs.str_body) + 1);
		}
		free(set->va_str);
	}
}
