/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_functions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:31:05 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/15 17:50:45 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_nums(unsigned int n)
{
	unsigned int	aux;

	aux = 1;
	while (n >= 10)
	{
		n /= 10;
		aux++;
	}
	return (aux);
}

char				*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	num;
	unsigned int	size;
	char			*s;

	i = 0;
	if (n < 0)
		num = (unsigned int)(n * -1);
	else
		num = (unsigned int)n;
	size = ft_nums(num);
	if (!(s = (char *)malloc(sizeof(char) * (size + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (s[i] = '-'))
		size++;
	i = size - 1;
	while (num >= 10)
	{
		s[i--] = (char)(num % 10 + '0');
		num /= 10;
	}
	s[i] = (char)(num % 10 + '0');
	s[size] = '\0';
	return (s);
}

void				ft_write(int i, char c)
{
	while (i > 0)
	{
		write(1, &c, 1);
		i--;
	}
}

char				*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
		j++;
	if (!(str = (char *)malloc(j + 1)))
		return (0);
	while (i < j)
	{
		str[i] = (char)s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char				*ft_itoa_u(unsigned int n)
{
	unsigned int	i;
	unsigned int	num;
	unsigned int	size;
	char			*s;

	i = 0;
	if (n < 0)
		num = (unsigned int)(n * -1);
	else
		num = (unsigned int)n;
	size = ft_nums(num);
	if (!(s = (char *)malloc(sizeof(char) * (size + 1 + (n < 0 ? 1 : 0)))))
		return (0);
	if (n < 0 && (s[i] = '-'))
		size++;
	i = size - 1;
	while (num >= 10)
	{
		s[i--] = (char)(num % 10 + '0');
		num /= 10;
	}
	s[i] = (char)(num % 10 + '0');
	s[size] = '\0';
	return (s);
}
