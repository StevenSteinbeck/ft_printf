/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:01:30 by stestein          #+#    #+#             */
/*   Updated: 2018/05/30 19:26:18 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

wchar_t	*ft_wstrdup(wchar_t *str)
{
	t_wstr	*head;

	head = malloc(sizeof(t_wstr));
	head->size = 0;
	while (str[head->size])
		++head->size;
	head->dupl = (wchar_t *)malloc(sizeof(wchar_t) * (head->size + 1));
	if (!head->dupl)
		return (NULL);
	head->size = 0;
	while (str[head->size])
	{
		head->dupl[head->size] = str[head->size];
		head->size++;
	}
	head->dupl[head->size] = '\0';
	free(head);
	return (head->dupl);
}

size_t	ft_wstrlen(wchar_t *str)
{
	t_wstr	*head;

	head = malloc(sizeof(t_wstr));
	head->iii = 0;
	head->size = 0;
	while (str[head->iii])
	{
		head->size += ft_unicode_b(str[head->iii]);
		head->iii++;
	}
	free(head);
	return (head->size);
}

void	ft_prec_wstr(t_info *pfinfo, wchar_t *str)
{
	t_wstr	*head;

	head = malloc(sizeof(t_wstr));
	head->iii = 0;
	head->size = 0;
	if (pfinfo->prec == -1)
	{
		free(head);
		return ;
	}
	if (ft_wstrlen(str) <= (size_t)pfinfo->prec)
	{
		free(head);
		return ;
	}
	while (str[head->iii] && head->size <= (size_t)pfinfo->prec)
	{
		head->size += ft_unicode_b(str[head->iii]);
		head->iii++;
	}
	str[head->iii - 1] = '\0';
	free(head);
}

char	*ft_wstr_to_str(wchar_t *wstr)
{
	t_wstr	*head;

	head = malloc(sizeof(t_wstr));
	head->iii = 0;
	head->size = 0;
	head->value = ft_strnew(ft_wstrlen(wstr));
	while (wstr[head->iii])
	{
		ft_unicode_conv(wstr[head->iii], head->value + head->size);
		head->size += ft_unicode_b(wstr[head->iii]);
		head->iii++;
	}
	free(head);
	return (head->value);
}

void	ft_wstr_conv(t_vector *vector, t_info *pfinfo, va_list ap)
{
	t_wstr	*head;

	head = malloc(sizeof(t_wstr));
	head->dupl = va_arg(ap, wchar_t *);
	if (!head->dupl)
		head->value = ft_null_str(pfinfo);
	else
	{
		head->dupl = ft_wstrdup(head->dupl);
		ft_prec_wstr(pfinfo, head->dupl);
		head->value = ft_wstr_to_str(head->dupl);
		free(head->dupl);
	}
	ft_pad_handle(pfinfo, &head->value);
	ft_vector_append(vector, head->value);
	free(head->value);
	free(head);
}
