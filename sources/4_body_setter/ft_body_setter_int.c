/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_body_setter_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:59:02 by spark             #+#    #+#             */
/*   Updated: 2020/11/23 16:55:28 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_body_setter_wid_minus(t_set *set)
{
	int		padding;

	padding = set->lenths.total_len;
	free(set->va_str);
	set->va_str = ft_ltoa_no_minus(set->num);
	if ((set->lenths.width > ft_int_len(set->num)) && \
	(set->flags.zeroflag == 1) && (set->precision_yn == 0))
	{
		free(set->strs.str_body);
		if (!(set->strs.str_body = \
		malloc(sizeof(char) * (set->lenths.width + 1))))
			return ;
		set->strs.str_body = ft_memset_chr(set->strs.str_body, '0'\
		, set->lenths.width + 1);
		set->strs.str_body[set->lenths.width] = 0;
		set->strs.str_body[0] = '-';
		padding = set->lenths.width - ft_int_len(set->num);
		ft_strlcpy(set->strs.str_body + padding, \
		set->va_str, ft_int_len(set->num) + 1);
	}
	else
	{
		free(set->strs.str_body);
		set->strs.str_body = ft_itoa(set->num);
	}
}

static void		ft_body_setter_pres_minus(t_set *set)
{
	int		p;

	free(set->va_str);
	set->va_str = ft_ltoa_no_minus(set->num);
	if (!((set->flags.zeroflag == 1) && \
	((set->lenths.width) > ft_int_len(set->num))))
		free(set->strs.str_body);
	if ((set->lenths.precision > ft_int_len(set->num)))
	{
		if (!(set->strs.str_body = \
		ft_calloc((set->lenths.precision + 2), sizeof(char))))
			return ;
		set->strs.str_body = ft_memset_chr(set->strs.str_body, '0'\
		, set->lenths.precision + 2);
		set->strs.str_body[0] = '-';
		p = set->lenths.precision + 1 - ft_int_len(set->num);
		ft_strlcpy(set->strs.str_body + p, \
		set->va_str, ft_int_len(set->num) + 1);
	}
	else if ((set->flags.zeroflag == 1) && \
	((set->lenths.width) > ft_int_len(set->num)) && set->flags.lefted != 1)
		ft_body_setter_wid_minus(set);
	else
		set->strs.str_body = ft_ltoa(set->num);
	free(set->va_str);
}

static void		plus_adder(t_set *set)
{
	char	*tmp;

	if (((set->flags.zeroflag == 1) && (ft_strlen(set->strs.str_body) < \
	ft_strlen(set->strs.str_flaged)) && \
	(set->num > 0) && set->strs.str_flaged[0] == '0'))
		set->strs.str_flaged[0] = '+';
	else if (set->num >= 0)
	{
		if (!(tmp = ft_strjoin("+", set->strs.str_body)))
			return ;
		free(set->strs.str_body);
		set->strs.str_body = tmp;
	}
}

static void		ft_body_setter_int_2(t_set *set)
{
	int		padding;
	int		tmp;

	tmp = (set->flags.ull_on == 1) ? ulllencal(set->num_ull) : \
	ft_ilencal(set->num);
	padding = set->lenths.total_len;
	ft_free_va(1, set->va_str);
	if (set->flags.ull_on == 0)
		set->va_str = ft_ltoa(set->num);
	else
		set->va_str = ft_ultoa(set->num_ull);
	if (!(set->strs.str_body = malloc(sizeof(char) * \
	(set->lenths.precision + 1))))
		return ;
	set->strs.str_body = ft_memset_chr(set->strs.str_body, '0'\
	, set->lenths.precision + 1);
	set->strs.str_body[set->lenths.precision] = 0;
	padding = set->lenths.precision - tmp;
	padding = (padding < 0) ? -padding : padding;
	ft_memmove(set->strs.str_body + padding, set->va_str, tmp);
	ft_free_va(1, set->va_str);
}

void			ft_body_setter_int(t_set *set)
{
	int		padding;

	padding = set->lenths.total_len;
	if (set->flags.ull_on == 0)
		set->va_str = ft_ltoa(set->num);
	else
		set->va_str = ft_ultoa(set->num_ull);
	if (set->flags.just_bd == 1)
	{
		ft_memmove(set->strs.str_flaged, set->va_str, ft_strlen(set->va_str));
		if (set->lenths.width < set->lenths.precision)
			set->strs.str_flaged[ft_strlen(set->va_str)] = 0;
		ft_free_va(1, set->va_str);
	}
	else if ((set->num >= 0) && (set->precision_yn == 1) && \
	(set->lenths.precision >= ((set->flags.ull_on == 1) ? \
	ulllencal(set->num_ull) : ft_ilencal(set->num))))
		ft_body_setter_int_2(set);
	else if (set->num < 0)
		ft_body_setter_pres_minus(set);
	else
		set->strs.str_body = set->va_str;
	if (set->flags.plus_flag == 1)
		plus_adder(set);
}
