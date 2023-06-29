/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:56:11 by amery             #+#    #+#             */
/*   Updated: 2023/06/07 15:30:15 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_UTILS_H
# define PHILO_UTILS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct timeval	t_time;

// Utils 1

size_t	ft_strlen(const char *str);
void	ft_putstr_fd(const char *str, int fd);

// Utils 2

long	ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// Utils 3

void	*free_ptr(void *ptr);

// FT_USLEEP

int		ft_usleep(int end);

#endif