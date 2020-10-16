/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:08:28 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/16 21:42:01 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list	l;
	Set		set;

	set.int_num = 0;
	set.precision_yn= 0;
	set.double_num = 0;
	set.zeroflag = 0;
	set.spaceflag = 0;
	set.lefted = 0;
	set.precision = 0;
	set.val = 0;
	set.width = 0;
	va_start(l, str);

	if (*str != '%')
	{
		write(1, str, 1);
	}
	else
	{
		ft_pharse_str(str, &set);
	}

	printf("precision yn: %d\n", set.precision_yn);
	printf("zero flags : %d\n", set.zeroflag);
	printf("space flags : %d\n", set.spaceflag);
	printf("lefted : %d\n", set.lefted);
	printf("precision: %d\n", set.precision);
	printf("width : %d\n", set.width);
	
	va_end(l);
	return (0);
}
