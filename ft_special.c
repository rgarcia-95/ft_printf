/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 19:17:41 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/15 19:34:10 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flags(const char *s, t_struct *t)
{
	while (s[t->i] == '-' || s[t->i] == '0')
	{
		if (s[t->i] == '-')
			t->flag_minus = 1;
		else
			t->flag_zero = 1;
		if (t->flag_minus)
			t->flag_zero = 0;
		t->i++;
	}
}

static void	ft_width(const char *s, t_struct *t)
{
	if (s[t->i] == '*' || ft_isdigit((int)s[t->i]))
	{
		t->flag_width = 1;
		if (s[t->i] == '*')
		{
			t->width = va_arg(t->list, int);
			if (t->width < 0)
			{
				t->width = -(t->width);
				t->flag_minus = 1;
			}
			t->i++;
		}
		else
		{
			while (ft_isdigit((int)s[t->i]))
			{
				t->width = t->width * 10 + (s[t->i] - '0');
				t->i++;
			}
		}
	}
}

static void	ft_precision(const char *s, t_struct *t)
{
	if (s[t->i] == '.')
	{
		t->i++;
		t->flag_zero = 0;
		t->flag_precision = 1;
		if (s[t->i] == '*')
		{
			t->precision = va_arg(t->list, int);
			if (t->precision < 0)
				t->flag_precision = 0;
			t->i++;
		}
		else
		{
			while (ft_isdigit((int)s[t->i]))
			{
				t->precision = t->precision * 10 + (s[t->i] - '0');
				t->i++;
			}
		}
	}
}

void		ft_special(const char *s, t_struct *t)
{
	ft_flags(s, t);
	ft_width(s, t);
	ft_precision(s, t);
}
