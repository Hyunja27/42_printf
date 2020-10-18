/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pharse_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 21:33:17 by spark             #+#    #+#             */
/*   Updated: 2020/10/18 16:43:19 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_pharse_str(const char *str, t_set *set)
{
	size_t	i;

	i = 0;
	++str;
	if (ft_strchr(str, '-'))
		set->lefted = 1;
	if (ft_strchr(str, '.'))
		set->precision_yn = 1;
	if (ft_strchr(str, '+'))
		set->plus_flag = 1;
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
	return (str);
}
