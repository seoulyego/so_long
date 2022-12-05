/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:56:53 by yeongo            #+#    #+#             */
/*   Updated: 2022/12/05 21:44:01 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"
#include "../libft/include/libft.h"
#include <stdlib.h>

static void	ft_free(char **ptr, int index_max)
{
	while (index_max >= 0)
	{
		free(ptr[index_max]);
		ptr[index_max] = NULL;
		index_max--;
	}
	free(ptr);
	ptr = NULL;
}

static int	is_in_bound(int height, int width, int y, int x)
{
	return (0 <= y && y < height
		&& 0 <= x && x < width);
}

static t_query	path_finder(t_baram *baram, char **visited_map, int y, int x)
{
	t_query		query;
	t_query		temp;
	t_vector	offset;
	int			direction;

	query.collectible_count = 0;
	query.exit_count = 0;
	if (!is_in_bound(baram->map.height, baram->map.width, y, x) \
		|| visited_map[y][x] || baram->map.board[y][x] == WALL)
		return (query);
	query.collectible_count += baram->map.board[y][x] == COLLECT;
	query.exit_count += baram->map.board[y][x] == EXIT;
	visited_map[y][x] = 1;
	direction = UP;
	while (direction <= RIGHT)
	{
		offset = baram->player.preset[direction];
		temp = path_finder
			(baram, visited_map, y + offset.vector_y, x + offset.vector_x);
		query.collectible_count += temp.collectible_count;
		query.exit_count += temp.exit_count;
		direction++;
	}
	return (query);
}

int	check_valid_path(t_baram *baram)
{
	t_query	query;
	char	**visited_map;
	int		index_y;

	visited_map = malloc(sizeof(char *) * baram->map.height);
	if (visited_map == NULL)
		exit_with_perror("Fail to allocate visited_map");
	index_y = 0;
	while (index_y < baram->map.height)
	{
		visited_map[index_y] = malloc(sizeof(char) * baram->map.width);
		if (visited_map[index_y] == NULL)
			exit_with_perror("Fail to allocate visited_map line");
		ft_memset(visited_map[index_y], 0, baram->map.width);
		index_y++;
	}
	query = path_finder(baram, visited_map, baram->player.y, baram->player.x);
	ft_free(visited_map, --index_y);
	return (baram->map.component.collectible == query.collectible_count \
		&& baram->map.component.exit == query.exit_count);
}
