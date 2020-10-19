/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 04:20:30 by spark             #+#    #+#             */
/*   Updated: 2020/10/19 20:46:24 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char			str[10000] = "%10.13c";
	int		num1;
	int				num2;
	char			chr;
	int				rt_byte;
	//char			*str1 = "all extra error";

	num1 = 0;
	num2 = 30;
	chr = 'A';
	printf(" = test value is '%s' =\n\n            = va is '%c' =\n\n", str, chr);
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	printf("< Real printf >\n\n");
	rt_byte = printf(str, chr);
	printf("\n\n\n>real printf's return byte : %d\n", rt_byte);
	printf("\n\n");
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	printf("< My ft_printf >\n\n");
	ft_printf(str, chr);
	printf("\n\n");
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	return (0);
}
