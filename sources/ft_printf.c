/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:08:28 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/19 22:40:51 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		l;
	t_set		set;

	ft_set_clear(&set);
	set.list = &l;
	set.strs.str_to_pharse = str;
	set.rt_byte = 0;
	va_start(l, str);
	while (*set.strs.str_to_pharse)
	{
		if ((*set.strs.str_to_pharse != '%'))
			set.rt_byte += write(1, set.strs.str_to_pharse, 1);
		else if (*(set.strs.str_to_pharse + 1) && \
		((*set.strs.str_to_pharse == '%') && *(set.strs.str_to_pharse + 1) == '%'))
		{
			set.rt_byte += write(1, set.strs.str_to_pharse, 1);
			set.strs.str_to_pharse++;
		}
		else if ((*set.strs.str_to_pharse == '%'))
		{
			ft_pharse_str(&set);
			ft_printf_with_set(&set, l);
		}
		set.strs.str_to_pharse++;
		ft_set_clear(&set);
	}
	printf("\n\n>precision yn: %d\n", set.precision_yn);
	printf(">zero flags : %d\n", set.flags.zeroflag);
	printf(">space flags : %d\n", set.flags.spaceflag);
	printf(">lefted : %d\n", set.flags.lefted);
	printf(">precision: %d\n", set.lenths.precision);
	printf(">width : %d\n", set.lenths.width);
	printf(">type is : %c\n", set.type);
	printf(">return byte : %d\n", set.rt_byte);
	printf(">int that print is : %s\n", set.va_str);
	printf(">body str is : %s\n", set.strs.str_body);
	va_end(l);
	return (set.rt_byte);
}
