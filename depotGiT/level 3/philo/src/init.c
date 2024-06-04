/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:10:59 by endoliam          #+#    #+#             */
/*   Updated: 2024/05/16 11:32:44 by endoliam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	create_philo(t_philo **philo, int size,  char **av)
{
	int			i;
	t_philo		*data;
	t_philo		*start;

	i = 1;
	data = *philo;
	start = NULL;
	while (i <= size)
	{
		data = create_stack(i, av);
		add_stack(philo, data);
		data->size = size;
		if (i == 1)
			start = data;
		create_mutex(*philo);
		i++;
	}
	data->next = start;
	start->prev = data;
	start->r_fork = true;
	start->l_fork = true;
	*philo = start;
	set_fork(start);// don't need to set fork
}

t_philo		*create_stack(int index, char **av)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
			exit_error("philo malloc allocation failed", NULL);
	memset(philo, 0, sizeof(t_philo));
	philo->index = index;
	philo->u_eat = ft_atoi(av[3]);
	if (av[5])
		philo->i_eat = ft_atoi(av[5]);
	philo->u_sleep = ft_atoi(av[4]);
	philo->u_die = ft_atoi(av[2]);
	philo->u_time = get_time(philo);
	philo->u_start_sleep = get_time(philo);
	return(philo);
}

void	create_mutex(t_philo *philo)
{

	if (pthread_mutex_init(&philo->die_mutex, NULL) != 0 
		|| pthread_mutex_init(&philo->print_mutex, NULL) != 0
		|| pthread_mutex_init(&philo->l_mutex, NULL) != 0
		|| pthread_mutex_init(&philo->count_mutex, NULL) != 0)
	{
		philo->size = philo->index;
		exit_error("mutex allocation failed", philo);
	}
}

void	add_stack(t_philo **philo, t_philo *element)
{
	if (!*philo)
	{
		*philo = element;
		element->prev = NULL;	
	}
	else
	{
		while((*philo)->next)
			*philo = (*philo)->next;
		(*philo)->next = element;
		element->prev = *philo;
		(*philo) = (*philo)->next;
	}
}

void		set_fork(t_philo *philo)
{
	int		i;

	i = philo->size;
	while(i-- > 0)
	{
		if (philo->prev->r_fork == false && philo->next->r_fork == false)
			philo->r_fork = true;
		if (philo->prev-> l_fork == false)
			philo->l_fork = true;
		philo->r_mutex = &philo->next->l_mutex;
		philo = philo->next;
	}
	philo = philo->next;
}
