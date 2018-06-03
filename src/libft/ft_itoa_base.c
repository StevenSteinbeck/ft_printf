/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:17:37 by stestein          #+#    #+#             */
/*   Updated: 2018/05/31 14:15:26 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
# define END '\0';

char	*ft_itoa_base(int value, int base)
{
	unsigned int	i;
	int				size;
	char			*ret;
	int				value_check;

	value = (base != 10 && value < 0) ? -value : value;
	value_check = value;
	if (value != value_check)
		ft_isnan((double)value);
	i = (base == 10 && value < 0) ? -value : value;
	size = 1 + (base == 10 && value < 0);
	while ((i /= base))
		size++;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	ret[size] = END;
	i = (base == 10 && value < 0) ? -value : value;
	ret[--size] = "0123456789ABCDEF"[i % base];
	while ((i /= base))
		ret[--size] = "0123456789ABCDEF"[i % base];
	if ((base == 10) && value < 0)
		ret[--size] = '-';
	return (ret);
}
