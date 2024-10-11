/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:33:30 by alaaouar          #+#    #+#             */
/*   Updated: 2024/10/11 15:33:47 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void error(const char *message)
{
    const char *line = message;
    int i = 0;

    while (line[i] != '\0')
    {
        write(1, &line[i] , 1);
        usleep(55555);
        i++;
    }
    exit(1);
}

void print_sceen(t_philo *sceen)
{
    printf("Philosophers: %d\n", sceen->philos);
    printf("Rip Time: %d\n", sceen->rip_time);
    printf("Eat Time: %d\n", sceen->eat_time);
    printf("Sleep Time: %d\n", sceen->zzz_time);
}

int starting_check(char **av, int ac)
{
    int i;
    int j;

    i = 1;
    if (ac != 5)
    {
        printf("Invalid argument\n");
        return 1;
    }
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (av[i][j] < '0' || av[i][j] > '9')
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}

void data_init(t_philo *sceen, char **av)
{
    sceen->philos = atoi(av[1]);
    sceen->rip_time = atoi(av[2]);
    sceen->eat_time = atoi(av[3]);
    sceen->zzz_time = atoi(av[4]);
}
