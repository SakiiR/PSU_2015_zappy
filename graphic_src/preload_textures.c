/*
** preload_textures.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Tue Jun 21 12:59:05 2016 Thomas Billot
** Last update Tue Jun 21 13:26:46 2016 Thomas Billot
*/

#include "graphical.h"

static char	*g_textures[] =
  {
    T_GRASS,
    T_BORDER_DARK,
    T_BORDER_LIGHT
  }; 

int		preload_textures(t_map *map)
{
  int		i;

  i = -1;
  while (++i < NUMBER_OF_TEXTURES)
    {
      if ((map->textures[i] = load_bmp(g_textures[i])) != NULL)
	printf("Loaded texture: %s\n", g_textures[i]);
    }
  printf("Successfully loaded textures\n");
  return (0);
}
