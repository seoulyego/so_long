/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:02:46 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/04 10:43:55 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*result;

	if (s1 == NULL)
		return (NULL);
	length = ft_strlen(s1);
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, length + 1);
	return (result);
}
