/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:20:57 by hcherpre          #+#    #+#             */
/*   Updated: 2022/03/28 09:39:16 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_rules *rules)
{
	int	i;

	i = 0;
	ft_usleep(2);
	while (1)
	{
		i = 0;
		while (i < rules->nb_philo)
		{
			if (is_alive(&rules->philo[i]) == FAILURE)
			{
				pthread_mutex_lock(&rules->dead);
				rules->philo_dead = 1;
				pthread_mutex_unlock(&rules->dead);
				return (FAILURE);
			}
			i++;
			ft_usleep(2);
		}
	}
	return (SUCCESS);
}

int	is_alive(t_philo *philo)
{
	pthread_mutex_lock(&philo->lock);
	if ((ft_time() - philo->last_diner) > philo->rules->time_die
		&& !philo->rules->philo_dead)
	{
		if (philo->must_eat != 0)
		{
			printf("%s%lld ms | %d died ☠️ !\n", RED,
				(ft_time() - philo->rules->start), philo->philo_id);
			pthread_mutex_unlock(&philo->lock);
			return (FAILURE);
		}
		else
		{
			pthread_mutex_unlock(&philo->lock);
			return (FAILURE);
		}
	}
	pthread_mutex_unlock(&philo->lock);
	return (SUCCESS);
}
