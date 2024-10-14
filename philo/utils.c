/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:43:34 by alaaouar          #+#    #+#             */
/*   Updated: 2024/10/14 09:35:27 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*((unsigned char *)(s + n)) = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(size * count);
	if (!res)
		return (0);
	ft_bzero(res, size * count);
	return (res);
}

int ft_strlen(char *str)
{
    int i = 0;

    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}
void	ft_print_msg(char *message,t_philo *sceen)
{
	int i;

	i = 0;
	pthread_mutex_lock(&sceen->free_shopsticks);
	while (message[i] != '\0')
	{
		write(1, &message[i], 1);
		i++;
	}
	pthread_mutex_unlock(&sceen->free_shopsticks);
}
