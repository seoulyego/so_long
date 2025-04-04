/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:25:51 by yeongo            #+#    #+#             */
/*   Updated: 2022/11/01 10:17:52 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	modify_map_component(t_baram *baram, int vector_y, int vector_x)
{
	if (baram->map.board[baram->player.y][baram->player.x] == COLLECT)
		baram->map.component.collectible--;
	if (baram->map.board[baram->player.y - vector_y]
		[baram->player.x - vector_x] != EXIT \
		&& baram->map.board[baram->player.y][baram->player.x] != EXIT)
	{
		baram->map.board[baram->player.y][baram->player.x] = EMPTY;
		baram->map.board[baram->player.y - vector_y]
		[baram->player.x - vector_x] = EMPTY;
	}
}

static void	move_player(t_baram *baram, t_vector *offset, int direction)
{
	int	vector_y;
	int	vector_x;

	vector_y = offset[direction].vector_y;
	vector_x = offset[direction].vector_x;
	baram->player.direction = direction;
	baram->player.sprite_flag = 0;
	if (baram->map.board[baram->player.y + vector_y]
		[baram->player.x + vector_x] != WALL)
	{
		baram->player.move_flag = 1;
		baram->player.sprite_flag = 1;
		baram->player.y += vector_y;
		baram->player.x += vector_x;
		baram->player.movement++;
		modify_map_component(baram, vector_y, vector_x);
	}
	if (baram->map.component.collectible == 0 \
		&& baram->map.board[baram->player.y][baram->player.x] == EXIT)
		exit_success(baram);
}

int	press_key(int key_code, t_baram *baram)
{
	if (key_code == PRESS_ESC)
		exit_success(baram);
	else if (key_code == PRESS_W || key_code == PRESS_UP)
		move_player(baram, baram->player.preset, UP);
	else if (key_code == PRESS_S || key_code == PRESS_DOWN)
		move_player(baram, baram->player.preset, DOWN);
	else if (key_code == PRESS_A || key_code == PRESS_LEFT)
		move_player(baram, baram->player.preset, LEFT);
	else if (key_code == PRESS_D || key_code == PRESS_RIGHT)
		move_player(baram, baram->player.preset, RIGHT);
	return (0);
}

void	display_movement_count(t_baram *baram)
{
	ft_string_put(baram);
}
