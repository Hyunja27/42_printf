/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:33:45 by spark             #+#    #+#             */
/*   Updated: 2020/11/22 18:50:20 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_str_2(t_set *set)
{
	int		i;
	char	*tmp_flaged;

	i = 0;
	tmp_flaged = set->strs.str_flaged;
	ft_flag_setter(set);
	ft_body_setter_str(set);
	if ((set->strs.str_body[0] == '\0') && \
	(set->lenths.width) == 0)
		;
	else if ((set->strs.str_body[0] == '\0') && \
	(set->lenths.width) != 0)
		set->rt_byte += write(1, set->strs.str_flaged, set->lenths.width);
	else if (set->flags.just_bd == 0)
		set->rt_byte += write(1, set->strs.str_flaged, set->lenths.print_len);
	ft_free_va(1, set->strs.str_flaged);
	if (!ft_strncmp(set->strs.str_body, "(null)", 6))
		free(set->strs.str_body);
}

void		ft_printf_str(t_set *set, va_list l)
{
	int		i;
	char	*tmp_flaged;

	i = 0;
	set->strs.str_body = va_arg(l, char*);
	tmp_flaged = set->strs.str_flaged;
	if (set->strs.str_body == NULL)
		set->strs.str_body = ft_strdup("(null)");
	set->lenths.total_len = (int)ft_strlen(set->strs.str_body);
	if (set->precision_yn == 1)
		set->lenths.total_len = ((int)ft_strlen(set->strs.str_body) <=\
	(set->lenths.precision)) ? (int)ft_strlen(set->strs.str_body) : \
	(set->lenths.precision);
	set->lenths.total_len = (set->lenths.total_len > \
	(set->lenths.width)) ? (set->lenths.total_len) : (set->lenths.width);
	set->lenths.print_len = set->lenths.total_len;
	if (!(set->strs.str_flaged = malloc(sizeof(char) * \
	(set->lenths.total_len + 2))))
		return ;
	set->strs.str_flaged[set->lenths.total_len + 1] = 0;
	set->strs.str_flaged[set->lenths.total_len] = 0;
	ft_printf_str_2(set);
}
