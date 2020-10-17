/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:15:56 by spark             #+#    #+#             */
/*   Updated: 2020/10/17 18:13:33 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ilencal(int n)
{
	return (n == 0 ? 0 : 1 + ilencal(n / 10));
}

void	ft_printf_int(s_set *set, va_list l)
{
	int		num;
	int		num_len;
	int		total_len;
	char	*rt;
	
	num = va_arg(l, int);
	num_len = ilencal(num);
	total_len = (num_len > set->width) ? num_len : set->width;
	total_len = (total_len > set->precision ) ? total_len : set->precision;
	if(!(rt = malloc(sizeof(char) * total_len)))
		return ;
}