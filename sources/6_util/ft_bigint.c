/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:22:41 by hyunja            #+#    #+#             */
/*   Updated: 2020/11/22 14:56:56 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_add_arr(char **rt, char **src)
{
	int		rt_len;
	int		src_len;
	int		tmp;
	int		carry;
	int		num;

	src_len = ft_strlen(*src) - 1;
	rt_len = ft_strlen(*rt);
	carry = 0;
	while (src_len >= 0)
	{
		tmp = ((*rt)[src_len] - '0') + ((*src)[src_len] - '0');
		num = ((tmp % 10) + carry);
		(*rt)[src_len] = num % 10 + '0';
		carry = (num >= 10) ? 1 + (tmp / 10) : (tmp / 10);
		src_len--;
	}
}

static void		ft_five_array(char **rt, int i)
{
	int	len;
	int	tmp;
	int round;

	if (i > 0)
	{
		round = 0;
		len = ft_strlen(*rt) - 1;
		while (len >= 0)
		{
			tmp = ((*rt)[len] - '0') * 5;
			(*rt)[len + 1] = ((tmp % 10) + round) + '0';
			round = (tmp / 10);
			if (len == 0)
				(*rt)[len] = round + '0';
			len--;
		}
	}
}

static void		ft_bigint_2(t_set *set, char *bin, char **five, char **rt)
{
	int		i;
	int		exp;

	i = 0;
	exp = set->f.s_bit.expond - 1023;
	i = (exp < 0) ? -exp : 0;
	if (exp < 0)
		bin[i - 1] = '1';
	exp = exp >= 0 ? 51 - exp : 51;
	while (exp >= 0)
		bin[i++] = ((set->f.s_bit.sgnfi >> (exp--)) & 1) ? '1' : '0';
	i = -1;
	while (bin[++i])
	{
		ft_five_array(five, i);
		if (bin[i] == '1')
			ft_add_arr(rt, five);
	}
	free(*five);
	if (!(*five = calloc(set->lenths.precision \
	- set->e_expond + 1, sizeof(char))))
		return ;
	ft_array_round(set, *rt, set->lenths.precision - set->e_expond);
	ft_memmove(*five, *rt, \
	set->lenths.precision - set->e_expond);
}

char			*ft_bigint(t_set *set)
{
	char	tmp_bin[1075];
	char	*tmp_five;
	char	*tmp_rt;

	tmp_rt = 0;
	ft_memset_chr(tmp_bin, '0', 1075);
	if (!(tmp_five = calloc(1075, sizeof(char))))
		return (0);
	if (!(tmp_rt = calloc(1075, sizeof(char))))
		return (0);
	ft_memset_chr(tmp_five, '\0', 1074);
	ft_memset_chr(tmp_rt, '0', 1074);
	tmp_five[0] = '5';
	tmp_five[1074] = 0;
	tmp_rt[1074] = 0;
	tmp_bin[1074] = 0;
	ft_bigint_2(set, tmp_bin, &tmp_five, &tmp_rt);
	free(tmp_rt);
	return (tmp_five);
}
