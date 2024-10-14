/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:30:35 by alaaouar          #+#    #+#             */
/*   Updated: 2024/10/14 10:18:09 by alaaouar         ###   ########.fr       */
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
void display_philo_info(t_philo *philo) {
    if (!philo) {
        printf("Philosopher info is NULL\n");
        return;
    }
    printf("Philo Structure Information:\n");
    printf("Number of Philosophers: %d\n", philo->philos);
    printf("Time to RIP (ms): %d\n", philo->rip_time);
    printf("Time to Eat (ms): %d\n", philo->eat_time);
    printf("Time to Sleep (ms): %d\n", philo->zzz_time);     
    printf("Times Each Philosopher Must Eat: %d\n", philo->times_must_eat);
    printf("End Flag: %d\n", philo->end);
    printf("All Ate Flag: %d\n", philo->all_ate);
    printf("Start Time: %lld\n", philo->start_time);
    
    // Print shopsticks state (assuming you want to show the mutex addresses)
    printf("Shopsticks Mutex Addresses:\n");
    for (int i = 0; i < philo->philos; i++) {
        printf("Shopstick %d: %p\n", i, (void*)&philo->shopsticks[i]);
    }
    
    // Print the free shopstick mutex
    printf("Free Shopstick Mutex Address: %p\n", (void*)&philo->free_shopsticks);

    // Print philosophers' info
    printf("=====Philosophers Information:=====\n");
    for (int i = 0; i < philo->philos; i++) {
        t_philosopher *philosopher = &philo->philosophers[i];
        printf("  Philosopher ID: %d\n", philosopher->id);
        printf("  Times      Ate: %d\n", philosopher->ate);
        printf("  Should DieFlag: %d\n", philosopher->should_die);
        printf("  Last Meal Time: %lld\n", philosopher->last_meal);
        printf("  Thread ID     : %lu\n", philosopher->thread);
    }
}

int main(int ac, char **av)
{
    t_philo sceen;    

    everything_init(&sceen, ac, av);
    print_sceen(&sceen);
    if (starting_check(av, ac) != 0)
        error("ERROR at THE STARTING CHECK !!");
    sceen.philosophers = allocate_for_philo(&sceen);
    mutex_lunch(&sceen);
    
    display_philo_info(&sceen);
    return 0;
}