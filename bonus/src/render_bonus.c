/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:32:25 by yeongo            #+#    #+#             */
/*   Updated: 2022/11/03 09:42:35 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	set_index(int *max_idx, int min_std, int max_std, int movement)
{
	int	min_idx;

	if (movement == 0)
	{
		*max_idx = max_std;
		return (0);
	}
	min_idx = min_std - RENDER_MARGINE;
	if (min_idx < 0)
		min_idx = 0;
	*max_idx = min_std + RENDER_MARGINE;
	if (*max_idx > max_std)
		*max_idx = max_std;
	return (min_idx);
}

int	render_game(t_baram *baram, void (*render_character)(t_baram *, int))
{
	int	index_y;
	int	index_x;
	int	max_y;
	int	max_x;

	index_y = set_index
		(&max_y, baram->player.y, baram->map.height, baram->player.movement);
	while (index_y < max_y)
	{
		index_x = set_index
			(&max_x, baram->player.x, baram->map.width, baram->player.movement);
		while (index_x < max_x)
		{
			render_map(baram, index_y, index_x);
			index_x++;
		}
		index_y++;
	}
	render_character(baram, baram->player.direction);
	display_movement_count(baram);
	return (0);
}

int	render_movement(t_baram *baram)
{
	static int	frame;

	if (++frame > MAX_FRAME)
		frame = 0;
	if (baram->player.move_flag == 1 && frame == MAX_FRAME)
		baram->player.move_flag = 0;
	if (baram->player.move_flag == 0)
		render_game(baram, render_player);
	else
		render_game(baram, render_sprite);
	return (0);
}
