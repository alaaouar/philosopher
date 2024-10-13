/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theards.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:54:37 by alaaouar          #+#    #+#             */
/*   Updated: 2024/10/13 18:46:38 by alaaouar         ###   ########.fr       */
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
            sleep(philos->sceen->rip_time);
            break;
        }
        grab_fork(philos, left_shopstick);
    }
    printf("Philosopher %d is thinking\n", philos->id);
    return (NULL);
}
void	grab_fork(t_philosopher *philo, int shop)
{
	pthread_mutex_lock(&philo->sceen->shopsticks[shop]);
	ft_print_msg("has taken a fork", philo->sceen);
}

t_philosopher   *allocate_for_philo(t_philo *sceen)
{
    t_philosopher   *philosophers;
    int i;

    philosophers = ft_calloc(sceen->philos, sizeof(t_philosopher));
    if (philosophers == NULL)
        error("Failed to allocate memory for philosophers");
    i = 0;
    while (i <= sceen->philos)
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

void    philo_eating(t_philo *philo)
{
    printf("Philosopher %d is eating\n", philo->philosophers->id);
    
}