/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_double_g.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:15:56 by spark             #+#    #+#             */
/*   Updated: 2020/11/20 20:48:52 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_printf_double_g_2(t_set *set, va_list l)
{
	int		tmp;
	int		*pre;

	pre = &set->lenths.precision;
	tmp = (set->lenths.precision == 0) ? 1 : set->lenths.precision;
	set->lenths.precision = tmp - 1 - set->e_expond;
	if ((set->e_expond < -4) || (set->e_expond >= tmp))
	{
		if ((set->e_expond == 0) && (0 == tmp))
		{
			*pre = (set->lenths.precision < 0) ? 0 : set->lenths.precision;
			ft_printf_double(set, l);
		}
		else
		{
			set->lenths.precision = tmp - 1;
			*pre = (set->lenths.precision < 0) ? 0 : set->lenths.precision;
			ft_printf_double_e(set, l);
		}
	}
	else
	{
		*pre = (set->lenths.precision < 0) ? 0 : set->lenths.precision;
		ft_printf_double(set, l);
	}
}

void					ft_printf_double_g(t_set *set, va_list l)
{
	char	*tmp_str;
	int		tmp;

	tmp = (set->lenths.precision == 0) ? 1 : set->lenths.precision;
	if (set->precision_yn == 1 && set->lenths.precision == 0)
		set->lenths.precision = 0;
	else
		set->lenths.precision = (set->lenths.precision == 0) ? \
		6 : set->lenths.precision;
	set->f.d = va_arg(l, double);
	if ((set->precision_yn == 0) || set->db_aster_pre == 1)
		tmp_str = ft_dtoa_e(set, (set->f.d), 6 - 1, set->lenths.width);
	else if ((set->precision_yn == 1) && (set->lenths.precision == 0))
		tmp_str = ft_dtoa_e(set, (set->f.d), 0, set->lenths.width);
	else
		tmp_str = ft_dtoa_e(set, (set->f.d), \
		set->lenths.precision - 1, set->lenths.width);
	if (ft_strlen(tmp_str) > 1 && ((tmp_str[ft_strlen(tmp_str) - 1] == '0')\
	&& (tmp_str[ft_strlen(tmp_str) - 2] == '1')))
		set->e_expond++;
	ft_printf_double_g_2(set, l);
	free(tmp_str);
}
