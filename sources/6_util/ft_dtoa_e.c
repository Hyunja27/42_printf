/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:22:41 by hyunja            #+#    #+#             */
/*   Updated: 2020/11/22 16:21:49 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_dtoa_e_4(char **rt, double db)
{
	char		*be_free;
	long long	i;

	i = ft_strlen(*rt) - 1;
	if (((int)(db * 10)) - (((int)db) * 10) >= 5)
		(*rt)[ft_strlen(*rt) - 2] += (*rt)[ft_strlen(*rt) - 2] % 2 == 0 ? 0 : 1;
	while (--i >= 0)
	{
		if ((*rt)[i] == 58)
		{
			(*rt)[i] = '0';
			if (i > 1)
				(*rt)[i - 1]++;
			else
			{
				(*rt)[0] = '0';
				be_free = ft_strjoin("1", *rt);
				free(*rt);
				*rt = be_free;
			}
		}
	}
	(*rt)[ft_strlen(*rt)] = '\0';
	(*rt)[ft_strlen(*rt) - 1] = '\0';
}

static void		ft_dtoa_e_3(t_set *set, double n, char **rt, int pre)
{
	char	*be_free;

	if (((*rt)[2] == '.') && ((*rt)[1] == '0'))
	{
		(*rt)[2] = 0;
		(*rt)[1] = '.';
		set->e_expond++;
	}
	if ((pre == 6) && (n == 0))
	{
		be_free = ft_strjoin(*rt, "000000");
		free(*rt);
		*rt = be_free;
	}
}

static double	ft_dtoa_e_2(double n, t_set *set, char **rt)
{
	char			*be_free;
	double			db;

	db = n;
	if (ft_ilencal((int)n) >= 2)
	{
		while ((ft_ilencal((int)db) > 1))
			db = n / ft_power(++set->e_expond);
		n = n / ft_power(set->e_expond);
	}
	else if (((int)n == 0))
	{
		while ((int)db == 0)
		{
			db *= (double)10;
			set->e_expond--;
		}
		n = n * ft_power(set->e_expond * -1);
	}
	db = n - (int)n;
	be_free = ft_ltoa_no_minus(n - db);
	*rt = ft_strjoin(be_free, ".\0");
	free(be_free);
	return (n);
}

char			*ft_dtoa_e(t_set *set, double n, int pre, int wid)
{
	char			*rt;
	double			db;

	db = 0;
	if (n == 0)
		rt = ft_zero_maker(set, pre, wid);
	else
	{
		n = ft_dtoa_e_2(n, set, &rt);
		ft_dtoa_e_3(set, n, &rt, pre);
		db = n - (int)n;
		rt = (pre >= 0) ? ft_manti_to_a_e(set, db, rt, pre) : rt;
		db = (n < 0) ? -n : n;
		if ((rt[ft_strlen(rt) - 1] == '.') && (set->flags.shap_flag != 1))
			ft_dtoa_e_4(&rt, db);
	}
	return (rt);
}
