/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:45:25 by spark             #+#    #+#             */
/*   Updated: 2020/10/18 16:43:15 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_setter(char *rt, t_set *set, int total_len)
{
	if ((set->lefted == 1) && (set->zeroflag == 1))
		rt = ft_memset_chr(rt, ' ', total_len + 1);
	else if ((set->zeroflag == 1) && (set->precision_yn == 1) && \
			(total_len == set->width))
		rt = ft_memset_chr(rt, ' ', total_len + 1);
	else if (set->zeroflag == 1)
		rt = ft_memset_chr(rt, ' ', total_len + 1);
	if (set->zeroflag == 0)
		rt = ft_memset_chr(rt, ' ', total_len + 1);
	else if ((set->zeroflag == 1) && (set->precision_yn == 0))
		rt = ft_memset_chr(rt, '0', total_len + 1);
	rt[total_len] = 0;
	while (*rt)
		printf("[%c]", *rt++);
}
