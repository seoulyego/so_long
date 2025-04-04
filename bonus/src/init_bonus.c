/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:31:50 by yeongo            #+#    #+#             */
/*   Updated: 2022/11/01 10:47:22 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/include/libft.h"
#include "../include/so_long_bonus.h"

static void	set_move_preset(t_vector preset[5])
{
	preset[NONE].vector_y = 0;
	preset[NONE].vector_x = 0;
	preset[UP].vector_y = -1;
	preset[UP].vector_x = 0;
	preset[DOWN].vector_y = 1;
	preset[DOWN].vector_x = 0;
	preset[LEFT].vector_y = 0;
	preset[LEFT].vector_x = -1;
	preset[RIGHT].vector_y = 0;
	preset[RIGHT].vector_x = 1;
}

void	init_baram(t_baram *baram, char *map_path)
{
	ft_memset(baram, 0, sizeof(t_baram));
	baram->map.path = map_path;
	set_move_preset(baram->player.preset);
}

static void	init_player_images(t_baram *baram)
{
	ft_xpm_to_image
		(baram->mlx, &baram->player.img[NONE], "./img/P_South.xpm");
	ft_xpm_to_image
		(baram->mlx, &baram->player.img[UP], "./img/P_North.xpm");
	ft_xpm_to_image
		(baram->mlx, &baram->player.img[DOWN], "./img/P_South.xpm");
	ft_xpm_to_image
		(baram->mlx, &baram->player.img[LEFT], "./img/P_West.xpm");
	ft_xpm_to_image
		(baram->mlx, &baram->player.img[RIGHT], "./img/P_East.xpm");
}

void	init_img_ptr(t_baram *baram)
{
	ft_xpm_to_image
		(baram->mlx, &baram->img.empty, "./img/0.xpm");
	ft_xpm_to_image
		(baram->mlx, &baram->img.wall, "./img/1.xpm");
	ft_xpm_to_image
		(baram->mlx, &baram->img.collect, "./img/C.xpm");
	ft_xpm_to_image
		(baram->mlx, &baram->img.exit, "./img/E.xpm");
	init_player_images(baram);
}

void	init_window(t_baram *baram)
{
	int	window_width;
	int	window_height;

	window_width = baram->map.width * 64;
	window_height = baram->map.height * 64;
	if (window_width > MAX_WINDOW_WIDTH || window_height > MAX_WINDOW_HEIGHT)
		exit_with_error_message("Map is too large\n");
	ft_new_window(baram->mlx, &baram->window, window_width, window_height);
}
