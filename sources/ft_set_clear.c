/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:41:03 by spark             #+#    #+#             */
/*   Updated: 2020/10/19 01:00:28 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_clear(t_set *set)
{
	set->val = 0;
	set->type = 0;
	set->va_str = 0;
	set->num = 0;
	set->precision_yn = 0;
	set->strs.str_body = 0;
	set->strs.str_flaged = 0;
	set->strs.str_to_print = 0;
	set->strs.str_to_pharse = 0;
	set->flags.lefted = 0;
	set->flags.plus_flag = 0;
	set->flags.spaceflag = 0;
	set->flags.zeroflag = 0;
	set->lenths.precision = 0;
	set->lenths.total_len = 0;
	set->lenths.width = 0;
}
