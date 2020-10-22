/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body_setter_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:59:02 by spark             #+#    #+#             */
/*   Updated: 2020/10/22 18:17:54 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_body_setter_wid_minus(t_set *set)
{
	int		padding;

	padding = set->lenths.total_len;
	set->va_str = ft_itoa_no_minus(set->num);
	if ((set->lenths.width > ft_int_len(set->num)) && \
	(set->flags.zeroflag == 1) && (set->precision_yn == 0))
	{
		if (!(set->strs.str_body = \
		malloc(sizeof(char) * (set->lenths.width + 1))))
			return ;
		set->strs.str_body = ft_memset_chr(set->strs.str_body, '0'\
		, set->lenths.width + 1);
		set->strs.str_body[set->lenths.width + 1] = 0;
		set->strs.str_body[0] = '-';
		padding = set->lenths.width - ft_int_len(set->num);
		ft_strlcpy(set->strs.str_body + padding, \
		set->va_str, ft_int_len(set->num) + 1);
	}
	else
		set->strs.str_body = ft_itoa(set->num);
}

static void		ft_body_setter_pres_minus(t_set *set)
{
	int		padding;

	padding = set->lenths.total_len;
	set->va_str = ft_itoa_no_minus(set->num);
	if ((set->lenths.precision > ft_int_len(set->num)))
	{
		if (!(set->strs.str_body = \
		malloc(sizeof(char) * (set->lenths.precision + 2))))
			return ;
		set->strs.str_body = ft_memset_chr(set->strs.str_body, '0'\
		, set->lenths.precision + 2);
		set->strs.str_body[set->lenths.precision + 1] = 0;
		set->strs.str_body[0] = '-';
		padding = set->lenths.precision + 1 - ft_int_len(set->num);
		ft_strlcpy(set->strs.str_body + padding, \
		set->va_str, ft_int_len(set->num) + 1);
	}
	else if ((set->flags.zeroflag == 1) && \
	((set->lenths.width) > ft_int_len(set->num)))
		ft_body_setter_wid_minus(set);
	else
		set->strs.str_body = ft_itoa(set->num);
}

static void		plus_adder(t_set *set)
{
	char	*tmp;

	if ((set->flags.plus_flag == 1) && (set->flags.zeroflag == 1))
		set->strs.str_flaged[0] = '+';
	else if ((set->flags.plus_flag == 1) && (set->num >= 0))
	{
		if (!(tmp = malloc(sizeof(char) * ft_strlen(set->strs.str_body) + 1)))
			return ;
		tmp[0] = '+';
		ft_strlcpy(tmp + 1, set->strs.str_body, \
		ft_strlen(set->strs.str_body) + 1);
		set->strs.str_body = tmp;
	}
}

void		ft_body_setter_int(t_set *set)
{
	int		padding;

	padding = set->lenths.total_len;
	set->va_str = ft_ltoa(set->num);
	if ((set->num >= 0) && (set->precision_yn == 1) && \
	(set->lenths.precision > ft_int_len(set->num)))
	{
		if (!(set->strs.str_body = \
		malloc(sizeof(char) * (set->lenths.precision + 1))))
			return ;
		set->strs.str_body = ft_memset_chr(set->strs.str_body, '0'\
		, set->lenths.precision + 1);
		set->strs.str_body[set->lenths.precision] = 0;
		padding = set->lenths.precision - ft_int_len(set->num);
		ft_memmove(set->strs.str_body + padding, set->va_str, \
		ft_int_len(set->num));
	}
	else if (set->num < 0)
		ft_body_setter_pres_minus(set);
	else
		set->strs.str_body = set->va_str;
	plus_adder(set);
	free(set->va_str);
}
