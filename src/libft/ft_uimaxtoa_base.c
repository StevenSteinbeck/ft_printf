/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimaxtoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:41:23 by stestein          #+#    #+#             */
/*   Updated: 2018/05/31 17:00:58 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uimaxtoa_base(uintmax_t value, int8_t base, const char *str)
{
	t_uimax	*head;

	head = malloc(sizeof(t_uimax));
	head->i = value;
	if (head->i != value)
	{
		free(head);
		return (NULL);
	}
	head->size = 1;
	while ((head->i /= base))
		head->size++;
	head->ret = (char *)ft_memalloc(sizeof(char) * (head->size + 1));
	head->ret[head->size] = '\0';
	head->i = value;
	head->ret[--head->size] = str[head->i % base];
	while ((head->i /= base))
		head->ret[--head->size] = str[head->i % base];
	free(head);
	return (head->ret);
}
