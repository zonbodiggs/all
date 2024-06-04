/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: endoliam <endoliam@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:46:31 by endoliam          #+#    #+#             */
/*   Updated: 2024/05/15 01:37:28 by endoliam         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "tools.h"
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <string.h>
/*   struct for philo */

typedef struct s_philo
{
	pthread_t			thread;			// thread philo
	pthread_mutex_t		*r_mutex;		// mutex for right fork
	pthread_mutex_t		l_mutex;		// mutex for left fork
	pthread_mutex_t		print_mutex;	// mutex for print
	pthread_mutex_t		die_mutex;		// mutex for die
	pthread_mutex_t		count_mutex;	// mutex for index eat
	int					index;			// index philo
	int					size;			// nb of philo
	int					i_eat;			// index eat
	int					u_eat;			// time eat
	int					u_sleep;		// time sleep
	int					u_die;			// time die
	long long			u_time;			// global time
	long long			u_start_sleep; 	// time for death
	bool				die;
	bool				r_fork;
	bool				l_fork;
	struct s_philo		*prev;
	struct s_philo		*next;
}	t_philo;

int 			main(int ac, char **av);

// init philo
void			create_philo(t_philo **philo, int size,  char **av);
t_philo			*create_stack(int index, char **av);
void			add_stack(t_philo **philo, t_philo *element);
void			create_mutex(t_philo *philo);
void			set_fork(t_philo *philo);

// utils
long long		get_time(t_philo *philo);
void			message(char *msg, t_philo *philo);
void			my_usleep(int sleep, t_philo *philo);
int				is_all_dead(t_philo *philo);

// exit
void			destroy_philo(t_philo *philo);
void			exit_error(char *msg, t_philo *philo);
void 			destroy_stack(t_philo *philo);

// thread
void			create_threads(t_philo *philo);
void			*routine(void  *philo);
void			join_thread(t_philo *philo);


#endif