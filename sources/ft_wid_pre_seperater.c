/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wid_pre_seperater.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 09:33:39 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/17 10:55:09 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_wid_pre_seperater(const char *str, Set *set)
{
	char *type_set;

	type_set = ft_strdup("diuoxXfFeEgGaAcspn");
	while (!ft_strchr(type_set, *str))
	{
		if (*str == '.')
			str = ft_precision_detecter(str, set);
		else
			str = ft_width_detecter(str, set);
		str++;
	}
	return (str);
}
