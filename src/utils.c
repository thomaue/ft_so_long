/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:14:57 by tauer             #+#    #+#             */
/*   Updated: 2024/03/25 22:58:39 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	delete_emptyness(t_data *data, char **map)
{
	int	x;
	int	y;

	x = 0;
	if (!data->map)
		return ;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '0')
				data->map[x][y] = 'X';
			y++;
		}
		x++;
	}
}

void	security(t_data *data)
{
	if (data->move >= __LONG_LONG_MAX__ || data->x >= __INT_MAX__
		|| data->y >= __INT_MAX__ || data->mov_chunk_x >= __INT_MAX__
		|| data->mov_chunk_y >= __INT_MAX__)
	{
		ft_printf("[security] : variable out of range\n");
		close_win(data);
	}
}
