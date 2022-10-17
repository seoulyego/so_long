/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:45:38 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/17 10:11:11 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_player_images(t_baram *baram)
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

void	init_sprite_images(t_baram *baram)
{
	ft_xpm_to_image
		(baram->mlx, &baram->player.sprite[NONE], "./img/spr_N.xpm");
	ft_xpm_to_image
		(baram->mlx, &baram->player.sprite[UP], "./img/spr_U.xpm");
	ft_xpm_to_image
		(baram->mlx, &baram->player.sprite[DOWN], "./img/spr_D.xpm");
	ft_xpm_to_image
		(baram->mlx, &baram->player.sprite[LEFT], "./img/spr_L.xpm");
	ft_xpm_to_image
		(baram->mlx, &baram->player.sprite[RIGHT], "./img/spr_R.xpm");
}
