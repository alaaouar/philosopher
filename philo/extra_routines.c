/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:42:13 by alaaouar          #+#    #+#             */
/*   Updated: 2024/10/16 12:37:57 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *reaper(void *arg)
{
    t_philosopher *stone;

    stone = (t_philosopher *)arg;
    while (stone->sceen->end != 1)
    {
        if ((stone->last_meal + stone->sceen->rip_time) < starting_time())
        {
            ft_print_msg("      DIED", stone);
            stone->should_die = 1;
            stone->sceen->end = 1;
        }
        usleep(100);
    }
    return(NULL);
}

void    *philos_hunger(void *arg)
{
    t_philo *sceen;

    sceen = (t_philo *)arg;
    while (sceen->end == 0)
    {
        if(sceen->all_ate == sceen->philos)
            sceen->end = 1;
    }
    return (NULL);
}

void	ft_join_free(t_philo *sceen)
{
    int	i;

    i = 0;
    while (i < sceen->philos)
        pthread_join(sceen->philosophers[i++].thread, NULL);
    free(sceen->philosophers);
    i = 0;
    while (i < sceen->philos)
        pthread_mutex_destroy(&sceen->shopsticks[i++]);
    pthread_mutex_destroy(&sceen->free_shopsticks);
    free(sceen->shopsticks);
    free(sceen);
}