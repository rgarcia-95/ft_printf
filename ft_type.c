/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:43:10 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/15 19:55:06 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type(const char *s, t_struct *t)
{
	if (s[t->i] == 'd' || s[t->i] == 'i')
		ft_int(t);
	else if (s[t->i] == 'u')
		ft_unsigned(t);
	else if (s[t->i] == 's')
		ft_str(t);
	else if (s[t->i] == 'c')
		ft_char(t);
	else if (s[t->i] == 'p')
		ft_pointer(t);
	else if (s[t->i] == 'x' || s[t->i] == 'X')
	{
		if (s[t->i] == 'X')
			t->flag_mayus = 1;
		ft_hexa(t);
	}
	else if (s[t->i] == '%')
		ft_percent(t);
}
