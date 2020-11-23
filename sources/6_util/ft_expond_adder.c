/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expond_adder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 17:15:56 by spark             #+#    #+#             */
/*   Updated: 2020/11/20 01:04:45 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_expond_adder_3(t_set *set, char **be_free1, char **be_free2)
{
	int		i;

	i = 0;
	if (set->e_expond != 0)
		*be_free1 = ft_itoa_no_minus(set->e_expond);
	else
		*be_free1 = ft_strdup("0");
	if (ft_strlen(*be_free1) == 1)
	{
		*be_free2 = ft_strjoin("0", *be_free1);
		free(*be_free1);
		*be_free1 = ft_strjoin("e-", *be_free2);
		free(*be_free2);
	}
	else
	{
		*be_free2 = ft_strjoin("e-", *be_free1);
		free(*be_free1);
		*be_free1 = ft_strdup(*be_free2);
		free(*be_free2);
	}
}

void			ft_expond_adder_2(t_set *set, char **be_free1, char **be_free2)
{
	int		i;

	i = 0;
	if (set->e_expond != 0)
		*be_free1 = ft_ltoa_no_minus(set->e_expond);
	else
		*be_free1 = ft_strdup("0");
	if (ft_strlen(*be_free1) == 1)
	{
		*be_free2 = ft_strjoin("0", *be_free1);
		free(*be_free1);
		*be_free1 = ft_strjoin("e+", *be_free2);
		free(*be_free2);
	}
	else
	{
		*be_free2 = ft_strjoin("e+", *be_free1);
		free(*be_free1);
		*be_free1 = ft_strdup(*be_free2);
		free(*be_free2);
	}
}

void			ft_expond_adder(t_set *set)
{
	char	*be_free1;
	char	*be_free2;
	int		i;

	i = 0;
	be_free1 = 0;
	be_free2 = 0;
	if (set->e_expond == 0)
		be_free1 = ft_strdup("e+00");
	else if (set->e_expond > 0)
		ft_expond_adder_2(set, &be_free1, &be_free2);
	else if (set->e_expond < 0)
		ft_expond_adder_3(set, &be_free1, &be_free2);
	set->strs.str_body = ft_strjoin_free(set->strs.str_body, be_free1);
	if (set->type == 'E')
	{
		while (set->strs.str_body[i])
		{
			set->strs.str_body[i] = ft_toupper(set->strs.str_body[i]);
			i++;
		}
	}
}
