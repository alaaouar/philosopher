/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:30:44 by alaaouar          #+#    #+#             */
/*   Updated: 2024/10/11 15:34:22 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

typedef struct s_philosopher
{
    int             id;
    pthread_t       thread;
}               t_philosopher;

typedef struct s_philo
{
    int philos;
    int rip_time;
    int eat_time;
    int zzz_time;
}               t_philo;


// void    *philosopher_routine(void *arg);


        /*      parcing       */
void    error(const char *message);
int     starting_check(char **av, int ac);
int     ft_atoi(char *str);
void    data_init(t_philo *sceen, char **av);
void print_sceen(t_philo *sceen);
        /**********************/
#endif