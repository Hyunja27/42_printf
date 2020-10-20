/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 06:08:16 by spark             #+#    #+#             */
/*   Updated: 2020/10/20 21:00:10 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbr_divide(long long nbr, int base_len)
{
	int cnt;

	if (!nbr)
		return (1);
	cnt = 0;
	if (nbr < 0)
		++cnt;
	while (nbr)
	{
		nbr = nbr / base_len;
		++cnt;
	}
	return (cnt);
}

static int		str_check(char *str, int *len)
{
	int		idx;
	int		checker[256];
	char	c;

	if (!*str)
		return (0);
	idx = 0;
	while (idx < 256)
		checker[idx++] = 0;
	*len = 0;
	while (str[*len])
	{
		c = str[*len];
		if (checker[(int)c] || c == '+' || c == '-' || is_space(c))
			return (0);
		checker[(int)c] = 1;
		++*len;
	}
	if (*len <= 1)
		return (0);
	return (1);
}

static int		atoi_base_from(char *str, char *base, int base_len)
{
	int ret;
	int indic;
	int idx;

	ret = 0;
	indic = 1;
	while (is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
		if (*(str++) == '-')
			indic = indic * -1;
	while (*str)
	{
		idx = -1;
		while (++idx < base_len)
		{
			if (*str == base[idx])
				break ;
		}
		if (idx == base_len)
			break ;
		ret = ret * base_len + (idx * indic);
		++str;
	}
	return (ret);
}

static char		*convert_to(int nbr, char *base, int base_len)
{
	long long	tmp;
	char		*ret;
	int			size;

	if (nbr == 0)
	{
		ret = (char*)malloc(2);
		ret[0] = base[0];
		ret[1] = 0;
		return (ret);
	}
	tmp = nbr;
	size = nbr_divide(tmp, base_len);
	if (!(ret = (char*)malloc(size + 1)))
		return (0);
	ret[size] = 0;
	tmp = (tmp < 0) ? (tmp * -1) : tmp;
	while (tmp)
	{
		ret[--size] = base[tmp % base_len];
		tmp = tmp / base_len;
	}
	if (nbr < 0)
		ret[0] = '-';
	return (ret);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		tmp;
	int		from_len;
	int		to_len;
	char	*ret;

	if (!(str_check(base_from, &from_len)) || !(str_check(base_to, &to_len)))
		return (0);
	tmp = atoi_base_from(nbr, base_from, from_len);
	ret = convert_to(tmp, base_to, to_len);
	return (ret);
}
