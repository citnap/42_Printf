/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_shex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:14:27 by ppanpais          #+#    #+#             */
/*   Updated: 2022/10/14 02:21:58 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

unsigned int	print_shex(unsigned long n)
{
	char			r;
	unsigned int	m;

	m = 0;
	if (n < 16)
	{
		(n < 10) ? (ft_putchar_fd('0' + n, 1)) : (ft_putchar_fd('a' + n - 10, 1));
		m++;
	}
	else
	{
		r = n % 16;
		m += print_shex(n / 16);
		if (r < 10)
			ft_putchar_fd(r + '0', 1);
		else
			ft_putchar_fd(r - 10 + 'a', 1);
		m++;
	}
	return (m);
}

unsigned int	pf_print_shex(unsigned long *n)
{
	return (print_shex(*n));
}