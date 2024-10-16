/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:30:35 by alaaouar          #+#    #+#             */
/*   Updated: 2024/10/16 10:36:40 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    get_args(t_philo *sceen, char **av)
{
    sceen->philos = ft_atoi(av[1]);
    sceen->rip_time = ft_atoi(av[2]);
    sceen->eat_time = ft_atoi(av[3]);
    sceen->zzz_time = ft_atoi(av[4]);
}
void	mutex_lunch(t_philo *sceen)
{
	int	i;

	i = 0;
	pthread_mutex_init(&sceen->free_shopsticks, NULL);
	while (i < sceen->philos)
    {
		pthread_mutex_init(&sceen->shopsticks[i], NULL);
        i++;
    }
}
void    everything_init(t_philo *sceen, int ac, char **av)
{    
    if (ac != 5)
        error("Invalid argument\n");
    get_args(sceen, av);
    sceen->philosophers = ft_calloc(sceen->philos, sizeof(t_philosopher));
    sceen->shopsticks = ft_calloc(sceen->philos, sizeof(pthread_mutex_t));
    if (!sceen->philosophers || !sceen->shopsticks)
        error("Failed to allocate memory for philosophers");
    sceen->start_time = starting_time();
    sceen->end = 0;
    sceen->all_ate = 0;
    mutex_lunch(sceen);
    
}


int main(int ac, char **av)
{
    t_philo sceen;    

    everything_init(&sceen, ac, av);
    if (starting_check(av, ac) != 0)
        error("ERROR at THE STARTING CHECK !!");
    mutex_lunch(&sceen);
    spawn_philos(&sceen);
    return 0;
}