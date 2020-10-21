/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 17:35:52 by spark             #+#    #+#             */
/*   Updated: 2020/10/21 11:21:58 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_left_setter(t_set *set)
{
	int		padding;
	char	*tmp_flaged;
	char	*tmp_body;

	tmp_flaged = set->strs.str_flaged;
	tmp_body = set->strs.str_body;
	padding = 0;
	if ((set->flags.lefted == 0) && (ft_strlen(tmp_flaged) \
	> ft_strlen(tmp_body)))
	{
		padding = ft_strlen(tmp_flaged) - ft_strlen(tmp_body);
		ft_memmove(tmp_flaged + padding, tmp_body, ft_strlen(tmp_body) + 1);
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
	else if ((set->flags.lefted == 1) && (ft_strlen(tmp_flaged) \
		> ft_strlen(tmp_body)))
	{
		ft_memmove(tmp_flaged, tmp_body, ft_strlen(tmp_body));
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
	else
	{
		ft_memmove(tmp_flaged, tmp_body, ft_strlen(tmp_body));
		set->rt_byte += write(1, tmp_flaged, ft_strlen(tmp_flaged));
	}
}
