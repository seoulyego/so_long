/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:38:37 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/20 09:42:29 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx/mlx.h"
#include "../include/so_long_bonus.h"
#include "../../libft/include/libft.h"
#include <stdlib.h>

void	ft_mlx_init(void **mlx_ptr)
{
	*mlx_ptr = mlx_init();
	if (*mlx_ptr == NULL)
		exit_with_error_message("Fail to mlx_init\n");
}

void	ft_new_window(void *mlx_ptr, void **window, int size_x, int size_y)
{
	*window = mlx_new_window(mlx_ptr, size_x, size_y, P_NAME);
	if (*window == NULL)
		exit_with_error_message("Fail to mlx_new_window\n");
}

void	ft_xpm_to_image(void *mlx_ptr, void **img_ptr, char *img_path)
{
	int	width;
	int	height;

	*img_ptr = mlx_xpm_file_to_image(mlx_ptr, img_path, &width, &height);
	if (*img_ptr == NULL)
		exit_with_error_message("Fail to mlx_xpm_file_to_image\n");
}

void	ft_string_put(t_baram *baram)
{
	char	*string;

	string = ft_itoa(baram->player.movement);
	mlx_string_put(baram->mlx, baram->window, baram->player.x * 64 + 48, \
			baram->player.y * 64 + 64, 0x00ffffff, string);
	free(string);
}
