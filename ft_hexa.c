/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:42:22 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/16 19:57:03 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_no_minus_no_precision(t_struct *t)
{
	if (t->flag_width && (t->width > t->size_num))
	{
		if (t->flag_zero)
			ft_write((t->width - t->size_num), '0');
		else
			ft_write((t->width - t->size_num), ' ');
		ft_putstr_fd(t->str, 1);
		t->len += t->width;
	}
	else
	{
		ft_putstr_fd(t->str, 1);
		t->len += t->size_num;
	}
}

static void	ft_no_minus_yes_precision(t_struct *t)
{
	if (t->precision <= t->size_num)
		ft_no_minus_no_precision(t);
	else
	{
		if (t->flag_width && (t->width > t->precision))
		{
			ft_write((t->width - t->precision), ' ');
			t->len += (t->width - t->precision);
		}
		ft_unsigned_extra(t);
	}
}

static void	ft_yes_minus_no_precision(t_struct *t)
{
	if (t->flag_width && (t->width > t->size_num))
	{
		ft_putstr_fd(t->str, 1);
		ft_write((t->width - t->size_num), ' ');
		t->len += t->width;
	}
	else
	{
		ft_putstr_fd(t->str, 1);
		t->len += t->size_num;
	}
}

static void	ft_yes_minus_yes_precision(t_struct *t)
{
	if (t->precision <= t->size_num)
		ft_yes_minus_no_precision(t);
	else
	{
		if (t->flag_width && (t->width > t->precision))
		{
			ft_unsigned_extra(t);
			ft_write((t->width - t->precision), ' ');
			t->len += (t->width - t->precision);
		}
		else
			ft_unsigned_extra(t);
	}
}

void		ft_hexa(t_struct *t)
{
	t->aux_u = va_arg(t->list, unsigned int);
	if (t->flag_precision == 0 && t->aux_u == 0)
		t->str = ft_strdup("0");
	else
		t->str = ft_to_hexa(t);
	t->size_num = ft_strlen(t->str);
	if (t->flag_minus == 0 && t->flag_precision == 0)
		ft_no_minus_no_precision(t);
	else if (t->flag_minus == 0 && t->flag_precision == 1)
		ft_no_minus_yes_precision(t);
	else if (t->flag_minus == 1 && t->flag_precision == 0)
		ft_yes_minus_no_precision(t);
	else if (t->flag_minus == 1 && t->flag_precision == 1)
		ft_yes_minus_yes_precision(t);
}
