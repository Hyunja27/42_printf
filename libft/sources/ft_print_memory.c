/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 00:42:36 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/21 10:51:00 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *g_hexline;
char *g_body;

void	hexarize(long long nbr)
{
	if (nbr > 15)
	{
		hexarize(nbr / 16);
		hexarize(nbr % 16);
	}
	else
	{
		write(1, &g_hexline[nbr % 16], 1);
		g_body = ft_strcat_chr(g_body, g_hexline[nbr % 16]);
	}
}

void	hex_addr_print(long long addr, int count)
{
	long long tmp;

	tmp = addr;
	while (tmp > 0)
	{
		tmp = tmp / 16;
		count++;
	}
	hexarize((long long)addr);
}

char	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*tmp;
	int				index;
	int				len;

	if (!(g_body = malloc(sizeof(char) * 2)))
		return (0);
	g_body[0] = '0';
	g_body[1] = 'x';
	g_hexline = "0123456789abcdef";
	index = 0;
	while (size)
	{
		if (size / 16)
			len = 16;
		else
			len = size;
		tmp = (unsigned char *)addr + index;
		hex_addr_print((long long)tmp, 0);
		size = size - len;
		index = index + 16;
	}
	return (g_body);
}
