/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_detecter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:48:16 by spark             #+#    #+#             */
/*   Updated: 2020/10/17 16:44:05 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_width_detecter(const char *str, s_set *set)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	ptr = ft_strndup(str, i);
	set->width = ft_atoi(ptr);
	return (&str[i]);
}
