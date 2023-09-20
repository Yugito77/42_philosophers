/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 00:18:10 by hcherpre          #+#    #+#             */
/*   Updated: 2022/03/28 09:30:23 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong Arguments!\n");
		return (1);
	}
	if (!ft_check(argc, argv) || !ft_isdigit(argc, argv))
		return (1);
	ft_init(&rules, argv, argc);
	philo_init(&rules);
	philo(&rules);
	return (0);
}

int	philo(t_rules *rules)
{
	if (rules->nb_philo > 1)
	{
		if (create_thread(rules) == FAILURE || ft_join(rules) == FAILURE)
			return (1);
	}
	else
	{
		if (one_philo(rules) == FAILURE)
		{
			ft_free(rules);
			return (1);
		}
	}
	ft_free(rules);
	return (0);
}
