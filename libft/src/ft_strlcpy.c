/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:15:39 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/04 10:44:31 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	index;

	src_len = ft_strlen(src);
	if (dstsize > 0)
	{
		index = 0;
		while (src[index] && index + 1 < dstsize)
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (src_len);
}
