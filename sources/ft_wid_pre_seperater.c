/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wid_pre_seperater.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 09:33:39 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/17 12:42:46 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_wid_pre_seperater(const char *str, Set *set)
{
	char *type_set;

	type_set = ft_strdup("diuoxXfFeEgGaAcspn");
	while (!ft_strchr(type_set, *str))
	{
		if (*str == '.' && (*(str + 1) >= '1' && *(str + 1) <= '9'))
		{
			str++;
			str = ft_precision_detecter(str, set);
		}
		else if ((*str == '+' || \
				*str == ' ' || \
				*str == '-') \
		&& (*(str + 1) >= '1' && *(str + 1) <= '9'))
		{
			str++;
			str = ft_width_detecter(str, set);
		}
		else
			str = ft_width_detecter(str, set);
	}
	return (str);
}
