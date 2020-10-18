/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:41:03 by spark             #+#    #+#             */
/*   Updated: 2020/10/18 16:44:13 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_clear(t_set *set)
{
	set->type = 0;
	set->num = 0;
	set->precision_yn = 0;
	set->double_num = 0;
	set->zeroflag = 0;
	set->spaceflag = 0;
	set->lefted = 0;
	set->precision = 0;
	set->val = 0;
	set->width = 0;
	set->plus_flag = 0;
}
