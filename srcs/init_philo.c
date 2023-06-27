/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:18:44 by amery             #+#    #+#             */
/*   Updated: 2023/06/26 17:13:34 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex_next(t_contr *contr)
{
	if (contr && contr->check_alive)
	{
		pthread_mutex_destroy(contr->check_alive);
		contr->check_alive = free_ptr(contr->check_alive);
	}
	if (contr && contr->end)
	{
		pthread_mutex_destroy(contr->end);
		contr->end = free_ptr(contr->end);
	}
	if (contr)
		contr = free_ptr(contr);
}

void	destroy_mutex(t_contr *contr)
{
	if (contr && contr->write)
	{
		pthread_mutex_destroy(contr->write);
		contr->write = free_ptr(contr->write);
	}
	if (contr && contr->start)
	{
		pthread_mutex_destroy(contr->start);
		contr->start = free_ptr(contr->start);
	}
	if (contr && contr->start_final)
	{
		pthread_mutex_destroy(contr->start_final);
		contr->start_final = free_ptr(contr->start_final);
	}
	destroy_mutex_next(contr);
}

void	*free_philo(t_philo *philo, t_params *params, t_contr *contr)
{
	t_philo	*tmp;
	int		i;

	i = -1;
	while (params && ++i < params->nb_of_philo && philo)
	{
		pthread_mutex_destroy(&philo->fork);
		tmp = philo;
		philo = philo->next;
		tmp = free_ptr(tmp);
	}
	params = free_ptr(params);
	contr->start_count = free_ptr(contr->start_count);
	destroy_mutex(contr);
	return (NULL);
}

t_philo	*philo_content(t_philo *phi, t_params *par, t_contr *contr, int i)
{
	pthread_mutex_init(&phi->fork, NULL);
	phi->name = i + 1;
	phi->alive = 1;
	phi->p = par;
	phi->c = contr;
	return (phi);
}

t_philo	*init_philo(t_params *params, t_contr *contr)
{
	t_philo			*philo;
	t_philo			*first;
	t_philo			*tmp;
	int				i;

	i = -1;
	philo = malloc(sizeof(t_philo));
	first = philo;
	while (++i < params->nb_of_philo && philo)
	{
		philo = philo_content(philo, params, contr, i);
		if (i != 0)
			philo->prec = tmp;
		tmp = philo;
		if (i + 1 < params->nb_of_philo)
			philo->next = malloc(sizeof(t_philo));
		else
			philo->next = first;
		philo = philo->next;
	}
	if (philo || free_philo(first, params, contr))
		philo->prec = tmp;
	return (philo);
}

//void	printphilo(t_philo *philo, t_params *params)
//{
//	int	i;
//
//	i = -1;
//	printf("--All philo :\n\n");
//	while (philo && ++i < params->nb_of_philo)
//	{
//		printf("-Philo : %i \n", philo->name);
//		printf("Fork : %p \n", &philo->fork);
//		printf("Thread : %p \n", philo->thread);
//		printf("Prec : %p \n", philo->prec);
//		printf("Curr : %p \n", philo);
//		printf("Next : %p \n\n", philo->next);
//		philo = philo->next;
//	}
//	printf("\n");
//}
