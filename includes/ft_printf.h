/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:02:40 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/17 10:07:00 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct	set
{
	void	*val;
	int		int_num;
	int		precision_yn;
	int		double_num;
	int		lefted;
	int		zeroflag;
	int		spaceflag;
	int		width;
	int		precision;
}				Set;

int		ft_printf(const char *str, ...);
void	ft_print_int(int n);
const char	*ft_width_detecter(const char *str, Set *set);
const char	*ft_precision_detecter(const char *str, Set *set);
void	ft_pharse_str(const char *str, Set	*set);
const char	*ft_wid_pre_seperater(const char *str, Set *set);

#endif
