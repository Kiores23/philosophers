/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:22:52 by amery             #+#    #+#             */
/*   Updated: 2023/06/29 11:21:33 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_thinking(t_philo *philo)
{
	philo->t_stape = get_current_time_in_ms();
	if (!philo_write(philo, "is thinking"))
		return (0);
	if (philo->i == 0 && !(philo->name % 2))
		usleep(50000);
	return (1);
}

int	philo_sleeping(t_philo *philo)
{
	if (!philo_write(philo, "is sleeping"))
		return (0);
	return (wait_philo(philo, philo->p->time_to_sleep));
}

int	philo_taken_a_fork(t_philo *philo)
{
	if (philo->p->time_to_eat > philo->p->time_to_sleep && philo->i != 0
		&& !wait_philo(philo,
			philo->p->time_to_eat - philo->p->time_to_sleep - 1))
		return (0);
	pthread_mutex_lock(&philo->fork);
	if (!philo_write(philo, "has taken a fork") || (philo->p->nb_of_philo == 1
			&& !wait_philo(philo, philo->p->time_to_die * 2)))
	{
		pthread_mutex_unlock(&philo->fork);
		return (0);
	}
	philo->t_stape = get_current_time_in_ms();
	if (philo->p->nb_of_philo % 2 && philo->name == philo->p->nb_of_philo - 1
		&& philo->i == 0 && !wait_philo(philo, philo->p->time_to_eat))
		return (0);
	pthread_mutex_lock(&philo->next->fork);
	if (!philo_write(philo, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		return (0);
	}
	return (1);
}

int	philo_opti_brute_force(t_philo *philo)
{
	unsigned long	tmp;
	unsigned long	tmp2;

	tmp2 = philo->t_stape;
	if (!philo_taken_a_fork(philo))
		return (0);
	tmp = get_current_time_in_ms();
	if (philo->i == 0 && tmp - tmp2 >= philo->p->time_to_eat - 1
		&& tmp - tmp2 <= philo->p->time_to_eat + 1)
		philo->t_reset += philo->p->time_to_eat;
	else if (philo->i != 0 && tmp - tmp2 >= philo->p->time_to_eat - 1
		&& tmp - tmp2 <= philo->p->time_to_eat + 1)
		philo->t_reset += (philo->p->time_to_eat * 2 + philo->p->time_to_sleep);
	else if (tmp - tmp2 >= 59)
		philo->t_reset = tmp;
	else if (philo->i != 0)
		philo->t_reset += (philo->p->time_to_eat + philo->p->time_to_sleep);
	philo->t_stape = philo->t_reset;
	return (1);
}

int	philo_eating(t_philo *philo)
{
	int				r;

	if (!philo_opti_brute_force(philo))
		return (0);
	if (!philo_write(philo, "is eating"))
	{
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		return (0);
	}
	r = wait_philo(philo, philo->p->time_to_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
	return (r);
}
