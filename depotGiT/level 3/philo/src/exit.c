/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:01:25 by endoliam          #+#    #+#             */
/*   Updated: 2024/05/14 22:04:48 by endoliam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	exit_error(char *msg, t_philo *philo)
{
	if (philo)
		destroy_philo(philo);
	printf("error : %s\n", msg);
	exit(EXIT_FAILURE);
}

void 	destroy_philo(t_philo *philo)
{
	t_philo		*p;
	int			i;
	i = philo->size; 
	while (i-- > 0) 
	{
		p = philo;
		if (!p)
			break;
		destroy_stack(p);
		if (philo->prev)
			philo = philo->prev;
		free(p);
	}
}

void 	destroy_stack(t_philo *philo)
{
	void	*p;

	if (&philo->l_mutex)
		pthread_mutex_destroy(&philo->l_mutex); // leak while mutex failed
	if (&philo->print_mutex)
		pthread_mutex_destroy(&philo->print_mutex); // leak while mutex failed
	if (&philo->die_mutex)
		pthread_mutex_destroy(&philo->die_mutex);
	if (philo->thread)
	{
		if(pthread_join(philo->thread, &p) != 0)
			exit(40);
	}
}
