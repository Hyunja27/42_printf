/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_detecter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:48:16 by spark             #+#    #+#             */
/*   Updated: 2020/10/18 21:16:41 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_precision_detecter(t_set *set)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (set->strs.str_to_pharse[i] >= '0' && \
			set->strs.str_to_pharse[i] <= '9')
		i++;
	ptr = ft_strndup(set->strs.str_to_pharse, i);
	set->lenths.precision = ft_atoi(ptr);
	return (&set->strs.str_to_pharse[i]);
}
