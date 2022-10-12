/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:42:27 by ppanpais          #+#    #+#             */
/*   Updated: 2022/10/11 14:57:20 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

unsigned int	pf_putuint(unsigned int *n)
{
	unsigned int	m;

	m = 0;
	if (*n < 10)
	{
		ft_putchar_fd(*n + '0', 1);
		m++;
	}
	else
	{
		unsigned int	tmp;
		tmp = *n / 10;
		m += pf_putuint(&tmp);
		ft_putchar_fd(*n % 10 + '0', 1);
		m++;
	}
	return (m);
}