/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:46:19 by endoliam          #+#    #+#             */
/*   Updated: 2024/05/14 21:32:14 by endoliam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_philo		*philo;
	int			size;

	if (ac != 5 && ac != 6)
		exit_error("wrong args", NULL);
	size = ft_atoi(av[1]);
	if (size <= 0)
		exit_error("atoi failed", NULL); // change message
	philo = NULL;
	create_philo(&philo,size, av); // creating list of philos and pars args
	if (philo->u_eat < 0 || philo->u_die < 0
		|| philo->i_eat < 0 || philo->u_sleep < 0)
		exit_error("atoi failed", philo);
	create_threads(philo); // init threads 
	// test routine with thread
	destroy_philo(philo);
	exit (1);
}
