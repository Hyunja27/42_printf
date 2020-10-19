/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 04:20:30 by spark             #+#    #+#             */
/*   Updated: 2020/10/19 17:41:04 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char			str[10000] = "%+d";
	long long		num1;
	int				num2;
	int				num3;
	int				rt_byte;

	num1 = 2147483648;
	num2 = 30;
	num3 = 0;
	//printf(" = test value is '%s' =\n\n            = va is '%d' =\n\n", str, num2);
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	printf("< Real printf >\n\n");
	rt_byte = printf(str, -100);
	printf("\n\n\n>real printf's return byte : %d\n", rt_byte);
	printf("\n\n");
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	printf("< My ft_printf >\n\n");
	ft_printf(str, -100);
	printf("\n\n");
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	return (0);
}
