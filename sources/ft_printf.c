/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:08:28 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/19 10:44:28 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		l;
	t_set		set;
	int			rt_byte;

	ft_set_clear(&set);
	set.strs.str_to_pharse = str;
	va_start(l, str);
	rt_byte = 0;
	while (*set.strs.str_to_pharse)
	{
		if ((*set.strs.str_to_pharse != '%'))
			rt_byte += write(1, set.strs.str_to_pharse, 1);
		else if ((*set.strs.str_to_pharse == '%') && \
		*(set.strs.str_to_pharse + 1) == '%')
		{
			rt_byte += write(1, set.strs.str_to_pharse, 1);
			set.strs.str_to_pharse++;
		}
		else if ((*set.strs.str_to_pharse == '%'))
		{
			ft_pharse_str(&set);
			rt_byte += ft_printf_with_set(&set, l);
		}
		set.strs.str_to_pharse++;
		ft_set_clear(&set);
	}
	printf("\n\nprecision yn: %d\n", set.precision_yn);
	printf("zero flags : %d\n", set.flags.zeroflag);
	printf("space flags : %d\n", set.flags.spaceflag);
	printf("lefted : %d\n", set.flags.lefted);
	printf("precision: %d\n", set.lenths.precision);
	printf("width : %d\n", set.lenths.width);
	printf("type is : %c\n", set.type);
	printf("return byte : %d\n", rt_byte);
	printf("int that print is : %s\n", set.va_str);
	printf("body str is : %s\n", set.strs.str_body);
	ft_set_clear(&set);
	va_end(l);
	return (rt_byte);
}
