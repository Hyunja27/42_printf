/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body_setter_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:59:02 by spark             #+#    #+#             */
/*   Updated: 2020/10/20 22:07:39 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_body_setter_hex(t_set *set)
{
	int		padding;
	char	*tmp_body;
	int		body_str_len;

	body_str_len = ft_strlen(tmp_body);
	tmp_body = set->strs.str_body;
	padding = set->lenths.total_len;
	if ((set->precision_yn == 1) && (set->lenths.precision > body_str_len))
	{
		if (!(tmp_body = malloc(sizeof(char) * (set->lenths.precision + 1))))
			return ;
		tmp_body = ft_memset_chr(tmp_body, '0', set->lenths.precision + 1);
		tmp_body[set->lenths.precision] = 0;
		padding = set->lenths.precision - body_str_len;
		ft_memmove(tmp_body + padding, tmp_body, body_str_len + 1);
	}
	if ((padding > body_str_len) && (set->flags.lefted == 0))
	{
		padding = set->lenths.total_len - (int)body_str_len;
		ft_strlcpy(set->strs.str_flaged + padding, tmp_body, body_str_len + 1);
	}
	else if ((padding > body_str_len) && (set->flags.lefted == 1))
		ft_memmove(set->strs.str_flaged, tmp_body, body_str_len);
	else
		ft_strlcpy(set->strs.str_flaged, tmp_body, body_str_len + 1);
	free(set->va_str);
}
