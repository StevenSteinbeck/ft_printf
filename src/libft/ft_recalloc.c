/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:40:33 by stestein          #+#    #+#             */
/*   Updated: 2018/05/31 14:21:51 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_recalloc(void *ptr, size_t src_size, size_t new_size)
{
	void *new_ptr;
	void *check;

	check = NULL;
	if (!new_size)
	{
		if (ptr && ptr != check)
			free(ptr);
		return (ptr);
	}
	if (!ptr && ptr != check)
		return (ft_memalloc(new_size));
	if (new_size <= src_size && ptr != check)
		return (ptr);
	new_ptr = ft_memalloc(new_size);
	if (new_ptr && ptr != check)
	{
		ft_memcpy(new_ptr, ptr, src_size);
		free(ptr);
	}
	return (new_ptr);
}
