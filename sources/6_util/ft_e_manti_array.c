/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_manti_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:22:41 by hyunja            #+#    #+#             */
/*   Updated: 2020/11/15 14:13:20 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_e_manti_array_2(t_set *set, char **rt, char **tmp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((*tmp)[i] != '0')
	{
		*rt[j] = *tmp[i];
		set->strs.str_to_print[0] = (*tmp)[i];
	}
	(*rt)[++i] = '.';
	while ((*tmp)[i])
	{
		if ((*tmp)[i] == '.')
			i++;
		(*rt)[j] = (*tmp)[i];
		i++;
		j++;
	}
}

char			*ft_e_manti_array(t_set *set, int pre)
{
	char	*rt;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(set->strs.str_to_print = malloc(sizeof(char) * 3)))
		return (0);
	set->strs.str_to_print[0] = '0';
	set->strs.str_to_print[1] = '.';
	set->strs.str_to_print[2] = 0;
	tmp = ft_dtoa(set, (set->f.d), pre + set->e_expond, set->lenths.width);
	if (!(rt = malloc(sizeof(char) * pre + 3)))
		return (0);
	rt[pre + 2] = 0;
	ft_memset_chr(rt, '0', pre + 1);
	ft_e_manti_array_2(set, &rt, &tmp);
	free(tmp);
	return (rt);
}
