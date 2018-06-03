/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:40:18 by stestein          #+#    #+#             */
/*   Updated: 2018/05/30 19:01:16 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_vector_init(t_vector *vector, size_t init_cap)
{
	t_vect *head;

	if (!vector || !init_cap)
		return (FAILED);
	head = malloc(sizeof(t_vect));
	head->init = init_cap;
	vector->len = 0;
	vector->cap = head->init;
	free(head);
	if ((vector->data = ft_memalloc(sizeof(char) * vector->cap)) == NULL)
		return (FAILED);
	return (SUCCESS);
}

void	ft_vector_append(t_vector *vector, char *newdata)
{
	t_vect	*head;

	head = malloc(sizeof(t_vect));
	head->size = ft_strlen(newdata);
	if (vector->cap < vector->len + head->size)
		ft_vector_resize(vector, vector->len + head->size);
	ft_memcpy(vector->data + vector->len, newdata, head->size);
	vector->len += head->size;
	free(head);
}

void	ft_vector_resize(t_vector *vector, size_t min)
{
	t_vect	*head;

	head = malloc(sizeof(t_vect));
	if (!(vector->data))
		ft_vector_init(vector, min);
	head->size = vector->cap;
	while (head->size < min)
		head->size *= 2;
	vector->data = (char *)ft_recalloc(vector->data, vector->len, head->size);
	vector->cap = head->size;
	free(head);
}

void	ft_vector_nappend(t_vector *vector, char *newdata, size_t n)
{
	t_vect	*head;

	head = malloc(sizeof(t_vect));
	head->size = n;
	if (vector->cap < vector->len + head->size)
		ft_vector_resize(vector, vector->len + head->size);
	ft_memcpy(vector->data + vector->len, newdata, head->size);
	vector->len += head->size;
	free(head);
}

void	ft_vector_free(t_vector *vector)
{
	t_vect	*head;

	head = malloc(sizeof(t_vect));
	head->string = vector->data;
	if (head->string && vector->cap > 0)
	{
		free(head->string);
		head->string = NULL;
	}
	free(head);
}
