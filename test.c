/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 04:20:30 by spark             #+#    #+#             */
/*   Updated: 2020/10/20 22:53:22 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	//"%010s%c%-0+5dhello\n";
	//"%.15u%%%.*d ALL\n"
	char			str[10000] = "%*.*X";
	//char			*str1;
	//unsigned int	num1;
	//long long 			num2;
	//char			chr;
	int				rt_byte;
	//char			*str1 = "all extra error";
	//num1 = 2147483648;
	//num2 = 2147489999;
	//chr = 'A';
	printf(" = test value is '%s' =\n\n          = va is '%%' =\n\n", str);
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	printf("< Real printf >\n\n");
	rt_byte = printf(str, 10, 8, 20000);
	printf("\n\n\n>real printf's return byte : %d\n", rt_byte);
	printf("\n\n");
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	printf("< My ft_printf >\n\n");
	ft_printf(str, 10, 8, 20000);
	printf("\n\n");
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");




	return (0);
}
