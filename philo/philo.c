/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:30:35 by alaaouar          #+#    #+#             */
/*   Updated: 2024/10/11 15:33:22 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_philo sceen;
    
    if (starting_check(av, ac) != 0)
        error("ERROR at THE STARTING CHECK !!");
    data_init(&sceen, av);
    print_sceen(&sceen);
    
    return 0;
}
