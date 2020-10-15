/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:59:31 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/16 20:05:42 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_no_minus(t_struct *t, int c)
{
	if (t->flag_width && (t->width > t->size_num))
	{
		if (t->flag_zero)
			ft_write((t->width - t->size_num), '0');
		else
			ft_write((t->width - t->size_num), ' ');
		ft_write(1, c);
		t->len += t->width;
	}
	else
	{
		ft_write(1, c);
		t->len++;
	}
}

static void	ft_yes_minus(t_struct *t, int c)
{
	if (t->flag_width && (t->width > t->size_num))
	{
		ft_write(1, c);
		if (t->flag_zero)
			ft_write((t->width - t->size_num), '0');
		else
			ft_write((t->width - t->size_num), ' ');
		t->len += t->width;
	}
	else
	{
		ft_write(1, c);
		t->len++;
	}
}

void		ft_percent(t_struct *t)
{
	int	c;

	c = '%';
	t->size_num = 1;
	if (t->flag_minus == 0)
		ft_no_minus(t, c);
	else
		ft_yes_minus(t, c);
}
