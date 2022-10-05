/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:49:19 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/05 16:37:52 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../include/so_long.h"
#include <stdlib.h>

int	check_map_name(char *map_path)
{
	const int	start = ft_strlen(map_path) - 4;

	if (start > 0)
		if (ft_strncmp(&map_path[start], FILE_EXT, 5) == 0)
			return (1);
	return (0);
}

int	get_width(int fd)
{
	char	*tmp_line;
	int		line_len;

	tmp_line = get_next_line(fd);
	line_len = ft_strlen(tmp_line) - 1;
	free(tmp_line);
	return (line_len);
}

void	count_component(int map_y, int map_x, t_player *player, t_map *map)
{
	if (map->board[map_y][map_x] == EMPTY || map->board[map_y][map_x] == WALL)
		return ;
	else if (map->board[map_y][map_x] == PLAYER)
	{
		if (map->comp.player++ == 0)
		{
			player->x = map_x;
			player->y = map_y;
		}
		map->board[map_y][map_x] = EMPTY;
	}
	else if (map->board[map_y][map_x] == COLLECT)
		map->comp.collect++;
	else if (map->board[map_y][map_x] == EXIT)
		map->comp.exit++;
	else
		exit_with_error_message("Invalid map component\n");
}
