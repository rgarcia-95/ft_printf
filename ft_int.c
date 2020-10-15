/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 16:39:46 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/16 17:11:18 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_no_minus_no_precision(t_struct *t)
{
	if (t->flag_width && (t->width > t->size_num))
	{
		if (t->flag_zero)
		{
			if (t->negative)
				ft_write(1, '-');
			ft_write((t->width - t->size_num), '0');
		}
		else
		{
			ft_write((t->width - t->size_num), ' ');
			if (t->negative)
				ft_write(1, '-');
		}
		ft_putstr_fd(t->str, 1);
		t->len += t->width;
	}
	else
	{
		if (t->negative)
			ft_write(1, '-');
		ft_putstr_fd(t->str, 1);
		t->len += t->size_num;
	}
}

static void	ft_no_minus_yes_precision(t_struct *t)
{
	if (t->precision <= ft_countdigits(t->aux))
		ft_no_minus_no_precision(t);
	else
	{
		if (t->flag_width && (t->width > t->precision))
		{
			if (t->negative)
			{
				ft_write((t->width - t->precision - t->negative), ' ');
				t->negative = 0;
				ft_write(1, '-');
			}
			else
				ft_write((t->width - t->precision), ' ');
			t->len += (t->width - t->precision);
		}
		ft_int_extra(t);
	}
}

static void	ft_yes_minus_no_precision(t_struct *t)
{
	if (t->flag_width && (t->width > t->size_num))
	{
		if (t->negative)
			ft_write(1, '-');
		ft_putstr_fd(t->str, 1);
		ft_write((t->width - t->size_num), ' ');
		t->len += t->width;
	}
	else
	{
		if (t->negative)
			ft_write(1, '-');
		ft_putstr_fd(t->str, 1);
		t->len += t->size_num;
	}
}

static void	ft_yes_minus_yes_precision(t_struct *t)
{
	if (t->precision <= ft_countdigits(t->aux))
		ft_yes_minus_no_precision(t);
	else
	{
		if (t->flag_width && (t->width > t->precision))
		{
			if (t->negative)
			{
				t->negative = 0;
				ft_write(1, '-');
				ft_int_extra(t);
				t->negative = 1;
				ft_write((t->width - t->precision - t->negative), ' ');
			}
			else
			{
				ft_int_extra(t);
				ft_write((t->width - t->precision), ' ');
			}
			t->len += (t->width - t->precision);
		}
		else
			ft_int_extra(t);
	}
}

void		ft_int(t_struct *t)
{
	t->aux = va_arg(t->list, int);
	if (t->aux < 0 && t->aux != -2147483648)
	{
		t->negative = 1;
		t->aux = -(t->aux);
	}
	t->size_num = ft_countdigits(t->aux) + t->negative;
	if (t->aux == -2147483648)
		t->size_num += 10;
	if (t->flag_precision && t->precision == 0 && t->aux == 0)
	{
		t->str = ft_strdup("");
		t->size_num--;
	}
	else
		t->str = ft_itoa(t->aux);
	if (t->flag_minus == 0 && t->flag_precision == 0)
		ft_no_minus_no_precision(t);
	else if (t->flag_minus == 0 && t->flag_precision == 1)
		ft_no_minus_yes_precision(t);
	else if (t->flag_minus == 1 && t->flag_precision == 0)
		ft_yes_minus_no_precision(t);
	else if (t->flag_minus == 1 && t->flag_precision == 1)
		ft_yes_minus_yes_precision(t);
}
