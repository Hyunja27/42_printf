/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:08:28 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/17 18:13:15 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		l;
	s_set		set;
	
	ft_set_clear(&set);
	va_start(l, str);
	while (*str)
	{
		if (*str != '%')
			write(1, str, 1);
		else if ((*str == '%') && *(str + 1) == '%')
		{
			write(1, str, 1);
			str++;
		}
		else
			str = ft_pharse_str(str, &set);
		ft_printf_with_set(&set, l);
		ft_set_clear(&set);
		str++;
	}
	
	printf("\n\nprecision yn: %d\n", set.precision_yn);
	printf("zero flags : %d\n", set.zeroflag);
	printf("space flags : %d\n", set.spaceflag);
	printf("lefted : %d\n", set.lefted);
	printf("precision: %d\n", set.precision);
	printf("width : %d\n", set.width);
	va_end(l);
	return (0);
}
