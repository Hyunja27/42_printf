/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_detecter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:48:16 by spark             #+#    #+#             */
/*   Updated: 2020/10/22 20:03:48 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_detecter(t_set *set)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = 0;
	if (set->strs.str_to_pharse[i] == '*')
	{
		set->lenths.width = va_arg(*set->list, int);
		set->strs.str_to_pharse = set->strs.str_to_pharse + 1;
	}
	else
	{
		while (set->strs.str_to_pharse[i] >= '0' && \
			set->strs.str_to_pharse[i] <= '9')
		i++;
		ptr = ft_strndup(set->strs.str_to_pharse, i);
		set->lenths.width = ft_atoi(ptr);
		set->strs.str_to_pharse = set->strs.str_to_pharse + i;
		// free(ptr);
	}
}
