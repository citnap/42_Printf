/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppanpais <ppanpais@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:03:57 by ppanpais          #+#    #+#             */
/*   Updated: 2022/10/14 21:48:02 by ppanpais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

t_list	*pf_getdata_str(char *start, char *end)
{
	t_list	*new;
	char	*str;

	str = ft_substr(start, 0 , end - start);
	new = ft_lstnew(str, "str");
	return (new);
}

char	*pf_get_str(va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
		str = "(null)";
	return (ft_strdup(str));
}