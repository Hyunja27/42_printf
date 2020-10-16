/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 04:20:30 by spark             #+#    #+#             */
/*   Updated: 2020/10/16 23:11:47 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char str[10000] = "% 50.20d[END]";

	printf(" - test value is      %s\n\n", str);
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	printf("< Real printf >\n\n");
	printf(str, 39);
	printf("\n\n");
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	printf("< My ft_printf >\n\n");
	ft_printf(str, 39);
	printf("\n\n");
	printf("= = = = = = = = = = = = = = = = = = = = = = = = = =\n");
	return (0);
}
