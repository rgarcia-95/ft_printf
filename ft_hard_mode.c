/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hard_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:06:44 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/15 12:30:22 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_reinitialize(t_struct *t)
{
	t->aux = 0;
	t->aux_u = 0;
	t->aux_u_l = 0;
	t->negative = 0;
	t->flag_minus = 0;
	t->flag_mayus = 0;
	t->flag_zero = 0;
	t->flag_precision = 0;
	t->flag_width = 0;
	t->precision = 0;
	t->width = 0;
	t->size_num = 0;
	if (t->str != NULL)
	{
		free(t->str);
		t->str = NULL;
	}
}

void		ft_hard_mode(const char *s, t_struct *t)
{
	t->i = 0;
	while (s[t->i])
	{
		ft_reinitialize(t);
		if (s[t->i] == '%')
		{
			t->i++;
			if (s[t->i] != '\0' && ft_strchr(".*-0123456789", s[t->i]))
				ft_special(s, t);
			if (s[t->i] != '\0' && ft_strchr("cspdiuxX%", s[t->i]))
				ft_type(s, t);
		}
		else
		{
			write(1, &(s[t->i]), 1);
			t->len++;
		}
		if (s[t->i] != '\0')
			t->i++;
	}
}
