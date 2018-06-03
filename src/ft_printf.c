/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:52:02 by stestein          #+#    #+#             */
/*   Updated: 2018/05/29 16:15:58 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_printf *head;

	head = malloc(sizeof(t_printf));
	if (!format || !*format)
		return (0);
	va_start(ap, format);
	head->len = ft_vasprintf(&head->ret, format, ap);
	write(1, head->ret, head->len);
	free(head->ret);
	va_end(ap);
	free(head);
	return (head->len);
}

int		ft_vasprintf(char **ret, const char *format, va_list ap)
{
	t_printf *head;

	head = NULL;
	head = malloc(sizeof(t_printf));
	head->format = format;
	if (*head->format == '\0')
		*ret = ft_strnew(0);
	if (!ret || !head->format || !*head->format)
	{
		free(head);
		return (0);
	}
	if (ft_strchr(head->format, '%') == NULL)
	{
		if ((*ret = ft_strdup(head->format)) == NULL)
		{
			free(head);
			return (-1);
		}
		free(head);
		return (ft_strlen(*ret));
	}
	free(head);
	return (ft_strprintf(ret, head->format, ap));
}

int		ft_sprintf(char *str, const char *format, ...)
{
	va_list ap;
	t_printf *head;

	head = NULL;
	if (!str || !format)
		return (0);
	va_start(ap, format);
	head->len = ft_vasprintf(&head->ret, format, ap);
	ft_strcpy(str, head->ret);
	free(head->ret);
	va_end(ap);
	free(head);
	return (head->len);
}

int		ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list ap;
	t_printf *head;

	head = NULL;
	head = malloc(sizeof(t_printf));
	if (!str || !format)
		return (0);
	va_start(ap, format);
	head->len = ft_vasprintf(&head->ret, format, ap);
	if (size == 0)
		return (head->len);
	else if (size - 1 == 0)
		str[0] = '\0';
	ft_strncpy(str, head->ret, size - 1);
	free(head->ret);
	va_end(ap);
	free(head);
	return (head->len);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list ap;
	t_printf *head;

	head = NULL;
	head = malloc(sizeof(t_printf));
	if (!format || !*format || fd < 0)
		return (0);
	va_start(ap, format);
	head->len = ft_vasprintf(&head->ret, format, ap);
	write(fd, head->ret, head->len);
	free(head->ret);
	va_end(ap);
	free(head);
	return (head->len);
}
