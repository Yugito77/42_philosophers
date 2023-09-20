/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:28:11 by hcherpre          #+#    #+#             */
/*   Updated: 2022/03/28 09:38:38 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		if (pthread_create(&rules->philo[i].thread, NULL, (void *)routine,
				((void *)&rules->philo[i])) != SUCCESS)
			return (FAILURE);
		i++;
	}
	if (pthread_create(&rules->check_death, NULL, (void *)check_death,
			(void *)rules) != SUCCESS)
		return (FAILURE);
	return (SUCCESS);
}

void	routine(t_philo	*philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->rules->dead);
		if (philo->rules->philo_dead == 0)
		{
			pthread_mutex_unlock(&philo->rules->dead);
			if (philo->philo_id % 2 == 0)
				is_eating(philo, philo->fork_left, philo->fork_right);
			else
				is_eating(philo, philo->fork_right, philo->fork_left);
			is_sleeping(philo);
			is_thinking(philo);
			ft_usleep(1);
			if (!philo->must_eat)
				return ;
		}
		else
			break ;
	}
	pthread_mutex_unlock(&philo->rules->dead);
}

int	one_philo(t_rules *rules)
{
	printf("%s%lld ms    | %d has taken a fork\n", GREEN,
		(ft_time() - rules->philo[0].last_diner), rules->philo[0].philo_id);
	ft_usleep(rules->time_die);
	printf("%s%lld ms    | %d died\n", RED,
		(ft_time() - rules->philo[0].last_diner), rules->philo[0].philo_id);
	return (FAILURE);
}

int	ft_join(t_rules *rules)
{
	int	i;

	i = 0;
	if (pthread_join(rules->check_death, NULL) != SUCCESS)
		return (FAILURE);
	while (i < rules->nb_philo)
	{
		if (pthread_join(rules->philo[i].thread, NULL) != SUCCESS)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
