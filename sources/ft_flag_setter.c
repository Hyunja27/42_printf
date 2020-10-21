/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:45:25 by spark             #+#    #+#             */
/*   Updated: 2020/10/21 11:21:54 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_setter(t_set *set)
{
	if ((set->flags.lefted == 1) && (set->flags.zeroflag == 1))
		set->strs.str_flaged = \
		ft_memset_chr(set->strs.str_flaged, ' ', set->lenths.total_len + 1);
	else if ((set->flags.zeroflag == 1) && (set->precision_yn == 1) && \
			(set->lenths.total_len == set->lenths.width))
		set->strs.str_flaged = ft_memset_chr(set->strs.str_flaged, ' ', \
		set->lenths.total_len + 1);
	else if (set->flags.zeroflag == 1)
		set->strs.str_flaged = ft_memset_chr(set->strs.str_flaged, ' ', \
		set->lenths.total_len + 1);
	if (set->flags.zeroflag == 0)
		set->strs.str_flaged = ft_memset_chr(set->strs.str_flaged, ' ', \
		set->lenths.total_len + 1);
	else if ((set->flags.zeroflag == 1) && (set->precision_yn == 0))
		set->strs.str_flaged = ft_memset_chr(set->strs.str_flaged, '0', \
		set->lenths.total_len + 1);
	set->strs.str_flaged[set->lenths.total_len] = 0;
	
	// int i = 0;
	// while(set->strs.str_flaged[i])
	// {
	// 	printf("[]");
	// 	i++;
	// }
}
