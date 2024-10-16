/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:30:44 by alaaouar          #+#    #+#             */
/*   Updated: 2024/10/16 11:32:31 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_philosopher t_philosopher;


typedef struct s_philo
{
    int philos;
    int rip_time;
    int eat_time;
    int zzz_time;
    int times_must_eat;
    int end;
    int all_ate;
    long long start_time;
    pthread_mutex_t *shopsticks;
    pthread_mutex_t free_shopsticks;
    t_philosopher *philosophers;
}               t_philo;

typedef struct s_philosopher
{
	int			id;
	int			ate;
	int			should_die;
	long long	last_meal;
	pthread_t	thread;
    t_philo     *sceen;
}               t_philosopher;

void            *philosopher_routine(void *arg);
void	        grab_fork(t_philosopher *philo, int f);
void	        mutex_lunch(t_philo *sceen);
t_philosopher   *allocate_for_philo(t_philo *sceen);
long long       current_time(t_philo *philo);
long long	    starting_time(void);
void            *reaper(void *arg);
void            *philos_hunger(void *arg);
void            spawn_philos(t_philo *sceen);
        
void     error(const char *message);
int     starting_check(char **av, int ac);
int     ft_atoi(char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_print_msg(char *message,t_philosopher *sceen);
void    philo_eating(t_philosopher *philo);
void    sleep_and_think(t_philosopher *philo);
void    death_clock(t_philo *sceen);
void	ft_join_free(t_philo *sceen);
void    get_args(t_philo *sceen, char **av);
void    everything_init(t_philo *sceen, int ac, char **av);
int     ft_strlen(char *str);



#endif