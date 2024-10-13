/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   theards.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:54:37 by alaaouar          #+#    #+#             */
/*   Updated: 2024/10/12 19:03:47 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *philosopher_routine(void *arg)
{
    t_philosopher *philo;
    int right_shopstick;
    int left_shopstick;

    philo = (t_philosopher *)arg;
    while (!philo->sceen->end && !philo->should_die)
    {
        right_shopstick = philo->id;
        left_shopstick = (philo->id + 1) % philo->sceen->philos;
        grab_fork(philo, right_shopstick);
        if (philo->sceen->philos == 1)
        {
            sleep(philo->sceen->rip_time);
            break;
        }
        grab_fork(philo, left_shopstick);
        
    }
    
    printf("Philosopher %d is thinking\n", philo->id);
    return (NULL);
}

t_philosopher   *allocate_for_philo(t_philo sceen)
{
    t_philosopher   *philosophers;

    philosophers = ft_calloc(sceen.philos, sizeof(t_philosopher));
    if (philosophers == NULL)
        error("Failed to allocate memory for philosophers");
    return (philosophers);
}
void	grab_fork(t_philosopher *philo, int shop)
{
	pthread_mutex_lock(&philo->sceen->shopsticks[shop]);
	ft_print_msg(philo, "has taken a fork");
}

void    philo_eating(t_philo *philo)
{
    printf("Philosopher %d is eating\n", philo->id);
    
}