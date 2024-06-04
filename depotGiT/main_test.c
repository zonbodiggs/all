/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:22:01 by sponthus          #+#    #+#             */
/*   Updated: 2024/01/15 13:37:33 by endoliam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	c = 'c';
	char	*str = "hello";
	char	*nptr = NULL;
	int		nbr = 54987856;
	int		negnbr = -124;
	int		zero = 0;
	int		value1;
	int		value2;

	value1 = printf("a simple \nstring");
	printf("\n");
	value2 = ft_printf("a simple \nstring");
	printf("\n true value = %d ft_ = %d \n\n", value1, value2);

	value1 = printf("test c = %c", c);
	printf("\n");
	value2 = ft_printf("test c = %c", c);
	printf("\n true value = %d ft_ = %d \n\n", value1, value2);

	value1 = printf("test str = %s / null = %s", str, nptr);
	printf("\n");
	value2 = ft_printf("test str = %s / null = %s", str, nptr);
	printf("\n true value = %d ft_ = %d \n\n", value1, value2);

	value1 = printf("test p = hello %p &hello %p NULL %p &54987856 %p", str, &str, nptr, &nbr);
	printf("\n");
	value2 = ft_printf("test p = hello %p &hello %p NULL %p &54987856 %p", str, &str, nptr, &nbr);
	printf("\n true value = %d ft_ = %d \n\n", value1, value2);

	value1 = printf("test d = %d %d %d %d", nbr, negnbr, zero, 2147483648);
	printf("\n");
	value2 = ft_printf("test d = %d %d %d %d", nbr, negnbr, zero, 2147483648);
	printf("\n true value = %d ft_ = %d \n\n", value1, value2);

	value1 = printf("test i = %i %i %i %i", nbr, negnbr, zero, 2147483648);
	printf("\n");
	value2 = ft_printf("test i = %i %i %i %i", nbr, negnbr, zero, 2147483648);
	printf("\n true value = %d ft_ = %d \n\n", value1, value2);

	value1 = printf("test u = %u %u %u %u", nbr, negnbr, zero, 2147483648);
	printf("\n");
	value2 = ft_printf("test u = %u %u %u %u", nbr, negnbr, zero, 2147483648);
	printf("\n true value = %d ft_ = %d \n\n", value1, value2);

	value1 = printf("test x = %x %x %x %x", nbr, negnbr, zero, 2147483648);
	printf("\n");
	value2 = ft_printf("test x = %x %x %x %x", nbr, negnbr, zero, 2147483648);
	printf("\n true value = %d ft_ = %d \n\n", value1, value2);

	value1 = printf("test X = %X %X %X %X", nbr, negnbr, zero, 2147483648);
	printf("\n");
	value2 = ft_printf("test X = %X %X %X %X", nbr, negnbr, zero, 2147483648);
	printf("\n true value = %d ft_ = %d \n\n", value1, value2);

	value1 = printf("test percent = %%");
	printf("\n");
	value2 = ft_printf("test percent = %%");
	printf("\n true value = %d ft_ = %d \n\n", value1, value2);

	value1 = printf("test percent end = %");
	printf("\n");
	value2 = ft_printf("test percent end = %");
	printf("\n true value = %d ft_ = %d \n\n", value1, value2);

	value1 = printf("");
	printf("\n");
	value2 = ft_printf("");
	printf("\n true value empty = %d ft_ = %d \n\n", value1, value2);

	value1 = printf(NULL);
	printf("\n");
	value2 = ft_printf(NULL);
	printf("\n true value empty = %d ft_ = %d \n\n", value1, value2);

	//value1 = printf("test all = %c%s %p %d%i %u %x /n%X%%", c, str, nptr, nbr, nbr, nbr, nbr, nbr);
	//printf("\n");
	//value2 = ft_printf("test all = %c%s %p %d%i %u %x /n%X%%", c, str, nptr, nbr, nbr, nbr, nbr, nbr);
	//printf("\n true value = %d ft_ = %d \n\n", value1, value2);
//
	//value1 = printf("false option = %y");
	//printf("\n");
	//value2 = ft_printf("false option = %y");
	//printf("\n true value empty = %d ft_ = %d \n\n", value1, value2);
}
