/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:03:22 by rgarcia-          #+#    #+#             */
/*   Updated: 2021/02/15 12:29:02 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_struct
{
	va_list					list;
	int						i;
	int						len;
	int						aux;
	unsigned int			aux_u;
	unsigned long long int	aux_u_l;
	int						negative;
	int						flag_minus;
	int						flag_mayus;
	int						flag_zero;
	int						flag_precision;
	int						flag_width;
	int						precision;
	int						width;
	int						size_num;
	char					*str;
}				t_struct;

int				ft_printf(const char *s, ...);
void			ft_hard_mode(const char *s, t_struct *t);
void			ft_special(const char *s, t_struct *t);
void			ft_type(const char *s, t_struct *t);
void			ft_int(t_struct *t);
void			ft_int_extra(t_struct *t);
void			ft_unsigned(t_struct *t);
void			ft_unsigned_extra(t_struct *t);
void			ft_str(t_struct *t);
void			ft_str_extra(t_struct *t);
void			ft_char(t_struct *t);
void			ft_pointer(t_struct *t);
void			ft_pointer_extra(t_struct *t);
void			ft_hexa(t_struct *t);
void			ft_percent(t_struct *t);
int				ft_isdigit(int c);
ssize_t			ft_strlen(const char *s);
int				ft_countdigits(long int c);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strchr(const char *s, int c);
char			*ft_itoa(int n);
void			ft_write(int i, char c);
char			*ft_strdup(const char *s1);
char			*ft_itoa_u(unsigned int n);
char			*ft_to_hexa(t_struct *t);
char			*ft_to_hexa_l(t_struct *t);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
