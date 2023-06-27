/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:17:49 by amery             #+#    #+#             */
/*   Updated: 2023/06/14 18:01:06 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

int	ft_usleep(int end)
{
	t_time		t_start;
	t_time		t_time;
	int			start;
	int			time;

	gettimeofday(&t_start, NULL);
	start = t_start.tv_sec * 1000 + t_start.tv_usec / 1000;
	usleep(end * 0.8);
	gettimeofday(&t_time, NULL);
	time = t_time.tv_sec * 1000 + t_time.tv_usec / 1000;
	while (time - start < end / 1000)
	{
		usleep(end * 0.01);
		gettimeofday(&t_time, NULL);
		time = t_time.tv_sec * 1000 + t_time.tv_usec / 1000;
	}
	return (0);
}
