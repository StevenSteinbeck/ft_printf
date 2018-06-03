/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:38:27 by stestein          #+#    #+#             */
/*   Updated: 2018/05/31 13:57:02 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_imaxtoa(intmax_t value)
{
	t_libft		*head;

	head = malloc(sizeof(t_libft));
	head->intmx = (value < 0) ? -value : value;
	head->size = 1 + (value < 0);
	while ((head->intmx /= 10))
		head->size++;
	head->ret = (char *)malloc(sizeof(char) * (head->size + 1));
	head->ret[head->size] = '\0';
	head->intmx = (value < 0) ? -value : value;
	head->ret[--head->size] = "0123456789"[head->intmx % 10];
	while ((head->intmx /= 10))
		head->ret[--head->size] = "0123456789"[head->intmx % 10];
	if (value < 0)
		head->ret[--head->size] = '-';
	free(head);
	return (head->ret);
}
