/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wid_pre_seperater.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 09:33:39 by hyunja            #+#    #+#             */
/*   Updated: 2020/11/19 02:19:57 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_ex_detecter(t_set *set)
{
	if (*set->strs.str_to_pharse == 'h')
	{
		if (set->ex.h == 0)
			set->ex.h = 1;
		else
		{
			set->ex.hh = 1;
			set->ex.h = 0;
		}
	}
	else if (*set->strs.str_to_pharse == 'l')
	{
		if (set->ex.l == 0)
			set->ex.l = 1;
		else
		{
			set->ex.ll = 1;
			set->ex.l = 0;
		}
	}
	set->strs.str_to_pharse++;
}

void			ft_wid_pre_seperater_2(t_set *set)
{
	if ((*set->strs.str_to_pharse == '+' || \
				*set->strs.str_to_pharse == ' ' || \
				*set->strs.str_to_pharse == '-') \
		&& (*(set->strs.str_to_pharse + 1) >= '1' && \
			*(set->strs.str_to_pharse + 1) <= '9'))
	{
		set->strs.str_to_pharse++;
		ft_width_detecter(set);
	}
	else if ((*set->strs.str_to_pharse == '+' || \
			*set->strs.str_to_pharse == ' ' || \
			*set->strs.str_to_pharse == '-' || \
			*set->strs.str_to_pharse == '.' || \
			*set->strs.str_to_pharse == '#'))
		set->strs.str_to_pharse++;
	else if ((*set->strs.str_to_pharse == 'h') \
	|| (*set->strs.str_to_pharse == 'l'))
		ft_ex_detecter(set);
	else if ((set->lenths.width == 0) && \
	((*set->strs.str_to_pharse != 'h') && (*set->strs.str_to_pharse != 'l')))
		ft_width_detecter(set);
	else
		set->strs.str_to_pharse++;
}

void			ft_wid_pre_seperater(t_set *set)
{
	char *type_set;

	type_set = ft_strdup("diuoxXfFeEgGaAcspn%");
	while (!ft_strchr(type_set, *set->strs.str_to_pharse))
	{
		if (*set->strs.str_to_pharse == '.')
		{
			set->strs.str_to_pharse++;
			ft_precision_detecter(set);
		}
		else
			ft_wid_pre_seperater_2(set);
	}
	if (((set->precision_yn == 1) && \
	(set->flags.lefted == 1)) || (*set->strs.str_to_pharse == 'e'))
		set->flags.zeroflag = 0;
	free(type_set);
	set->type = *set->strs.str_to_pharse;
}
