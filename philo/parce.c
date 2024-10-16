/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:33:30 by alaaouar          #+#    #+#             */
/*   Updated: 2024/10/16 10:36:46 by alaaouar         ###   ########.fr       */
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


