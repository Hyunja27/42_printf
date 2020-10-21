/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 09:40:49 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/21 10:56:45 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat_chr(char const *s1, char c)
{
	int		len;
	char	*rt;

	if (s1 == NULL)
		return (0);
	len = ft_strlen(s1) + 1;
	printf("\ns1 : >>%d",(int)ft_strlen(s1));
	printf("\nlen : >>>%d",len);
	if (!(rt = malloc(sizeof(char) * len + 1)))
		return (0);
	printf("\nmalloced_len : >>>>%d\n",(int)ft_strlen(rt));
	ft_memmove(rt, (char*)s1, ft_strlen(s1));
	printf("\nrt_len : >>>>%d\n",(int)ft_strlen(rt));
	rt[len] = c;
	rt[len + 1] = 0;
	// while(*rt)
	// 	printf("[%c]", *rt++);
	return (rt);
}
