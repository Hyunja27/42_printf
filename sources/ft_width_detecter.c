/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_detecter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:48:16 by spark             #+#    #+#             */
/*   Updated: 2020/10/19 01:03:20 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_detecter(t_set *set)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (set->strs.str_to_pharse[i] >= '0' && \
			set->strs.str_to_pharse[i] <= '9')
		i++;
	ptr = ft_strndup(set->strs.str_to_pharse, i);
	set->lenths.width = ft_atoi(ptr);
	set->strs.str_to_pharse = set->strs.str_to_pharse + i;
}
