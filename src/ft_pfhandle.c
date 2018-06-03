/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfhandle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:02:00 by stestein          #+#    #+#             */
/*   Updated: 2018/05/30 18:28:20 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

# define PREC_NUMS t_handl *head; head = malloc(sizeof(t_handl)); head->orig = *str;

void	ft_prec_nums(t_info *pfinfo, char **str)
{
	PREC_NUMS;
	if (pfinfo->prec == 0 && !ft_strcmp("0", *str))
	{
		**str = '\0';
		free(head);
		return ;
	}
	if (pfinfo->prec == -1)
		pfinfo->prec = 1;
	if ((size_t)pfinfo->prec < ft_strlen(*str))
	{
		free(head);
		return ;
	}
	head->extra = (!ISDIGIT((*str)[0]) && pfinfo->spec == 'd') ? (*str)[0] : 0;
	if (head->extra)
		(*str)++;
	head->new = ft_strnew(pfinfo->prec + !!head->extra);
	ft_memset(head->new + !!head->extra, '0', pfinfo->prec - ft_strlen(*str));
	ft_strcpy(head->new + pfinfo->prec - ft_strlen(*str) + !!head->extra, *str);
	if (head->extra)
		head->new[0] = head->extra;
	free(head->orig);
	*str = head->new;
	free(head);
}

void	ft_prec_handle(t_info *pfinfo, char **str)
{
	t_handl *head;

	head = malloc(sizeof(t_handl));
	head->number = -1;
	head->numb = -1;
	if (pfinfo->prec == head->number)
	{
		free(head);
		return ;
	}
	head->numb = ft_strlen(*str);
	if (head->numb <= (size_t)pfinfo->prec)
	{
		free(head);
		return ;
	}
	(*str)[pfinfo->prec] = '\0';
	free(head);
}

void	ft_right_just(t_info *pfinfo, char **str, char *new)
{
	t_handl *head;

	head = malloc(sizeof(t_handl));
	head->extra = 0;
	if (pfinfo->flags & ZER)
	{
		head->extra = (!ISDIGIT((*str)[0]) && pfinfo->spec == 'd') ? (*str)[0] : 0;
		ft_memset(new, '0', pfinfo->width - ft_strlen(*str) + !!head->extra);
		if (head->extra)
		{
			new[0] = head->extra;
			(*str)[0] = '0';
		}
	}
	else
	{
		ft_memset(new, ' ', pfinfo->width - ft_strlen(*str));
		if ((pfinfo->flags & POS) && **str != '-')
			new[pfinfo->width - ft_strlen(*str)] =
												((*str)[0] == '-') ? '-' : '+';
	}
	ft_strcpy(new + pfinfo->width - ft_strlen(*str) + !!head->extra, *str + !!head->extra);
	free(head);
}

void	ft_pad_handle(t_info *pfinfo, char **str)
{
	t_handl *head;

	head = malloc(sizeof(t_handl));
	if (pfinfo->width == 0 || ft_strlen(*str) >= (size_t)pfinfo->width)
	{
		free(head);
		return ;
	}
	head->new = ft_strnew(pfinfo->width);
	if (pfinfo->flags & LFT)
	{
		ft_strcpy(head->new, *str);
		ft_memset(head->new + ft_strlen(*str), ' ', pfinfo->width - ft_strlen(*str));
	}
	else
		ft_right_just(pfinfo, str, head->new);
	free(*str);
	*str = head->new;
	free(head);
	return ;
}
