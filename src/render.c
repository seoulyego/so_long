/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:32:25 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/17 10:49:12 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

static int	set_index(int *max_idx, int min_std, int max_std, int movement)
{
	int	min_idx;

	if (movement == 0)
	{
		*max_idx = max_std;
		return (0);
	}
	min_idx = min_std - 3;
	if (min_idx < 0)
		min_idx = 0;
	*max_idx = min_std + 3;
	if (*max_idx > max_std)
		*max_idx = max_std;
	return (min_idx);
}

int	render_game(t_baram *baram)
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
	render_player(baram);
	return (0);
}
