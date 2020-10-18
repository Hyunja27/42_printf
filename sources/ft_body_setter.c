/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:27:52 by spark             #+#    #+#             */
/*   Updated: 2020/10/18 22:02:39 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_body_setter(t_set *set)
{
	int		padding;
	char	*rt;

	rt = NULL;
	padding = set->lenths.total_len;
	set->va = ft_itoa(set->num);
	if ((set->precision_yn == 1) && \
	(set->lenths.precision > ft_int_len(set->num)))
	{
		if (!(set->strs.str_body = \
		malloc(sizeof(char) * (set->lenths.precision + 1))))
			return (NULL);
		set->strs.str_body = ft_memset_chr(rt, '0', set->lenths.precision + 1);
		set->strs.str_body[set->lenths.precision] = 0;
		padding = set->lenths.precision - ft_int_len(set->num);
		ft_strlcpy(set->strs.str_body + padding, \
		set->va, ft_int_len(set->num) + 1);
	}
	set->va = set->strs.str_flaged;
	rt = set->va;
	return (NULL);
}
