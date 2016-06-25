/*
** preload_textures.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Tue Jun 21 12:59:05 2016 Thomas Billot
** Last update Sat Jun 25 10:33:25 2016 Thomas Beaudet
*/

#include "graphical.h"

static char	*g_textures[] =
  {
    T_GRASS,
    T_BORDER_DARK,
    T_BORDER_LIGHT,
    T_CHARACTER,
    T_FOOD,
    T_LINEMATE,
    T_DERAUMERE,
    T_MENDIANE,
    T_PHIRAS,
    T_SIBUR,
    T_THYSTAME,
    T_EGG
  };

int		preload_textures(t_render *ress)
{
  int		i;

  i = -1;
  while (++i < NUMBER_OF_TEXTURES)
    {
      if ((ress->tileset[i].bmp = load_bmp(g_textures[i])) != NULL)
	printf("Loaded bmp: %s\n", g_textures[i]);
      else
	return (RETURN_FAILURE);
      if ((ress->tileset[i].texture = create_texture(ress,
							  ress->tileset[i].bmp)) != NULL)
	printf("Loaded texture for: %s\n", g_textures[i]);
      else
	return (RETURN_FAILURE);
    }
  printf("\nSuccessfully loaded textures\n");
  return (RETURN_SUCCESS);
}
