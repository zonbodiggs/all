/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:06:22 by endoliam          #+#    #+#             */
/*   Updated: 2024/05/14 22:08:55 by endoliam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long long	get_time(t_philo *philo)
{
	struct timeval	t;

	if (gettimeofday(&t,NULL))
		exit_error("gettimeofday failure", philo);
	return((t.tv_sec) * 1000 + (t.tv_usec) / 1000);
}

void	message(char *msg, t_philo *philo)
{
	pthread_mutex_lock(&philo->print_mutex);
	if(!philo->die)
		printf("%lld %d %s\n",( get_time(philo) 
			- philo->u_time),philo->index, msg);
	pthread_mutex_unlock(&philo->print_mutex);
}
void	my_usleep(int sleep, t_philo *philo)
{
	long		start;

	start = get_time(philo);
	while ((get_time(philo) - start) < sleep)
		usleep(100);
}

int		is_all_dead(t_philo *philo)
{
	int		i;

	i = philo->size;
	while(i-- > 0)
	{
		if (philo->die == false)
			return (-1);
		if (philo->prev)
			philo = philo->prev;
	}
	return (0);
}

