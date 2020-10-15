/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:39:01 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/16 19:41:03 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer_extra(t_struct *t)
{
	int	i;

	i = t->size_num - 2;
	if (t->precision > i)
	{
		ft_write((t->precision - i), '0');
		t->len += (t->precision - i);
	}
	ft_putstr_fd(t->str, 1);
	t->len += t->size_num;
}
