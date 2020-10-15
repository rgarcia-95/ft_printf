/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_extra.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:10:05 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/16 18:11:37 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_extra(t_struct *t)
{
	if (t->precision > t->size_num)
	{
		ft_write((t->precision - t->size_num), '0');
		t->len += (t->precision - t->size_num);
	}
	ft_putstr_fd(t->str, 1);
	t->len += t->size_num;
}
