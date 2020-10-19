/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body_setter_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:59:02 by spark             #+#    #+#             */
/*   Updated: 2020/10/19 20:02:47 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_body_setter_str(t_set *set)
{
	int		padding;

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
