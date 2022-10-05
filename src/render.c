/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:32:25 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/05 23:36:03 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

void	render_map(t_baram *baram, int y, int x)
{
	mlx_put_image_to_window
		(baram->mlx, baram->window, baram->img.empty, x * 64, y * 64);
	if (baram->map.board[y][x] == WALL)
		mlx_put_image_to_window
			(baram->mlx, baram->window, baram->img.wall, x * 64, y * 64);
	else if (baram->map.board[y][x] == COLLECT)
		mlx_put_image_to_window
			(baram->mlx, baram->window, baram->img.collect, x * 64, y * 64);
	else if (baram->map.board[y][x] == EXIT)
		mlx_put_image_to_window
			(baram->mlx, baram->window, *baram->img.exit, x * 64, y * 64);
}

void	render_player(t_baram *baram)
{
	mlx_put_image_to_window
		(baram->mlx, baram->window, baram->player.img, \
		baram->player.x * 64, baram->player.y * 64);
}

int	render_game(t_baram *baram)
{
	int	y;
	int	x;

	y = 0;
	while (y < baram->map.height)
	{
		x = 0;
		while (x < baram->map.width)
		{
			render_map(baram, y, x);
			render_player(baram);
			x++;
		}
		y++;
	}
	return (0);
}

void	change_exit_img(t_baram *baram)
{
	int	index_y;
	int	index_x;

	baram->img.exit = &baram->img.exit_open;
	index_y = 0;
	while (index_y < baram->map.height)
	{
		index_x = 0;
		while (index_x < baram->map.width)
		{
			if (baram->map.board[index_y][index_x] == EXIT)
				mlx_put_image_to_window
					(baram->mlx, baram->window, *baram->img.exit, \
					index_x * 64, index_y * 64);
			index_x++;
		}
		index_y++;
	}
}

int	set_index_range(int *max_index, int min_std, int max_std, int range)
{
	int	min_index;

	min_index = min_std - range;
	if (min_index < 0)
		min_index = 0;
	*max_index = min_std + range;
	if (*max_index > max_std)
		*max_index = max_std;
	return (min_index);
}

int	render_change(t_baram *baram)
{
	int	index_y;
	int	index_x;
	int	max_y;
	int	max_x;

	index_y = set_index_range(&max_y, baram->player.y, baram->map.height, 3);
	while (index_y < max_y)
	{
		index_x = set_index_range(&max_x, baram->player.x, baram->map.width, 3);
		while (index_x < max_x)
		{
			render_map(baram, index_y, index_x);
			index_x++;
		}
		index_y++;
	}
	render_player(baram);
	if (baram->map.comp.collect == 0 \
			&& *baram->img.exit == baram->img.exit_close)
		change_exit_img(baram);
	return (0);
}
