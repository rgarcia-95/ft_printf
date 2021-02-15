/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 18:57:53 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/15 12:18:20 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_initialize(t_struct *t)
{
	t->i = 0;
	t->len = 0;
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
	t->str = NULL;
}

int			ft_printf(const char *s, ...)
{
	t_struct	*t;
	int			res;

	if (!s)
		return (-1);
	if (!(t = malloc(sizeof(t_struct))))
		return (-1);
	ft_initialize(t);
	va_start(t->list, s);
	if (ft_strchr(s, '%'))
		ft_hard_mode(s, t);
	else
	{
		ft_putstr_fd((char *)s, 1);
		t->len = ft_strlen(s);
	}
	va_end(t->list);
	res = t->len;
	free(t);
	t = NULL;
	return (res);
}
