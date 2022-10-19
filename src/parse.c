/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:30:29 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/19 10:02:46 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../include/so_long.h"
#include <sys/fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void	check_map_file(t_baram *baram)
{
	int	fd;
	int	tmp_width;

	if (!check_map_name(baram->map.path))
		exit_with_error_message("Invalid file name\n");
	fd = open(baram->map.path, O_RDONLY);
	if (fd == -1)
		exit_with_perror("Fail to open file");
	baram->map.width = get_width(fd);
	if (baram->map.width == -1)
		exit_with_error_message("File is empty\n");
	tmp_width = baram->map.width;
	while (tmp_width == baram->map.width)
	{
		baram->map.height++;
		tmp_width = get_width(fd);
	}
	close(fd);
	if (tmp_width != -1)
		exit_with_error_message("Invalid map size\n");
}

static int	get_map_board(t_baram *baram)
{
	int	fd;
	int	index;

	baram->map.board = malloc(sizeof(char *) * (baram->map.height + 1));
	if (baram->map.board == NULL)
		exit_with_perror("Fail to allocate board");
	fd = open(baram->map.path, O_RDONLY);
	if (fd == -1)
		exit_with_perror("Fail to open file");
	index = 0;
	while (index < baram->map.height)
	{
		baram->map.board[index] = get_next_line(fd);
		if (baram->map.board[index] == NULL)
			exit_with_perror("Fail to allocate board line");
		index++;
	}
	baram->map.board[index] = NULL;
	close(fd);
	return (1);
}

static int	check_valid_map(t_player *player, t_map *map)
{
	int	map_y;
	int	map_x;

	map_y = 0;
	while (map->board[map_y])
	{
		map_x = 0;
		while (map->board[map_y][map_x] != '\n')
		{
			if (map_y == 0 || map_y == map->height - 1 || \
					map_x == 0 || map_x == map->width - 1)
			{
				if (map->board[map_y][map_x] != WALL)
					exit_with_error_message("Invalid wall design\n");
			}
			else
				count_component(map_y, map_x, player, map);
			map_x++;
		}
		map_y++;
	}
	if (map->component.player > 1)
		exit_with_error_message("Too many player\n");
	return (map->component.player && map->component.collectible \
			&& map->component.exit);
}

int	parse_map(t_baram *baram)
{
	check_map_file(baram);
	get_map_board(baram);
	if (!check_valid_map(&baram->player, &baram->map))
		exit_with_error_message("No such essential component\n");
	return (1);
}
