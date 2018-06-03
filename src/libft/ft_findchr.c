/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:37:53 by stestein          #+#    #+#             */
/*   Updated: 2018/05/31 13:48:52 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_findchr(const char *s, int c)
{
	t_libft	*head;

	head = malloc(sizeof(t_libft));
	head->a = (unsigned char)c;
	head->i = 0;
	free(head);
	while (s[head->i] != '\0')
	{
		if (s[head->i] == head->a)
			return (head->i);
		head->i++;
	}
	if (s[head->i] == head->a)
		return (ft_strlen(s) + 1);
	return (0);
}
