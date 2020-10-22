/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wid_pre_seperater.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 09:33:39 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/22 19:30:32 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wid_pre_seperater(t_set *set)
{
	char *type_set;

	type_set = ft_strdup("diuoxXfFeEgGaAcspn");
	while (!ft_strchr(type_set, *set->strs.str_to_pharse))
	{
		if (*set->strs.str_to_pharse == '.' && \
		((*(set->strs.str_to_pharse + 1) >= '1' && \
		*(set->strs.str_to_pharse + 1) <= '9') || *(set->strs.str_to_pharse + 1) == '*'))
		{
			set->strs.str_to_pharse++;
			ft_precision_detecter(set);
		}
		else if ((*set->strs.str_to_pharse == '+' || \
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
		else if (set->lenths.width == 0)
			ft_width_detecter(set);
		else
			set->strs.str_to_pharse++;
	}
	set->type = *set->strs.str_to_pharse;
}
