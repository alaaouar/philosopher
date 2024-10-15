/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:35:22 by alaaouar          #+#    #+#             */
/*   Updated: 2024/10/14 19:53:07 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	starting_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return(time.tv_sec *1000 + time.tv_usec/1000);
}

long long current_time(t_philo *philo)
{
    long long time;

    time = starting_time() - philo->start_time;
    return (time);
}

void    philo_eating(t_philosopher *philo)
{
    ft_print_msg("is eating", philo);
    usleep(philo->sceen->eat_time * 1000);
    philo->last_meal = current_time(philo->sceen);
    philo->ate++;
    if (philo->ate == philo->sceen->times_must_eat)
        philo->sceen->all_ate++;
}
