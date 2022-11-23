/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:47:24 by yeongo            #+#    #+#             */
/*   Updated: 2022/11/23 23:08:55 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../include/so_long.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_baram	baram;

	if (ac != 2)
		exit_with_error_message("Invalid input\n");
	init_baram(&baram, av[1]);
	parse_map(&baram);
	ft_mlx_init(&baram.mlx);
	init_img_ptr(&baram);
	init_window(&baram);
	render_game(&baram);
	mlx_hook(baram.window, X_EVENT_KEY_PRESS, 0, press_key, &baram);
	mlx_hook(baram.window, X_EVENT_WIN_EXIT, 0, exit_success, &baram);
	mlx_loop_hook(baram.mlx, render_game, &baram);
	mlx_loop(baram.mlx);
	exit (0);
}
