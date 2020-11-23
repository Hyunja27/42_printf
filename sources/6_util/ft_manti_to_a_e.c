/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manti_to_a_e.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:22:41 by hyunja            #+#    #+#             */
/*   Updated: 2020/11/22 16:07:03 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_manti_to_a_e_3_2(t_set *set, char **base)
{
	if (ft_strlen(*base) > 2)
	{
		(*base)[2] = 0;
		(*base)[1] = '.';
		if (set->flags.shap_flag == 0)
			set->e_expond++;
	}
}

static void	ft_manti_to_a_e_3(t_set *set, char **base, int i)
{
	char	*be_free;

	be_free = 0;
	(*base)[i]++;
	while (i >= 0)
	{
		if (((*base)[i] == 58) && (i > 0))
		{
			(*base)[i] = '0';
			(*base)[i - 1]++;
		}
		if ((*base)[0] == 58)
		{
			(*base)[0] = '0';
			be_free = ft_strjoin("1", *base);
			free(*base);
			*base = ft_strdup(be_free);
			free(be_free);
		}
		i--;
	}
	if ((set->type == 'e') || (set->type == 'E'))
		ft_manti_to_a_e_3_2(set, base);
}

static void	ft_manti_to_a_e_2_2(char **rt)
{
	if ((*rt)[0] != '\0')
		*rt = ft_strcat_chr(*rt, '0');
	else
		(*rt)[0] = '0';
}

static int	ft_manti_to_a_e_2(char **rt, double manti, int pre)
{
	long long		i;
	long long		tmp_int;
	double			tmp_db;
	char			*be_free;

	i = -1;
	tmp_int = 0;
	while (++i < pre + 1)
	{
		tmp_db = manti * 10;
		if ((int)tmp_db == (int)manti)
			ft_manti_to_a_e_2_2(rt);
		manti = tmp_db;
		tmp_int = (long long)manti;
		if (ft_ilencal(tmp_int) == 5)
		{
			be_free = ft_ltoa_no_minus(tmp_int);
			*rt = ft_strjoin_free(*rt, be_free);
			manti = manti - (long long)manti;
			tmp_int = 0;
		}
	}
	return (tmp_int);
}

char		*ft_manti_to_a_e(t_set *set, double manti, char *base, int pre)
{
	double			tmp_db;
	char			*rt;
	char			*be_free;

	manti = (manti < 0) ? -manti : manti;
	if (!(rt = calloc(2, sizeof(char))))
		return (0);
	tmp_db = manti;
	if (pre > 0)
	{
		be_free = ft_ltoa_no_minus(ft_manti_to_a_e_2(&rt, manti, pre));
		rt = ft_strjoin_free(rt, be_free);
	}
	if (ft_array_round(set, rt, pre))
		ft_manti_to_a_e_3(set, &base, ft_strlen(base) - 2);
	rt = ft_strjoin_free(base, rt);
	return (rt);
}
