/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:18:47 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/16 19:38:21 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_no_minus_no_precision(t_struct *t)
{
	if (t->flag_width && (t->width > t->size_num))
	{
		if (t->flag_zero)
		{
			ft_putstr_fd("0x", 1);
			ft_write((t->width - t->size_num), '0');
		}
		else
		{
			ft_write((t->width - t->size_num), ' ');
			ft_putstr_fd("0x", 1);
		}
		ft_putstr_fd(t->str, 1);
		t->len += t->width;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(t->str, 1);
		t->len += t->size_num;
	}
}

static void	ft_no_minus_yes_precision(t_struct *t)
{
	if (t->precision <= (t->size_num - 2))
		ft_no_minus_no_precision(t);
	else
	{
		if (t->flag_width && (t->width > t->precision))
		{
			ft_write((t->width - t->precision - 2), ' ');
			t->len += t->width - t->precision - 2;
		}
		ft_putstr_fd("0x", 1);
		ft_pointer_extra(t);
	}
}

static void	ft_yes_minus_no_precision(t_struct *t)
{
	if (t->flag_width && (t->width > t->size_num))
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(t->str, 1);
		ft_write((t->width - t->size_num), ' ');
		t->len += t->width;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(t->str, 1);
		t->len += t->size_num;
	}
}

static void	ft_yes_minus_yes_precision(t_struct *t)
{
	if (t->precision <= (t->size_num - 2))
		ft_no_minus_no_precision(t);
	else
	{
		ft_putstr_fd("0x", 1);
		ft_pointer_extra(t);
		if (t->flag_width && (t->width > t->precision))
		{
			ft_write(t->width - t->precision - 2, ' ');
			t->len += t->width - t->precision - 2;
		}
	}
}

void		ft_pointer(t_struct *t)
{
	t->aux_u_l = va_arg(t->list, unsigned long long int);
	if (t->aux_u_l == 0)
	{
		if (t->flag_precision && t->precision == 0)
			t->str = ft_strdup("");
		else
			t->str = ft_strdup("0");
	}
	else
		t->str = ft_to_hexa_l(t);
	t->size_num = ft_strlen(t->str) + 2;
	if (t->flag_minus == 0 && t->flag_precision == 0)
		ft_no_minus_no_precision(t);
	else if (t->flag_minus == 0 && t->flag_precision == 1)
		ft_no_minus_yes_precision(t);
	else if (t->flag_minus == 1 && t->flag_precision == 0)
		ft_yes_minus_no_precision(t);
	else if (t->flag_minus == 1 && t->flag_precision == 1)
		ft_yes_minus_yes_precision(t);
}
