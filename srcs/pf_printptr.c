/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:57:27 by ppanpais          #+#    #+#             */
/*   Updated: 2022/10/14 15:44:59 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"
#include <inttypes.h>

unsigned int	pf_printptr(void *ptr)
{
	uintptr_t	n;

	if (ptr == NULL)
		return (pf_putstr("(nil)"));
	n = (uintptr_t)ptr;
	ft_putstr_fd("0x", 1);
	return (2 + pf_print_shex(&n));
}
