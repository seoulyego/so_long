/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:10:34 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/04 10:46:08 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/get_next_line.h"

void	ft_lst_remove_if(t_buffer **lst, int fd)
{
	t_buffer	*tmp;
	t_buffer	*cur;

	if (*lst == NULL)
		return ;
	while (*lst != NULL && (*lst)->fd == fd)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	cur = *lst;
	while (cur != NULL)
	{
		if (cur->next != NULL && cur->next->fd == fd)
		{
			tmp = cur->next->next;
			free(cur->next);
			cur->next = tmp;
		}
		else
			cur = cur->next;
	}
	return ;
}

t_buffer	*get_node_or_null(t_buffer **lst, int fd)
{
	t_buffer	*cur;
	t_buffer	*new_node;

	cur = *lst;
	while (cur != NULL)
	{
		if (cur->fd == fd)
			return (cur);
		if (cur->next == NULL)
			break ;
		cur = cur->next;
	}
	new_node = ft_calloc(1, sizeof(t_buffer));
	if (new_node == NULL)
		return (NULL);
	new_node->fd = fd;
	if (*lst == NULL)
		*lst = new_node;
	else
		cur->next = new_node;
	return (new_node);
}

char	get_char(t_buffer *buf)
{
	if (buf->pos == buf->read_size)
	{
		buf->read_size = read(buf->fd, buf->buffer, BUFFER_SIZE);
		if (buf->read_size == -1)
			return (ERROR);
		buf->pos = 0;
	}
	return (buf->buffer[buf->pos++]);
}
