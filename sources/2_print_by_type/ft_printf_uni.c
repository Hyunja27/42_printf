/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uni.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:33:45 by spark             #+#    #+#             */
/*   Updated: 2020/11/22 15:48:27 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void		ft_uni_encode_4(t_set *set)
{
	char			*rt;
	unsigned char	tmp1;
	unsigned char	tmp2;

	tmp1 = 0;
	tmp1 = set->num >> 18;
	tmp1 = tmp1 & 31;
	tmp1 = tmp1 | 240;
	tmp2 = 0;
	tmp2 = set->num >> 12;
	tmp2 = tmp2 & 63;
	tmp2 = tmp2 | 128;
	rt = ft_chrcat_chr(tmp1, tmp2);
	tmp2 = set->num >> 6;
	tmp2 = tmp2 & 63;
	tmp2 = tmp2 | 128;
	rt = ft_strcat_chr(rt, tmp2);
	tmp2 = 0;
	tmp2 = set->num & 63;
	tmp2 = tmp2 | 128;
	rt = ft_strcat_chr(rt, tmp2);
	set->chr = *rt;
}

static	void		ft_uni_encode_3(t_set *set)
{
	char			*rt;
	unsigned char	tmp1;
	unsigned char	tmp2;

	tmp1 = 0;
	tmp1 = set->num >> 12;
	tmp1 = tmp1 & 31;
	tmp1 = tmp1 | 224;
	tmp2 = 0;
	tmp2 = set->num >> 6;
	tmp2 = tmp2 & 63;
	tmp2 = tmp2 | 128;
	rt = ft_chrcat_chr(tmp1, tmp2);
	tmp2 = 0;
	tmp2 = set->num & 63;
	tmp2 = tmp2 | 128;
	rt = ft_strcat_chr(rt, tmp2);
	set->chr = *rt;
}

static void			ft_uni_encode_2(t_set *set)
{
	char			*rt;
	unsigned char	tmp1;
	unsigned char	tmp2;

	tmp1 = 0;
	tmp1 = set->num >> 6;
	tmp1 = tmp1 & 31;
	tmp1 = tmp1 | 192;
	tmp2 = 0;
	tmp2 = set->num & 63;
	tmp2 = tmp2 | 128;
	rt = ft_chrcat_chr(tmp1, tmp2);
	set->chr = *rt;
}

void				ft_printf_uni(t_set *set, va_list l)
{
	set->num = va_arg(l, int);
	if ((set->num | 127) == 127)
		set->rt_byte += write(1, &set->num, 1);
	else if ((set->num | 2047) == 2047)
		ft_uni_encode_2(set);
	else if ((set->num | 65535) == 65535)
		ft_uni_encode_3(set);
	else if ((set->num | 2097151) == 2097151)
		ft_uni_encode_4(set);
	set->lenths.total_len = \
	(1 > set->lenths.width) ? 1 : set->lenths.width;
	if (!(set->strs.str_flaged = malloc(sizeof(char) * \
		(set->lenths.total_len + 1))))
		return ;
	ft_flag_setter(set);
	ft_body_setter_str(set);
	set->rt_byte += write(1, set->strs.str_flaged, set->lenths.total_len);
	ft_free_va(2, set->strs.str_body, set->strs.str_flaged);
}
