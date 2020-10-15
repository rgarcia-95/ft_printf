/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:30:04 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/09/16 18:31:41 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_extra(t_struct *t)
{
	int	i;
	int	j;

	i = t->precision;
	j = 0;
	if (t->precision < t->size_num)
	{
		while (i > 0)
		{
			ft_write(1, t->str[j]);
			i--;
			j++;
		}
		t->len += t->precision;
	}
}
