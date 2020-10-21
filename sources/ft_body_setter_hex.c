/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body_setter_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:59:02 by spark             #+#    #+#             */
/*   Updated: 2020/10/21 13:27:19 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_body_setter_hex_wid_setter(t_set *set, int body_str_len)
{
	int padding;

	padding = set->lenths.total_len;
	if ((padding > body_str_len) && (set->flags.lefted == 0))
	{
		padding = padding - body_str_len;
		ft_memmove(set->strs.str_flaged + padding, set->strs.str_body, body_str_len + 1);
	}
	else if ((padding > body_str_len) && (set->flags.lefted == 1))
		ft_memmove(set->strs.str_flaged, set->strs.str_body, body_str_len);
	else
		ft_memmove(set->strs.str_flaged, set->strs.str_body, body_str_len + 1);
	free(set->va_str);
}

void	ft_body_setter_hex(t_set *set)
{
	int		padding;
	char	*tmp_body;
	int		body_str_len;

	tmp_body = set->strs.str_body;
	body_str_len = ft_strlen(tmp_body);
	padding = set->lenths.total_len;
	if ((set->precision_yn == 1) && (set->lenths.precision > body_str_len))
	{
		if (!(tmp_body = malloc(sizeof(char) * (set->lenths.precision + 1))))
			return ;
		tmp_body = ft_memset_chr(tmp_body, '0', set->lenths.precision + 1);
		tmp_body[set->lenths.precision] = 0;
		padding = set->lenths.precision - body_str_len;
		ft_memmove(tmp_body + padding, set->strs.str_body, body_str_len + 1);
	}
	else
		ft_memmove(set->strs.str_body, tmp_body, ft_strlen(tmp_body));
	body_str_len = ft_strlen(tmp_body);
	ft_memmove(set->strs.str_body, tmp_body, ft_strlen(tmp_body));
	free(tmp_body);
	ft_body_setter_hex_wid_setter(set, body_str_len);
}
