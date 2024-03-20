/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_custom_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:40:05 by tauer             #+#    #+#             */
/*   Updated: 2024/03/20 16:01:39 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	custom_indoor_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x <= data->size_x)
	{
		y = 0;
		while (y <= data->size_y)
		{
			if (data->map[x][y] == 'E')
			{
				data->e_x = x;
				data->e_y = y;
			}
			else if (data->map[x][y] == 'D')
				data->map[x][y] = 'D';
			else if (check_walls(data, x, y) && check_walls(data, x + 1, y)
				&& check_walls(data, x - 1, y) && check_walls(data, x, y - 1)
				&& check_walls(data, x, y + 1))
				data->map[x][y] = 'e';
			else if (check_walls(data, x, y) && check_walls(data, x - 1, y)
				&& check_walls(data, x, y - 1) && check_walls(data, x, y + 1))
				data->map[x][y] = 'f';
			else if (check_walls(data, x, y) && check_walls(data, x + 1, y)
				&& check_walls(data, x, y - 1) && check_walls(data, x, y + 1))
				data->map[x][y] = 'b';
			else if (check_walls(data, x, y) && check_walls(data, x + 1, y)
				&& check_walls(data, x - 1, y) && check_walls(data, x, y + 1))
				data->map[x][y] = 'p';
			else if (check_walls(data, x, y) && check_walls(data, x + 1, y)
				&& check_walls(data, x - 1, y) && check_walls(data, x, y - 1))
				data->map[x][y] = 'q';
			else if (check_walls(data, x, y) && check_walls(data, x, y - 1)
				&& check_walls(data, x, y + 1))
			{
				if (data->selecter_custom > 4)
					data->selecter_custom = 0;
				if (data->selecter_custom == 0 && check_empty(data, x + 1, y))
					data->map[x][y] = 'y';
				else if (data->selecter_custom == 1 && check_empty(data, x + 1,
						y))
					data->map[x][y] = 'x';
				else if (data->selecter_custom == 2 && (check_void(data, x + 1,
							y) || x == data->size_x))
					data->map[x][y] = 't';
				else if (data->selecter_custom == 3 && ((check_void(data, x + 1,
								y) && check_empty(data, x - 1, y))
						|| x == data->size_x))
					data->map[x][y] = 's';
				else if (data->selecter_custom == 4 && (check_void(data, x + 1,
							y) || x == data->size_x))
					data->map[x][y] = 'r';
				else
					data->map[x][y] = '1';
				data->selecter_custom++;
			}
			else if (check_walls(data, x, y) && check_walls(data, x - 1, y)
				&& check_walls(data, x, y + 1))
				data->map[x][y] = 'l';
			else if (check_walls(data, x, y) && check_walls(data, x - 1, y)
				&& check_walls(data, x, y - 1))
				data->map[x][y] = 'm';
			else if (check_walls(data, x, y) && check_walls(data, x + 1, y)
				&& check_walls(data, x, y + 1))
				data->map[x][y] = 'j';
			else if (check_walls(data, x, y) && check_walls(data, x - 1, y)
				&& check_walls(data, x + 1, y))
				data->map[x][y] = 'n';
			else if (check_walls(data, x, y) && check_walls(data, x + 1, y)
				&& check_walls(data, x, y - 1))
				data->map[x][y] = 'o';
			else if (check_walls(data, x, y) && check_walls(data, x - 1, y))
				data->map[x][y] = 'c';
			else if (check_walls(data, x, y) && check_walls(data, x + 1, y))
				data->map[x][y] = 'd';
			else if (check_walls(data, x, y) && check_walls(data, x, y + 1))
				data->map[x][y] = 'g';
			else if (check_walls(data, x, y) && check_walls(data, x, y - 1))
				data->map[x][y] = 'h';
			y++;
		}
		x++;
	}
	return (0);
}

void	choose_toward_wall(t_data *data, int x, int y)
{
	if (check_walls(data, x, y + 1) && check_walls(data, x, y - 1))
		put_img_to_img(data->base_image, data->textures.down, x * 50, y * 50);
	if ((check_empty(data, x, y + 1) || check_walls(data, x, y + 1)
			|| check_char(data, x, y + 1, 'D')) && (!check_empty(data, x, y - 1)
			|| !check_walls(data, x, y - 1)))
	{
		put_img_to_img(data->base_image, data->textures.empty, x * 50, y * 50);
		put_img_to_img(data->base_image, data->textures.toward_wall_left_empty,
			x * 50, y * 50);
	}
	if ((check_empty(data, x, y - 1) || check_walls(data, x, y - 1)
			|| check_char(data, x, y - 1, 'D')) && (!check_empty(data, x, y + 1)
			|| !check_walls(data, x, y + 1)))
	{
		put_img_to_img(data->base_image, data->textures.empty, x * 50, y * 50);
		put_img_to_img(data->base_image, data->textures.toward_wall_right_empty,
			x * 50, y * 50);
	}
	if (check_char(data, x, y + 1, 'X') && check_char(data, x, y - 1, 'X'))
	{
		put_img_to_img(data->base_image, data->textures.empty, x * 50, y * 50);
		put_img_to_img(data->base_image, data->textures.toward_wall, x * 50, y
			* 50);
	}
	if ((check_empty(data, x, y + 1) || check_walls(data, x, y + 1))
		&& ((check_empty(data, x, y - 1)) || check_walls(data, x, y - 1)))
	{
		put_img_to_img(data->base_image, data->textures.floor, x * 50, y * 50);
		put_img_to_img(data->base_image, data->textures.toward_wall, x * 50, y
			* 50);
	}
}
