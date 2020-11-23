/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_detecter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:48:16 by spark             #+#    #+#             */
/*   Updated: 2020/11/20 03:26:07 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_precision_detecter_2(t_set *set)
{
	set->lenths.precision = va_arg(*set->list, int);
	if (set->lenths.precision < 0)
	{
		(set->precision_yn = 0);
		set->lenths.precision = 0;
	}
	set->strs.str_to_pharse = set->strs.str_to_pharse + 1;
}

void		ft_precision_detecter(t_set *set)
{
	char	*ptr;
	int		i;

	i = 0;
	if (set->strs.str_to_pharse[i] == '*')
		ft_precision_detecter_2(set);
	else
	{
		while (set->strs.str_to_pharse[i] >= '0' && \
		set->strs.str_to_pharse[i] <= '9')
			i++;
		ptr = ft_strndup(set->strs.str_to_pharse, i);
		set->lenths.precision = ft_atoi(ptr);
		set->lenths.origin_precs = set->lenths.precision;
		if (set->lenths.precision == 0)
			set->pre_is_zero = 1;
		set->strs.str_to_pharse = set->strs.str_to_pharse + i;
		free(ptr);
	}
}
