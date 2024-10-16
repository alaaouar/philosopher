/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theards.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:54:37 by alaaouar          #+#    #+#             */
/*   Updated: 2024/10/16 10:46:11 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *philosopher_routine(void *arg)
{
    t_philosopher *philos;
    int right_shopstick;
    int left_shopstick;

    philos = (t_philosopher *)arg;
    while (!philos->sceen->end && !philos->should_die)
    {
        right_shopstick = philos->id;
        left_shopstick = (philos->id + 1) % philos->sceen->philos;
        grab_fork(philos, right_shopstick);
        if (philos->sceen->philos == 1)
        {
            usleep(philos->sceen->rip_time);
            break;
        }
        grab_fork(philos, left_shopstick);
        philo_eating(philos);
        pthread_mutex_unlock(&philos->sceen->shopsticks[right_shopstick]);
        pthread_mutex_unlock(&philos->sceen->shopsticks[left_shopstick]);
        sleep_and_think(philos);
    }
    return (NULL);
}

void    sleep_and_think(t_philosopher *philo)
{
    ft_print_msg("is sleeping", philo);
    usleep(philo->sceen->zzz_time);
    ft_print_msg("is thinking", philo);
}

void	grab_fork(t_philosopher *philo, int shop)
{
	pthread_mutex_lock(&philo->sceen->shopsticks[shop]);
	ft_print_msg("has taken a fork", philo);
}

t_philosopher   *allocate_for_philo(t_philo *sceen)
{
    t_philosopher   *philosophers;
    int i;

    philosophers = ft_calloc(sceen->philos, sizeof(t_philosopher));
    if (philosophers == NULL)
        error("Failed to allocate memory for philosophers");
    i = 0;
    while (i < sceen->philos)
    {
        philosophers[i].id = i;
        philosophers[i].ate = 0;
        philosophers[i].should_die = 0;
        philosophers[i].last_meal = 0;
        philosophers[i].sceen = sceen;
        i++;
    }
    return (philosophers);
}

void    death_clock(t_philo *sceen)
{
    pthread_t   *observer;

    while (sceen->end == 0)
    {
        observer = ft_calloc(1, sizeof(pthread_t));
        if (observer == NULL)
            error("Failed to allocate memory for reaper");
        pthread_create(observer, NULL, reaper, sceen);
        pthread_detach(*observer);
        usleep(100);
    }
}

void spawn_philos(t_philo *sceen)
{
    t_philosopher *philosophers;
    pthread_t observer;
    int i = 0;

    philosophers = allocate_for_philo(sceen);
    if (philosophers == NULL)
        return;
    while (i < sceen->philos)
    {
        if (pthread_create(&philosophers[i].thread, NULL, philosopher_routine, &philosophers[i]) != 0)
        {
            perror("Failed to create thread");
            free(philosophers);
            return;
        }
        i++;
    }
    i = 0;
    while (i <sceen->philos)
    {
        pthread_create(&observer, NULL, reaper, &philosophers[i]);
        pthread_detach(observer);
        i++;
    }
    i = 0;
    while (i < sceen->philos)
    {
        pthread_join(philosophers[i].thread, NULL);
        i++;
    }
    free(philosophers);
}
