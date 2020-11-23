/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_e_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:22:41 by hyunja            #+#    #+#             */
/*   Updated: 2020/11/22 15:42:45 by spark            ###   ########.fr       */
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
	(*rt)[ft_strlen(*rt) - 1] = '\0';
}

static void		ft_dtoa_e_3(t_set *set, double n, char **rt, int pre)
{
	char	*be_free;

	set->e_expond++;
	set->e_expond--;
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

static void		ft_dtoa_e_2_2(double n, t_set *set, char **rt, double *db)
{
	char			*be_free;
	char			*tmp;
	int				i;

	i = 0;
	be_free = 0;
	if (ft_ilencal((int)n) >= 2)
	{
		while ((ft_ilencal((int)*db) > 1))
			*db = n / ft_power(++set->e_expond);
		be_free = ft_ltoa_no_minus((long long)n);
		if (!(tmp = calloc(ft_strlen(be_free) + 2, sizeof(char))))
			return ;
		tmp[ft_strlen(tmp) - 1] = 0;
		tmp[0] = be_free[0];
		tmp[1] = '.';
		while (be_free[++i])
			tmp[i + 1] = be_free[i];
		*rt = tmp;
	}
}

static double	ft_dtoa_e_2(double n, t_set *set, char **rt)
{
	char			*be_free;
	double			db;

	db = n;
	be_free = 0;
	if (ft_ilencal((int)n) >= 2)
	{
		ft_dtoa_e_2_2(n, set, rt, &db);
		return (n);
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
	*rt = ft_strjoin(be_free, ".");
	free(be_free);
	return (n);
}

char			*ft_dtoa_e_big(t_set *set, double n, int pre, int wid)
{
	char			*rt;
	char			*body;
	char			*be_free;
	double			db;

	db = 0;
	if (n == 0)
		rt = ft_zero_maker(set, pre, wid);
	else
	{
		n = ft_dtoa_e_2(n, set, &rt);
		ft_dtoa_e_3(set, n, &rt, pre);
		db = n - (int)n;
		body = ft_bigint(set);
		body += (set->e_expond < 0) ? (set->e_expond * -1) : 0;
		be_free = rt;
		rt = ft_strjoin(rt, body);
		if (set->e_expond < 0)
			body -= (set->e_expond * -1);
		ft_free_va(2, body, be_free);
		db = (n < 0) ? -n : n;
		if ((rt[ft_strlen(rt) - 1] == '.') && (set->flags.shap_flag != 1))
			ft_dtoa_e_4(&rt, db);
	}
	return (rt);
}
