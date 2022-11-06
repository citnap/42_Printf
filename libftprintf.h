/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:57:18 by ppanpais          #+#    #+#             */
/*   Updated: 2022/11/07 00:06:02 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

unsigned int	pf_printptr(void *ptr);
unsigned int	pf_print_bhex(unsigned long *n);
unsigned int	pf_print_shex(unsigned long *n);
unsigned int	pf_putstr(char *c);
int				pf_print_data(t_list **data);
int				ft_printf(const char *fmt, ...);
unsigned int	pf_putuint(unsigned int *n, int mode);
unsigned int	pf_putchar(char *c);
unsigned int	pf_putnbr(int *n);
t_list			**pf_get_data(char *fmt, va_list arg);
t_list			*pf_getdata_str(char *start, char *end);
char			*pf_get_str(va_list arg);
#endif
