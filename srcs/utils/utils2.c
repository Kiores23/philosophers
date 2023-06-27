/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amery <amery@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:05:44 by amery             #+#    #+#             */
/*   Updated: 2023/04/28 12:55:39 by amery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n - 1)
		i++;
	if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i] && i < n)
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}

long	ft_atoi(const char *str)
{
	char	*s;
	long	r;
	int		sign;

	s = (char *)str;
	sign = 1;
	r = 0;
	while ((9 <= *s && *s <= 13) || *s == 32)
		s++;
	if (*(s) == '+' || *s == '-')
	{
		if (*(s++) == '-')
			sign *= -1;
	}
	s--;
	while (ft_isdigit(*(++s)) && r <= 2147483648)
		r = r * 10 + *s - '0';
	while (*s)
	{
		if (!(9 <= *s && *s <= 13) && *s != 32)
			return (0);
		s++;
	}
	return (r * sign);
}
