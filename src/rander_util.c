/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rander_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:40:28 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/05 23:41:09 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"

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
