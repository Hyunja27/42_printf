/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_with_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:47:57 by spark             #+#    #+#             */
/*   Updated: 2020/11/15 18:03:49 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void		ex_va_arg_setter_n(t_set *set, va_list l)
{
	long int		*long_ptr;
	short int		*sh_ptr;
	signed char		*ch_ptr;
	long long int	*ll_ptr;

	if (set->ex.l == 1)
	{
		long_ptr = va_arg(l, long int*);
		*long_ptr = set->rt_byte;
	}
	else if (set->ex.ll == 1)
	{
		ll_ptr = va_arg(l, long long int*);
		*ll_ptr = set->rt_byte;
	}
	else if (set->ex.h == 1)
	{
		sh_ptr = va_arg(l, short int*);
		*sh_ptr = set->rt_byte;
	}
	else if (set->ex.hh == 1)
	{
		ch_ptr = va_arg(l, signed char*);
		*ch_ptr = set->rt_byte;
	}
}

static int			ex_checker(t_set *set)
{
	if (set->ex.h)
		return (1);
	if (set->ex.hh)
		return (1);
	if (set->ex.l)
		return (1);
	if (set->ex.ll)
		return (1);
	return (0);
}

static int			etc_checker(t_set *set)
{
	char	*type_set;

	type_set = ft_strdup("fFeEgGaA\0");
	if (ft_strchr(type_set, set->type))
		return (1);
	free(type_set);
	return (0);
}

static	void		ft_printf_with_set_2(t_set *set, va_list l)
{
	int *int_ptr;

	if (set->type == 'o')
	{
		if (!ex_checker(set))
			ft_printf_oct(set, l);
		else if (ex_checker(set))
			ft_printf_int(set, l);
	}
	else if (etc_checker(set))
		ft_printf_int(set, l);
	else if (set->type == 'n')
	{
		if (!ex_checker(set))
		{
			int_ptr = va_arg(l, int*);
			*int_ptr = set->rt_byte;
		}
		else if (ex_checker(set))
			ex_va_arg_setter_n(set, l);
	}
	else
		set->strs.str_to_pharse++;
}

void				ft_printf_with_set(t_set *set, va_list l)
{
	if (set->type == 'f')
		ft_printf_double(set, l);
	else if ((set->type == 'e') || (set->type == 'E'))
		ft_printf_double_e(set, l);
	else if ((set->type == 'g') || (set->type == 'G'))
		ft_printf_double_g(set, l);
	else if (set->type == 'd' || set->type == 'i' || set->type == 'u')
		ft_printf_int(set, l);
	else if (set->type == 's')
		ft_printf_str(set, l);
	else if (set->type == 'c')
	{
		if (set->ex.l == 1)
			ft_printf_uni(set, l);
		else
			ft_printf_char(set, l);
	}
	else if ((set->type == 'x') || (set->type == 'X'))
		ft_printf_hex(set, l);
	else if (set->type == 'p')
		ft_printf_ptr(set, l);
	else if (set->type == '%')
		ft_printf_per(set);
	else
		ft_printf_with_set_2(set, l);
}
