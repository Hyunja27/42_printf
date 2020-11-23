/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pharse_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:43:31 by spark             #+#    #+#             */
/*   Updated: 2020/11/19 02:10:30 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_pharse_str(t_set *set)
{
	int		i;
	char	*type_set;

	type_set = ft_strdup("diuoxXfFeEgGaAcspn\0");
	i = -1;
	while (!ft_strchr(type_set, set->strs.str_to_pharse[++i]))
	{
		if (set->strs.str_to_pharse[i] == '-')
			set->flags.lefted = 1;
		if (set->strs.str_to_pharse[i] == '.')
			set->precision_yn = 1;
		if (set->strs.str_to_pharse[i] == '+')
			set->flags.plus_flag = 1;
		if ((set->strs.str_to_pharse[i] == '0') && \
		(!ft_isdigit(set->strs.str_to_pharse[i - 1]) \
		&& set->strs.str_to_pharse[i - 1] != '.'))
			set->flags.zeroflag = 1;
		else if (set->strs.str_to_pharse[i] == ' ')
			set->flags.spaceflag = 1;
		else if (set->strs.str_to_pharse[i] == '#')
			set->flags.shap_flag = 1;
	}
	set->strs.str_to_pharse++;
	free(type_set);
	ft_wid_pre_seperater(set);
}
