/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:35:52 by spark             #+#    #+#             */
/*   Updated: 2020/10/18 22:04:12 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_left_setter(t_set *set)
{
	int	padding;

	padding = 0;
	if ((set->flags.lefted == 0) && (ft_strlen(set->strs.str_flaged) \
		> ft_strlen(set->strs.str_body)))
	{
		padding = ft_strlen(set->strs.str_flaged) \
		- ft_strlen(set->strs.str_body);
		ft_strlcpy(set->strs.str_flaged + padding, set->strs.str_body,\
		ft_strlen(set->strs.str_body) + 1);
	}
	if ((set->flags.lefted == 1) && (ft_strlen(set->strs.str_flaged) \
		> ft_strlen(set->strs.str_body)))
	{
		ft_strlcpy(set->strs.str_flaged, set->strs.str_body,\
		ft_strlen(set->strs.str_body) + 1);
	}
}
