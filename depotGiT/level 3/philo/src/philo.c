/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:46:16 by endoliam          #+#    #+#             */
/*   Updated: 2024/05/16 11:33:23 by endoliam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void		death_philo(t_philo *philo)
{
	int		i;

	i = philo->size;
	pthread_mutex_lock(&philo->die_mutex);
	if (get_time(philo) - philo->u_start_sleep > philo->u_die)
	{
		while(i-- > 0)
		{
			philo->die = true;
			philo = philo->next;
		}
		pthread_mutex_lock(&philo->print_mutex);
		printf("%lld philo %d died\ntime death %lld\n",(get_time(philo) 
			- philo->u_time),philo->index, get_time(philo) - philo->u_start_sleep );
		pthread_mutex_unlock(&philo->print_mutex);
	}
	pthread_mutex_unlock(&philo->die_mutex);
	return ;
}
static void		eat(t_philo *philo)
{
	while(philo->l_fork == false)
		;
	if (philo->l_fork == true)
		message("has taken a fork", philo);
	while(philo->r_fork == false)
		;
	if (philo->l_fork == true && philo->r_fork == true)
	{	
		message("has taken a fork", philo);
		message("is eating", philo);
		my_usleep(philo->u_eat, philo);
		pthread_mutex_lock(&philo->l_mutex);
		philo->r_fork = false;
		philo->l_fork = false;
		pthread_mutex_unlock(&philo->l_mutex);
		pthread_mutex_lock(&philo->die_mutex);
		philo->u_start_sleep = get_time(philo);
		pthread_mutex_unlock(&philo->die_mutex);
	}
}

void	*routine(void  *p)
{
	t_philo 		*philo;

	philo = (t_philo *)p;
	while(is_all_dead(philo) != 0 && philo->i_eat > 0)
	{
		death_philo(philo);
		eat(philo);
		pthread_mutex_lock(&philo->count_mutex);
		philo->i_eat--;
		pthread_mutex_unlock(&philo->count_mutex);
		pthread_mutex_lock(&philo->l_mutex);
		message("is sleeping", philo);
		pthread_mutex_unlock(&philo->l_mutex);
		pthread_mutex_lock(philo->r_mutex);
		if (philo->l_fork == false)		// don't set prev fork but can watch prev fork
			philo->prev->r_fork = true;
		philo->next->l_fork = true;
		pthread_mutex_unlock(philo->r_mutex);
		my_usleep(philo->u_sleep, philo);
		message("is thinking", philo);
	}
	return(0);
}
void	create_threads(t_philo *philo)
{
	int		i;

	i = philo->size;
	while(i-- > 0)
	{
		if (pthread_create(&philo->thread, NULL ,&routine, philo) != 0)
			exit_error("thread allocation failed", philo);
		usleep(100);
		philo = philo->next;
	}
}
