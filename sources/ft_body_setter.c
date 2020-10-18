/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body_setter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:27:52 by spark             #+#    #+#             */
/*   Updated: 2020/10/19 01:37:04 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	plus_adder(t_set *set)
{
	char	*tmp;

	if ((set->flags.plus_flag == 1) && (set->flags.zeroflag == 1))
		set->strs.str_flaged[0] = '+';
	else if (set->flags.plus_flag == 1)
	{
		if (!(tmp = malloc(sizeof(char) * ft_strlen(set->strs.str_body) + 1)))
			return ;
		tmp[0] = '+';
		ft_strlcpy(tmp + 1, set->strs.str_body, \
		ft_strlen(set->strs.str_body) + 1);
		set->strs.str_body = tmp;
	}
}

void	ft_body_setter(t_set *set)
{
	int		padding;
	char	*rt;

	rt = NULL;
	padding = set->lenths.total_len;
	set->va_str = ft_itoa(set->num);
	if ((set->precision_yn == 1) && \
	(set->lenths.precision > ft_int_len(set->num)))
	{
		if (!(set->strs.str_body = \
		malloc(sizeof(char) * (set->lenths.precision + 1))))
			return ;
		set->strs.str_body = ft_memset_chr(set->strs.str_body, '0'\
		, set->lenths.precision + 1);
		set->strs.str_body[set->lenths.precision] = 0;
		padding = set->lenths.precision - ft_int_len(set->num);
		ft_strlcpy(set->strs.str_body + padding, \
		set->va_str, ft_int_len(set->num) + 1);
	}
	else
		set->strs.str_body = set->va_str;
	plus_adder(set);
	free(set->va_str);
}
