/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 04:20:30 by spark             #+#    #+#             */
/*   Updated: 2020/10/21 12:44:06 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	//"%010s%c%-0+5dhello\n";
	//"%.15u%%%.*d ALL\n"
	char			str[10000] = "%.20x";
	//char			*str1;
	//unsigned int	num1;
	//long long 	num2;
	//char			chr;
	int				rt_byte;
	int	a;
	//num1 = 2147483648;
	//num2 = 2147489999;
	//chr = 'A';

	a = 9988786;
	printf(" = test value is '%s' =\n\n          = va is '%%n' =\n\n", str);
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	printf("< Real printf >\n\n");
	rt_byte = printf(str, a);
	//printf("\n>>> %d", a);
	printf("\n\n\n>real printf's return byte : %d\n", rt_byte);
	printf("\n\n");
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	printf("< My ft_printf >\n\n");
	ft_printf(str, a);
	printf("\n\n");
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");



	return (0);
}
