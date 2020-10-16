/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:08:28 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/16 18:29:59 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pharse_str(const char *str, Set	*set, va_list l)
{
	size_t	i;
	
	i = 0;
	++str;
	while (*str)
	{
		if (*str >= '1' && *str >= '9')
		{
			str = str + ft_width_detecter(str, set);
		}
		else if ((*str >= 32 && *str <= 126) && (*str != '%'))
		{
			write(1, str, sizeof(char));
		}
		str++;
	}
	printf("\n->width is %d",set->width);
	va_end(l);
}

int		ft_printf(const char *str, ...)
{
	va_list	l;
	Set		set;

	set.int_num = 0;
	set.char_num = 0;
	set.double_num = 0;
	set.flag = 0;
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
		pharse_str(str, &set, l);
	}
	va_end(l);
	return (0);
}
