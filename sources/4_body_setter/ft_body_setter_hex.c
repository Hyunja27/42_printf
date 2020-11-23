/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body_setter_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:59:02 by spark             #+#    #+#             */
/*   Updated: 2020/11/22 15:59:27 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_shap_adder(t_set *set)
{
	char	*tmp;
	char	*be_free;

	tmp = 0;
	if (set->flags.shap_flag == 1)
	{
		if (((set->type == 'o')) && (set->lenths.precision + 1 <= \
		(int)ft_strlen(set->strs.str_body)))
			tmp = ft_strdup("0");
		else if ((set->type == 'x') || (set->type == 'X'))
			tmp = ft_strdup("0x");
		be_free = set->strs.str_body;
		set->strs.str_body = ft_strjoin_free(tmp, set->strs.str_body);
		set->flags.add = 1;
	}
}

static void		ft_body_setter_hex_2(t_set *set)
{
	int		padding;
	char	*tmp_body;
	int		body_str_len;

	tmp_body = set->strs.str_body;
	body_str_len = ft_strlen(tmp_body);
	padding = set->lenths.total_len;
	if (!(set->strs.str_body = \
	malloc(sizeof(char) * (set->lenths.precision + 2))))
		return ;
	set->strs.str_body = ft_memset_chr(set->strs.str_body, '0'\
	, set->lenths.precision + 2);
	set->strs.str_body[set->lenths.precision] = 0;
	set->strs.str_body[set->lenths.precision + 1] = 0;
	padding = set->lenths.precision - body_str_len;
	ft_memmove(set->strs.str_body + padding, tmp_body, body_str_len);
	free(tmp_body);
	if (set->num != 0)
		ft_shap_adder(set);
}

void			ft_body_setter_hex(t_set *set)
{
	int		padding;
	char	*tmp_body;
	int		body_str_len;

	tmp_body = set->strs.str_body;
	body_str_len = ft_strlen(tmp_body);
	padding = set->lenths.total_len;
	if ((set->num >= 0) && (set->precision_yn == 1) && \
	(set->lenths.precision > body_str_len))
		ft_body_setter_hex_2(set);
	else if ((set->num != 0) && (set->flags.zeroflag == 0 ||\
		((int)ft_strlen(tmp_body) >= \
		set->lenths.total_len) || set->precision_yn == 1))
		ft_shap_adder(set);
	free(set->va_str);
}
