/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_component_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:16:42 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/17 10:21:03 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx/mlx.h"
#include "../include/so_long_bonus.h"

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
			(baram->mlx, baram->window, baram->img.exit, x * 64, y * 64);
}

void	render_sprite(t_baram *baram, int direction)
{
	if (direction == UP)
		mlx_put_image_to_window
			(baram->mlx, baram->window, baram->player.img[direction], \
				baram->player.x * 64, baram->player.y * 64 + 32);
	else if (direction == DOWN)
		mlx_put_image_to_window
			(baram->mlx, baram->window, baram->player.img[direction], \
				baram->player.x * 64, baram->player.y * 64 - 32);
	else if (direction == LEFT)
		mlx_put_image_to_window
			(baram->mlx, baram->window, baram->player.img[direction], \
				baram->player.x * 64 + 32, baram->player.y * 64);
	else if (direction == RIGHT)
		mlx_put_image_to_window
			(baram->mlx, baram->window, baram->player.img[direction], \
				baram->player.x * 64 - 32, baram->player.y * 64);
}

void	render_player(t_baram *baram, int direction)
{
	mlx_put_image_to_window
		(baram->mlx, baram->window, baram->player.img[direction], \
		baram->player.x * 64, baram->player.y * 64);
}
