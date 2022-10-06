/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeongo <yeongo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:29:57 by yeongo            #+#    #+#             */
/*   Updated: 2022/10/06 21:25:23 by yeongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/include/libft.h"
#include "../../mlx/mlx.h"
#include "../include/so_long_bonus.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	exit_with_error_message(char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	exit(1);
}

void	exit_with_perror(char *str)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	perror(str);
	exit(1);
}

int	exit_success(t_baram *baram)
{
	mlx_destroy_window(baram->mlx, baram->window);
	if (baram->player.movement == 0)
		printf("movement : 0");
	printf("\n");
	exit(0);
}
