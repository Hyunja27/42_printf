/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_detecter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 17:48:16 by spark             #+#    #+#             */
/*   Updated: 2020/10/17 10:43:37 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_precision_detecter(const char *str, Set *set)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	ptr = ft_strndup(str, i);
	set->precision = ft_atoi(ptr);
	return (&str[i]);
}
