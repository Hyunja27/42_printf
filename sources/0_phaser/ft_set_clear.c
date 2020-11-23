/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:41:03 by spark             #+#    #+#             */
/*   Updated: 2020/11/22 17:49:08 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_clear_2(t_set *set)
{
	set->flags.just_bd = 0;
	set->flags.e_absilon = 0;
	set->db_aster_pre = 0;
	set->e_expond = 0;
	set->pre_is_zero = 0;
	set->lenths.precision = 0;
	set->lenths.total_len = 0;
	set->lenths.width = 0;
	set->lenths.print_len = 0;
	set->lenths.origin_precs = 0;
	set->f.d = 0;
	set->f.s_bit.expond = 0;
	set->f.s_bit.sgnfi = 0;
	set->f.s_bit.sign = 0;
}

void		ft_set_clear(t_set *set)
{
	set->val = 0;
	set->type = 0;
	set->va_str = 0;
	set->num = 0;
	set->num_ull = 0;
	set->chr = 0;
	set->ex.h = 0;
	set->ex.hh = 0;
	set->ex.l = 0;
	set->ex.ll = 0;
	set->precision_yn = 0;
	set->strs.str_body = 0;
	set->strs.str_flaged = 0;
	set->strs.str_to_print = 0;
	set->flags.lefted = 0;
	set->flags.plus_flag = 0;
	set->flags.spaceflag = 0;
	set->flags.zeroflag = 0;
	set->flags.shap_flag = 0;
	set->flags.ull_on = 0;
	set->flags.add = 0;
	ft_set_clear_2(set);
}
