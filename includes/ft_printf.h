/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:02:40 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/17 18:01:38 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct	t_set
{
	void	*val;
	char	type;
	int		precision_yn;
	int		double_num;
	int		lefted;
	int		zeroflag;
	int		spaceflag;
	int		width;
	int		precision;
	int		plus_flag;
}				s_set;

int		ft_printf(const char *str, ...);
const char	*ft_width_detecter(const char *str, s_set *set);
const char	*ft_precision_detecter(const char *str, s_set *set);
const char	*ft_pharse_str(const char *str, s_set	*set);
const char	*ft_wid_pre_seperater(const char *str, s_set *set);
void	ft_printf_with_set(s_set *set, va_list l);
void	ft_printf_int(s_set *set, va_list l);
void	ft_set_clear(s_set *set);

#endif
