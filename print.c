/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugoo <hugoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:47:01 by hcherpre          #+#    #+#             */
/*   Updated: 2022/03/22 15:17:28 by hugoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_philo *philo, char *text, char *color)
{
	pthread_mutex_lock(&philo->rules->dead);
	if (philo->rules->philo_dead == 0 && philo->must_eat != 0)
	{
		pthread_mutex_lock(&philo->rules->print);
		printf("%s%lld ms    | %d %s\n", color,
			(ft_time() - philo->rules->start),
			philo->philo_id, text);
		pthread_mutex_unlock(&philo->rules->print);
	}
	pthread_mutex_unlock(&philo->rules->dead);
}
