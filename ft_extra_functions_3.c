/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_functions_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:53:25 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/15 18:11:08 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countdigits_hexa(unsigned int c)
{
	int	i;

	i = 1;
	while (c / 16 > 0)
	{
		i++;
		c /= 16;
	}
	return (i);
}

char		*ft_to_hexa(t_struct *t)
{
	int		i;
	char	*s;
	char	*str;

	i = ft_countdigits_hexa(t->aux_u);
	if (!(s = malloc(sizeof(char) * 17)))
		return (0);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	if (t->flag_mayus)
		s = "0123456789ABCDEF";
	else
		s = "0123456789abcdef";
	i--;
	while (t->aux_u > 0)
	{
		str[i] = s[t->aux_u % 16];
		t->aux_u /= 16;
		i--;
	}
	return (str);
}

static int	ft_countdigits_hexa_l(unsigned long long int c)
{
	int	i;

	i = 1;
	while (c / 16 > 0)
	{
		i++;
		c /= 16;
	}
	return (i);
}

char		*ft_to_hexa_l(t_struct *t)
{
	int		i;
	char	*s;
	char	*str;

	i = ft_countdigits_hexa_l(t->aux_u_l);
	if (!(s = malloc(sizeof(char) * 17)))
		return (0);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	if (t->flag_mayus)
		s = "0123456789ABCDEF";
	else
		s = "0123456789abcdef";
	i--;
	while (t->aux_u_l > 0)
	{
		str[i] = s[t->aux_u_l % 16];
		t->aux_u_l /= 16;
		i--;
	}
	return (str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (s1 != 0 && s2 != 0)
	{
		i = ft_strlen(s1) + ft_strlen(s2) + 1;
		if (!(str = (char *)malloc(i)))
			return (0);
		i = 0;
		while (s1[i] != '\0')
		{
			str[i] = (char)s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
		{
			str[i + j] = (char)s2[j];
			j++;
		}
		str[i + j] = '\0';
		return (str);
	}
	return (0);
}
