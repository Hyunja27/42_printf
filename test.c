/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 04:20:30 by spark             #+#    #+#             */
/*   Updated: 2020/11/23 17:00:37 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

int	main(void)
{
	setlocale(LC_ALL, "");
	//"%010s%c%-0+5dhello\n";
	//"%.15u%%%.*d ALL\n"
	
	//char			*str1 ="bombastic";
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
	a = 0;
	// int		b = 0;
	// char	c = 'a';
	// int		d = 2147483647;
	// int		e = -2147483648;
	// int		f = 42;
	// int		g = 25;
	// int		h = 4200;
	// int		i = 8;
	// int		j = -12;
	// int		k = 123456789;
	// int		l = 0;
	// int		m = -12345678;
	// char	*n = "abcdefghijklmnop";
	// char	*o = "-a";
	// char	*p = "-12";
	// char	*q = "0";
	// char	*r = "%%";
	// char	*s = "-2147483648";
	// char	*t = "0x12345678";
	// char	*u = "-0";
	// const char		*str = "%0*.*i,%0*.*i,%0*.*i";

	//printf(" = test value is '%s' =\n\n          = va is '%%n' =\n\n", str);
	
	
	// printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	
	printf("< Real printf >\n\n");
	//rt_byte = printf("%-*.*s/", -7, -3, "yolo");
	rt_byte = printf("%#37llX", 522337203685470ull);
	printf("\n\n\n>real printf's return byte : %d\n", rt_byte);
	printf("\n\n");

	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");

	printf("< My ft_printf >\n\n");
	//rt_byte = ft_printf("%-*.*s/", -7, -3, "yolo");
	//rt_byte = ft_printf(str, -2, -2, 0, -2, -2, 0, -2, -2, 0);
	rt_byte = ft_printf("%#37llX", 522337203685470ull);

	

	
	//ft_printf("\n\n%.30f", 26);
	printf("\n\n\n>my printf's return byte : %d\n", rt_byte);

	
	// ft_printf("% 8.5d", 45355);
	// ft_printf("% 224ld", 45355);
	// ft_printf("%3.54i", 45355);
	printf("\n\n");

	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");

	// while (1)
	// {
	// 	;
	// }
	return (0);
}

	// printf("%+5d", 35);
	// ft_printf("%c/", '\0');

	// printf("\n\n>precision yn: %d\n", set.precision_yn);
	// printf(">zero flags : %d\n", set.flags.zeroflag);
	// printf(">space flags : %d\n", set.flags.spaceflag);
	// printf(">sha5p flags : %d\n", set.flags.shap_flag);
	// printf(">lefted : %d\n", set.flags.lefted);
	// printf(">precision: %d\n", set.lenths.precision);
	// printf(">width : %d\n", set.lenths.width);
	// printf(">type is : %c\n", set.type);
	// printf(">return byte : %d\n", set.rt_byte);
	// printf(">int that print is : %s\n", set.va_str);
	// printf(">body str is : %s\n", set.strs.str_body);

		// printf("\n\n<flaged s :%s>\n",set->strs.str_flaged);
		// printf("\n\n<body s :%s>\n",set->strs.str_body);
		// printf("\n\n<padding :%d>\n",padding);
		// printf("\n\n<sm_padding :%d>\n",sm_padding);



		// if ((set->type == 'e') || (set->type == 'E'))
		// {
		// 	if (ft_strlen(base) > 2)
		// 	{
		// 		base[2] = 0;
		// 		base[1] = '.';
		// 		be_free = ft_strjoin("0", rt);
		// 		rt = ft_strdup(be_free);
		// 		free(be_free);
		// 	}
		// }

		// printf("\n\n\n\n ==========> %f\n\n\n\n", db);
		// -g3 -fsanitize=address