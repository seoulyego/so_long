/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_component.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:34:25 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/17 10:34:32 by yeongo           ###   ########.fr       */
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
			(baram->mlx, baram->window, baram->img.exit, x * 64, y * 64);
}

void	render_player(t_baram *baram)
{
	mlx_put_image_to_window
		(baram->mlx, baram->window, baram->player.img, \
		baram->player.x * 64, baram->player.y * 64);
}
