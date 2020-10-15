/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:17:13 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/16 17:19:58 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_int_extra(t_struct *t)
{
	if (t->negative)
	{
		ft_write(1, '-');
		t->len++;
	}
	if (t->precision > ft_countdigits(t->aux))
	{
		ft_write((t->precision - ft_countdigits(t->aux)), '0');
		t->len += (t->precision - ft_countdigits(t->aux));
	}
	ft_putstr_fd(t->str, 1);
	t->len += ft_countdigits(t->aux);
}
