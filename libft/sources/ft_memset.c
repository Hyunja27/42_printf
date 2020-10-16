/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:35:00 by spark             #+#    #+#             */
/*   Updated: 2020/09/29 14:29:01 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int tg, size_t n)
{
	void	*rt;
	size_t	i;

	i = 0;
	rt = p;
	while (i < n)
	{
		*(char*)p++ = tg;
		i++;
	}
	return (rt);
}