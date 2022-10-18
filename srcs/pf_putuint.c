/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:42:27 by ppanpais          #+#    #+#             */
/*   Updated: 2022/10/14 15:31:14 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static unsigned int	print_shex(unsigned int n)
{
	char			r;
	unsigned int	m;

	m = 0;
	if (n < 16)
	{
		if (n < 10)
			ft_putchar_fd('0' + n, 1);
		else
			ft_putchar_fd('a' + n - 10, 1);
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

static unsigned int	print_bhex(unsigned int n)
{
	unsigned int	r;
	unsigned int	m;

	r = 0;
	m = 0;
	if (n < 16)
	{
		if (n < 10)
			ft_putchar_fd('0' + n, 1);
		else
			ft_putchar_fd('A' + n - 10, 1);
		m++;
	}
	else
	{
		r = n % 16;
		m += print_bhex(n / 16);
		if (r < 10)
			ft_putchar_fd(r + '0', 1);
		else
			ft_putchar_fd(r - 10 + 'A', 1);
		m++;
	}
	return (m);
}

unsigned int	pf_putuint(unsigned int *n, int mode)
{
	unsigned int	m;
	unsigned int	tmp;

	if (mode == 1)
		return (print_bhex(*n));
	if (mode == 2)
		return (print_shex(*n));
	m = 0;
	if (*n < 10)
	{
		ft_putchar_fd(*n + '0', 1);
		m++;
	}
	else
	{
		tmp = *n / 10;
		m += pf_putuint(&tmp, 0);
		ft_putchar_fd(*n % 10 + '0', 1);
		m++;
	}
	return (m);
}
