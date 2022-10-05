/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:25:51 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/05 20:08:06 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

/*
void	move_player(t_baram *baram, t_vector *offset, int direction)
{
	baram->player.direction = direction;
	if (baram->map.board[baram->player.y + offset[direction].vector_y]
		[baram->player.x + offset[direction].vector_x] != WALL)
	{
		baram->player.y += offset[direction].vector_y;
		baram->player.x += offset[direction].vector_x;
		if (baram->map.board[baram->player.y][baram->player.x] == COLLECT)
			baram->map.comp.collect--;
		if (baram->map.board[baram->player.y - offset[direction].vector_y]
			[baram->player.x - offset[direction].vector_x] != EXIT \
				&& baram->map.board[baram->player.y][baram->player.x] != EXIT)
		{
			baram->map.board[baram->player.y][baram->player.x] = EMPTY;
			baram->map.board[baram->player.y - offset[direction].vector_y]
			[baram->player.x - offset[direction].vector_x] = EMPTY;
		}
		baram->player.movement++;
		printf("movements : %d\n", baram->player.movement);
	}
	if (baram->map.comp.collect == 0 \
			&& baram->map.board[baram->player.y][baram->player.x] == EXIT)
		exit_success(baram);
}
*/

//void	move_player(t_baram *baram, int vector_y, int vector_x, int direction)
void	move_player(t_baram *baram, t_vector *offset, int direction)
{
	int	vector_y;
	int	vector_x;

	vector_y = offset[direction].vector_y;
	vector_x = offset[direction].vector_x;
	//baram->player.direction = direction;
	if (baram->map.board[baram->player.y + vector_y]
		[baram->player.x + vector_x] != WALL)
	{
		baram->player.y += vector_y;
		baram->player.x += vector_x;
		if (baram->map.board[baram->player.y][baram->player.x] == COLLECT)
			baram->map.comp.collect--;
		if (baram->map.board[baram->player.y - vector_y]
			[baram->player.x - vector_x] != EXIT \
				&& baram->map.board[baram->player.y][baram->player.x] != EXIT)
		{
			baram->map.board[baram->player.y][baram->player.x] = EMPTY;
			baram->map.board[baram->player.y - vector_y]
			[baram->player.x - vector_x] = EMPTY;
		}
		printf("movements : %d\n", ++baram->player.movement);
	}
	if (baram->map.comp.collect == 0 \
			&& baram->map.board[baram->player.y][baram->player.x] == EXIT)
		exit_success(baram);
}

int	press_key(int key_code, t_baram *baram)
{
	if (key_code == PRESS_ESC)
		exit_success(baram);
	else if (key_code == PRESS_W || key_code == PRESS_UP)
		move_player(baram, baram->player.preset, UP);
		//move_player(baram, baram->player.preset[UP].vector_y, baram->player.preset[UP].vector_x, UP);
	else if (key_code == PRESS_A || key_code == PRESS_LEFT)
		move_player(baram, baram->player.preset, LEFT);
		//move_player(baram, baram->player.preset[LEFT].vector_y, baram->player.preset[LEFT].vector_x, LEFT);
	else if (key_code == PRESS_S || key_code == PRESS_DOWN)
		move_player(baram, baram->player.preset, DOWN);
		//move_player(baram, baram->player.preset[DOWN].vector_y, baram->player.preset[DOWN].vector_x, DOWN);
	else if (key_code == PRESS_D || key_code == PRESS_RIGHT)
		move_player(baram, baram->player.preset, RIGHT);
		//move_player(baram, baram->player.preset[RIGHT].vector_y, baram->player.preset[RIGHT].vector_x, RIGHT);
	return (0);
}
