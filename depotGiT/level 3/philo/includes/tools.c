/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:38:51 by endoliam          #+#    #+#             */
/*   Updated: 2024/05/09 19:13:35 by endoliam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

int	ft_atoi(char *av)
{
	long	i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return(-1);
		nbr *= 10;
		nbr += av[i] - '0';
		i++;
	}
	return (nbr);
}