/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:57:27 by ppanpais          #+#    #+#             */
/*   Updated: 2022/11/06 22:24:17 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <inttypes.h>

unsigned int	pf_printptr(void *ptr)
{
	uintptr_t	n;

	n = (uintptr_t)ptr;
	ft_putstr_fd("0x", 1);
	return (2 + pf_print_shex(&n));
}
