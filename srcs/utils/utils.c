/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:43:47 by amery             #+#    #+#             */
/*   Updated: 2023/06/07 15:30:25 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

void	ft_putstr_fd(const char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
