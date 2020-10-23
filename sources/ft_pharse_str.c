/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pharse_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 21:33:17 by spark             #+#    #+#             */
/*   Updated: 2020/10/23 16:02:45 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pharse_str(t_set *set)
{
	int		i;
	char 	*type_set;

	type_set = ft_strdup("diuoxXfFeEgGaAcspn\0");
	i = 0;
	while (!ft_strchr(type_set, set->strs.str_to_pharse[i]))
	{
		if (set->strs.str_to_pharse[i] == '-')
			set->flags.lefted = 1;
		if (set->strs.str_to_pharse[i] == '.')
			set->precision_yn = 1;
		if (set->strs.str_to_pharse[i] == '+')
			set->flags.plus_flag = 1;
		if (set->strs.str_to_pharse[i] == '0')
			set->flags.zeroflag = 1;
		else if (set->strs.str_to_pharse[i] == ' ')
			set->flags.spaceflag = 1;
		else if (set->strs.str_to_pharse[i] == '#')
			set->flags.shap_flag = 1;
		i++;
	}
	set->strs.str_to_pharse++;
	free(type_set);
	ft_wid_pre_seperater(set);
}
