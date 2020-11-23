/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minus_adder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:22:41 by hyunja            #+#    #+#             */
/*   Updated: 2020/11/20 21:00:36 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_minus_adder(t_set *set, char *target)
{
	char	*tmp;

	if (set->f.s_bit.sign == 1)
	{
		if (!(tmp = ft_strjoin("-", target)))
			return ;
		free(target);
		set->strs.str_body = tmp;
	}
}
