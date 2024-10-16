/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:30:30 by alaaouar          #+#    #+#             */
/*   Updated: 2024/10/16 11:19:04 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	long	i;
	long	o;

	i = 0;
	o = 0;
	if (str[i] == '-')
	{
		error("Invalid argument\n");
	}
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		o *= 10;
		o += str[i] - 48;
		i++;
	}
	return (o);
}
