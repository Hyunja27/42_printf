/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:02:40 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/18 17:41:24 by spark            ###   ########.fr       */
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
	int		num;
	int		precision_yn;
	int		double_num;
	int		lefted;
	int		zeroflag;
	int		spaceflag;
	int		width;
	int		precision;
	int		plus_flag;
}				t_set;

int		ft_printf(const char *str, ...);
const char	*ft_width_detecter(const char *str, t_set *set);
const char	*ft_precision_detecter(const char *str, t_set *set);
const char	*ft_pharse_str(const char *str, t_set	*set);
const char	*ft_wid_pre_seperater(const char *str, t_set *set);
int		ft_printf_with_set(t_set *set, va_list l);
int		ft_printf_int(t_set *set, va_list l);
void	ft_flag_setter(char *rt, t_set *set, int total_len);
char	*ft_body_setter(char *flaged, t_set *set, int total_len);
char	*ft_left_setter(char *flaged, char *body, t_set *set);

void	ft_set_clear(t_set *set);

#endif
