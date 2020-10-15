/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:21:56 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/16 18:09:30 by rgarcia-         ###   ########.fr       */
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
	if (t->precision <= ft_countdigits(t->aux_u))
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
	if (t->precision <= ft_countdigits(t->aux_u))
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

void		ft_unsigned(t_struct *t)
{
	t->aux_u = va_arg(t->list, unsigned int);
	if (t->aux_u == 4294967295)
		t->size_num = 10;
	else
		t->size_num = ft_countdigits(t->aux_u);
	if (t->flag_precision && t->precision == 0 && t->aux_u == 0)
	{
		t->str = ft_strdup("");
		t->size_num--;
	}
	else
		t->str = ft_itoa_u(t->aux_u);
	if (t->flag_minus == 0 && t->flag_precision == 0)
		ft_no_minus_no_precision(t);
	else if (t->flag_minus == 0 && t->flag_precision == 1)
		ft_no_minus_yes_precision(t);
	else if (t->flag_minus == 1 && t->flag_precision == 0)
		ft_yes_minus_no_precision(t);
	else if (t->flag_minus == 1 && t->flag_precision == 1)
		ft_yes_minus_yes_precision(t);
}
