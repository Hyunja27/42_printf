/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:02:40 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/21 14:36:33 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_str
{
	const char	*str_to_pharse;
	char	*str_flaged;
	char	*str_body;
	char	*str_to_print;
}				t_str_set;

typedef struct	s_flag
{
	int			lefted;
	int			zeroflag;
	int			spaceflag;
	int			plus_flag;
	int			shap_flag;
}				t_flag_set;

typedef struct	s_lenth
{
	int			width;
	int			precision;
	int			total_len;
}				t_lenth_set;

typedef struct	s_set
{
	void		*val;
	char		type;
	long long	num;
	char		chr;
	char		*va_str;
	int			precision_yn;
	int			rt_byte;
	va_list		*list;
	t_str_set	strs;
	t_flag_set	flags;
	t_lenth_set lenths;
}				t_set;

int		ft_printf(const char *str, ...);
void	ft_width_detecter(t_set *set);
void	ft_precision_detecter(t_set *set);
void	ft_pharse_str(t_set *set);
void	ft_wid_pre_seperater(t_set *set);
void	ft_printf_with_set(t_set *set, va_list l);
void	ft_printf_int(t_set *set, va_list l);
void	ft_flag_setter(t_set *set);
void	ft_body_setter_int (t_set *set);
void	ft_body_setter_str(t_set *set);
void	ft_body_setter_hex(t_set *set);
void	ft_left_setter(t_set *set);
void	ft_printf_str(t_set *set, va_list l);
void	ft_printf_char(t_set *set, va_list l);
void	ft_printf_hex(t_set *set, va_list l);
void	ft_printf_ptr(t_set *set, va_list l);

void	ft_set_clear(t_set *set);

#endif
