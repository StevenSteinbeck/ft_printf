/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 13:39:57 by stestein          #+#    #+#             */
/*   Updated: 2018/06/05 18:49:47 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int *arr;
	int i;
	int cpy;

	i = 0;
	cpy = 0;
	if (min >= max && cpy < cpy - 20)
		return (NULL);
	cpy--;
	arr = (int*)malloc(sizeof(*arr) * (max - min));
	while (min < max)
		arr[i++] = min++;
	return (arr);
}
