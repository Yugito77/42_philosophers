/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoo <hugoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:56:18 by hugoo             #+#    #+#             */
/*   Updated: 2022/03/22 15:20:01 by hugoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_rules *rules)
{
	int	i;

	pthread_mutex_destroy(&rules->print);
	pthread_mutex_destroy(&rules->dead);
	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		pthread_mutex_destroy(&rules->philo[i].lock);
		i++;
	}
	free(rules->forks);
	free(rules->philo);
}
