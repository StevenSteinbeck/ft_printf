/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:09:09 by stestein          #+#    #+#             */
/*   Updated: 2018/05/29 17:36:23 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_unicode_conv(wchar_t chr, char *str)
{
	t_chr	*head;

	head = malloc(sizeof(t_chr));
	head->chr = chr;
	head->str = str;
	if (head->chr < (MB_CUR_MAX == 1 ? 0xFF : 0x7F))
				head->str[0] = (unsigned char)head->chr;
	else if (head->chr < (1 << 11))
	{
		head->str[0] = (unsigned char)((head->chr >> 6) | 0xC0);
		head->str[1] = (unsigned char)((head->chr & 0x3F) | 0x80);
	}
	else if (head->chr < (1 << 16))
	{
		head->str[0] = (unsigned char)(((head->chr >> 12)) | 0xE0);
		head->str[1] = (unsigned char)(((head->chr >> 6) & 0x3F) | 0x80);
		head->str[2] = (unsigned char)((head->chr & 0x3F) | 0x80);
	}
	else if (head->chr < (1 << 21))
	{
		head->str[0] = (unsigned char)(((head->chr >> 18)) | 0xF0);
		head->str[1] = (unsigned char)(((head->chr >> 12) & 0x3F) | 0x80);
		head->str[2] = (unsigned char)(((head->chr >> 6) & 0x3F) | 0x80);
		head->str[3] = (unsigned char)((head->chr & 0x3F) | 0x80);
	}
	free(head);
}

int		ft_unicode_b(wchar_t chr)
{
	t_chr	*head;

	head = malloc(sizeof(t_chr));
	head->chr = chr;
	if (head->chr < (1 << 7))
	{
		free(head);
		return (1);
	}
	else if (head->chr < (1 << 11))
	{
		free(head);
		return (2);
	}
	else if (head->chr < (1 << 16))
	{
		free(head);
		return (3);
	}
	else if (head->chr < (1 << 21))
	{
		free(head);
		return (4);
	}
	free(head);
	return (0);
}

int		ft_handle_wchar(char **str, va_list ap)
{
	t_chr *head;

	head = malloc(sizeof(t_chr));
	head->chr = va_arg(ap, wchar_t);
	head->len = ft_unicode_b(head->chr);
	*str = ft_strnew(head->len);
	ft_unicode_conv(head->chr, *str);
	free(head);
	return (head->chr == '\0');
}

void	ft_null_chr(t_vector *vector, char *str)
{
	t_chr *head;

	head = malloc(sizeof(t_printf));
	head->i = -1;
	head->len = ft_strlen(str);
	while (++head->i < head->len)
		if (str[head->i] == 1)
			str[head->i] = 0;
	ft_vector_nappend(vector, str, head->len);
	free(head);
}

void	ft_chr_conv(t_vector *vector, t_info *pfinfo, va_list ap)
{
	char		*str;
	t_chr	*head;

	head = NULL;
	head = malloc(sizeof(t_chr));
	if (pfinfo->spec == 'C' || pfinfo->length == l)
	{
		head->null = ft_handle_wchar(&str, ap);
		if (head->null)
			str[0] = head->null;
	}
	else
	{
		head->chr = va_arg(ap, int);
		str = ft_strnew(1);
		head->null = (head->chr == '\0') ? 1 : 0;
		str[0] = head->chr + head->null;
	}
	ft_pad_handle(pfinfo, &str);
	if (head->null)
		ft_null_chr(vector, str);
	else
		ft_vector_append(vector, str);
	free(str);
	free(head);
}
