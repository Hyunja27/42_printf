/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:27:52 by spark             #+#    #+#             */
/*   Updated: 2020/10/18 18:02:56 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_body_setter(char *flaged, t_set *set, int total_len)
{
	char	*body;
	char	*num_str;
	int		padding;
	char	*rt;

	body = NULL;
	rt = NULL;
	padding = total_len;
	num_str = ft_itoa(set->num);
	if ((set->precision_yn == 1) && (set->precision > ft_int_len(set->num)))
	{
		if (!(body = malloc(sizeof(char) * (set->precision + 1))))
			return (NULL);
		body = ft_memset_chr(rt, '0', set->precision + 1);
		body[set->precision] = 0;
		padding = set->precision - ft_int_len(set->num);
		ft_strlcpy(body + padding, num_str, ft_int_len(set->num) + 1);
		return (ft_left_setter(flaged, body, set));
	}
	rt = num_str;
	return (ft_left_setter(flaged, rt, set));
}
