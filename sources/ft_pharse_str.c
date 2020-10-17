/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pharse_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 21:33:17 by spark             #+#    #+#             */
/*   Updated: 2020/10/17 09:36:19 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pharse_str(const char *str, Set *set)
{
	size_t	i;

	i = 0;
	++str;
	if (ft_strchr(str, '-'))
		set->lefted = 1;
	if (ft_strchr(str, '.'))
		set->precision_yn = 1;
	if (*str == '0')
	{
		set->zeroflag = 1;
		str++;
	}
	else if (*str == ' ')
	{
		set->spaceflag = 1;
		str++;
	}
	str = ft_wid_pre_seperater(str, set);
}
