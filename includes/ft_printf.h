/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:02:40 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/16 18:24:05 by spark            ###   ########.fr       */
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
	int		char_num;
	int		double_num;
	int		lefted;
	int		flag;
	int		width;
	double	precision;
}				Set;

int		ft_printf(const char *str, ...);
void	ft_print_int(int n);
size_t	ft_width_detecter(const char *str, Set *set);

#endif
