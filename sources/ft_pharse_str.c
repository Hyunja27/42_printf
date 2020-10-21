/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pharse_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 21:33:17 by spark             #+#    #+#             */
/*   Updated: 2020/10/21 14:37:33 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pharse_str(t_set *set)
{
	size_t	i;

	i = 0;
	++(set->strs.str_to_pharse);
	if (ft_strchr(set->strs.str_to_pharse, '-'))
		set->flags.lefted = 1;
	if (ft_strchr(set->strs.str_to_pharse, '.'))
		set->precision_yn = 1;
	if (ft_strchr(set->strs.str_to_pharse, '+'))
		set->flags.plus_flag = 1;
	if (*set->strs.str_to_pharse == '0')
		set->flags.zeroflag = 1;
	else if (*set->strs.str_to_pharse == ' ')
		set->flags.spaceflag = 1;
	else if (*set->strs.str_to_pharse == '#')
		set->flags.shap_flag = 1;
	ft_wid_pre_seperater(set);
}
