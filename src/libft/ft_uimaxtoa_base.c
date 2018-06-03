/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:41:23 by stestein          #+#    #+#             */
/*   Updated: 2018/06/03 12:49:16 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uimaxtoa_base(uintmax_t value, int8_t base, const char *str)
{
	t_uimax	head;

	head.i_val = value;
	if (head.i_val != value)
		return (NULL);
	head.size = 1;
	while ((head.i_val /= base))
		head.size++;
	head.retrn = (char *)malloc(sizeof(char) * (head.size + 1));
	head.retrn[head.size] = '\0';
	head.i_val = value;
	head.retrn[--head.size] = str[head.i_val % base];
	while ((head.i_val /= base))
		head.retrn[--head.size] = str[head.i_val % base];
	return (head.retrn);
}
