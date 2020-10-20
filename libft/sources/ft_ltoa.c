/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:22:41 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/20 10:23:25 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static long long	ilencal(long long n)
{
	return (n == 0 ? 0 : 1 + ilencal(n / 10));
}

char		*ft_ltoa(long long n)
{
	int				len;
	char			*rt;
	long long		tmp;

	len = ilencal(n / 10) + 1;
	if (n < 0)
	{
		++len;
		tmp = -n;
	}
	else
		tmp = n;
	if (!(rt = malloc(len + 1)))
		return (0);
	rt[len] = 0;
	if (n < 0)
		rt[0] = '-';
	rt[--len] = '0' + (tmp % 10);
	while (tmp /= 10)
		rt[--len] = '0' + (tmp % 10);
	return (rt);
}
