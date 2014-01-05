/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrault <abrault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 17:11:12 by abrault           #+#    #+#             */
/*   Updated: 2014/01/05 17:12:21 by abrault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_head.h"

void	mlx_destroy_image(t_img *img)
{
	if (img)
	{
		shmdt(img->data);
		shmctl(img->shm.shmid,IPC_RMID,0);
		XDestroyImage(img->image);
		free(img);
	}
}
