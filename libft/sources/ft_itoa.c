/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:34:40 by spark             #+#    #+#             */
/*   Updated: 2020/10/20 10:22:19 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ilencal(int n)
{
	return (n == 0 ? 0 : 1 + ilencal(n / 10));
}

char		*ft_itoa(int n)
{
	int				len;
	char			*rt;
	unsigned int	tmp;

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
