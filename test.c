/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 04:20:30 by spark             #+#    #+#             */
/*   Updated: 2020/10/22 15:16:06 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	//"%010s%c%-0+5dhello\n";
	//"%.15u%%%.*d ALL\n"
	
	//char			*str1;
	//unsigned int	num1;
	//long long 	num2;
	//char			chr;
	//num1 = 2147483648;
	//num2 = 2147489999;
	//chr = 'A';

	// printf("\n\n<tmp_body : %s>\n\n",tmp_body);
	// printf("\n\n<body : %s>\n\n",set->strs.str_body);
	// printf("\n\n<flaged :%s>\n\n",set->strs.str_flaged);
	
	int				rt_byte;
	int				a;
	const char		*str = "%07d";

	printf(" = test value is '%s' =\n\n          = va is '%%n' =\n\n", str);
	
	
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	
	a = -54;
	printf("< Real printf >\n\n");
	rt_byte = printf(str, a);
	printf("\n\n\n>real printf's return byte : %d\n", rt_byte);
	printf("\n\n");

	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");

	
	printf("< My ft_printf >\n\n");
	ft_printf(str, a);
	printf("\n\n");

	
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");

	return (0);
}


	// printf("\n\n>precision yn: %d\n", set.precision_yn);
	// printf(">zero flags : %d\n", set.flags.zeroflag);
	// printf(">space flags : %d\n", set.flags.spaceflag);
	// printf(">shap flags : %d\n", set.flags.shap_flag);
	// printf(">lefted : %d\n", set.flags.lefted);
	// printf(">precision: %d\n", set.lenths.precision);
	// printf(">width : %d\n", set.lenths.width);
	// printf(">type is : %c\n", set.type);
	// printf(">return byte : %d\n", set.rt_byte);
	// printf(">int that print is : %s\n", set.va_str);
	// printf(">body str is : %s\n", set.strs.str_body);