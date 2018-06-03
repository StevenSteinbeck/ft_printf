/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 18:28:38 by stestein          #+#    #+#             */
/*   Updated: 2018/06/03 12:27:39 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_null_str(t_info *pfinfo)
{
	t_str	head;

	if (pfinfo->prec >= 1 || pfinfo->prec == -1)
	{
		head.tmp = ft_strdup("(null)");
		if (pfinfo->prec > 6)
			head.tmp[6] = '\0';
		else
			head.tmp[(pfinfo->prec == -1) ? 6 : pfinfo->prec] = '\0';
	}
	else
		head.tmp = ft_strdup("");
	return (head.tmp);
}

void	ft_str_conv(t_vector *vector, t_info *pfinfo, va_list ap)
{
	t_str	head;

	if (pfinfo->length == l)
	{
		ft_wstr_conv(vector, pfinfo, ap);
		free(head);
		return ;
	}
	head.ctmp = va_arg(ap, char *);
	if (!head.ctmp)
		head.s = ft_null_str(pfinfo);
	else
		head.s = ft_strdup(head.ctmp);
	ft_prec_handle(pfinfo, &head.s);
	ft_pad_handle(pfinfo, &head.s);
	ft_vector_append(vector, head.s);
	free(head.s);
}
