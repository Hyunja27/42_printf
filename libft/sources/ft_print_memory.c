/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 00:42:36 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/21 00:50:49 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char g_str[16];
char *g_hexline;

void	hexarize(long long nbr)
{
	if (nbr > 15)
	{
		hexarize(nbr / 16);
		hexarize(nbr % 16);
	}
	else
		write(1, &g_hexline[nbr % 16], 1);
}

char	*hex_addr_print(long long addr, int count)
{
	long long tmp;

	tmp = addr;
	while (tmp > 0)
	{
		tmp = tmp / 16;
		count++;
	}
	while (count < 16)
	{
		write(1, "0", 1);
		count++;
	}
	hexarize((long long)addr);
	write(1, ":", 1);
	return (0);
}

char	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*tmp;
	int				len;
	char			*rt;

	rt = 0;
	g_hexline = "0123456789abcdef";
	while (size)
	{
		if (size / 16)
			len = 16;
		else
			len = size;
		tmp = (unsigned char *)addr;
		rt = hex_addr_print((long long)tmp, 0);
	}
	return (rt);
}
