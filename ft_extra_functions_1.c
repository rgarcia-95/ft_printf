/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_functions_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:22:43 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/15 17:30:26 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

ssize_t	ft_strlen(const char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_countdigits(long int c)
{
	int	i;

	i = 1;
	while (c / 10 > 0)
	{
		i++;
		c /= 10;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != '\0')
		while (*s != '\0')
		{
			write(fd, &(*s), 1);
			s++;
		}
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}
