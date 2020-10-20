/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 04:20:30 by spark             #+#    #+#             */
/*   Updated: 2020/10/21 00:08:11 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	//"%010s%c%-0+5dhello\n";
	//"%.15u%%%.*d ALL\n"
	char			str[10000] = "%0s%c%-0+5dhello\n";
	//char			*str1;
	//unsigned int	num1;
	//long long 			num2;
	char			chr;
	int				rt_byte;
	char			*str1 = "all extra error";
	//num1 = 2147483648;
	//num2 = 2147489999;
	chr = 'A';
	printf(" = test value is '%s' =\n\n          = va is '%%' =\n\n", str);
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	printf("< Real printf >\n\n");
	rt_byte = printf(str, str1, chr, 20000);
	printf("\n\n\n>real printf's return byte : %d\n", rt_byte);
	printf("\n\n");
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	printf("< My ft_printf >\n\n");
	ft_printf(str, str1, chr, 20000);
	printf("\n\n");
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");




	return (0);
}
