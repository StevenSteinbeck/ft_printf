/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:39:07 by stestein          #+#    #+#             */
/*   Updated: 2018/05/31 14:03:15 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	t_libft	*head;
	
	head = malloc(sizeof(t_libft));
	head->i = 0;
	free(head);
	if (length == 0 || length == 1)
		return (1);
	while (head->i < length - 1)
	{
		if (f(tab[head->i], tab[head->i + 1]) <= 0)
			head->i++;
		else
			break ;
	}
	if (head->i == length - 1)
		return (1);
	return (0);
}
