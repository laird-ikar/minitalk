/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 07:46:52 by bguyot            #+#    #+#             */
/*   Updated: 2022/03/09 07:58:03 by bguyot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcat(const void *mem1, const void *mem2, size_t len1, size_t len2)
{
	void	*res;
	void	*ptr;

	res = ft_calloc(len1 + len2, 1);
	if (!res)
		return (NULL);
	ptr = res;
	while (len1--)
		*(char *)(ptr++) = *(char *)(mem1++);
	while (len2--)
		*(char *)(ptr++) = *(char *)(mem2++);
	return (res);
}