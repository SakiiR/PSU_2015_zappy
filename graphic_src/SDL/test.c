/*
** test.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Wed Jun 15 10:42:41 2016 Thomas Beaudet
** Last update Wed Jun 15 14:51:29 2016 Thomas Beaudet
*/

#include <>
#include <>
#include <>
#include <>
#include "../graphical.h"

SDL_Surface		*Load_image(const char *file_img)
{
  SDL_Surface		*final_img;
  SDL_Surface		*img_ram;

  if ((img_ram = SDL_LoadIMG(file_img)) == NULL)
    {
      fprintf(stderr, "Problem ecountered while setting video mode : %s\n",
	      SDL_GetError());
      exit (EXIT_FAILURE);
    }
  file_img = SDL_DisplayFormat(img_ram);
  SDL_FreeSurface(img_ram);
  return (img_ram);
}

int			Free_Map(t_map *m)
{
  int			i;

  i = 0;
  SDL_FreeSurface(m->tileset);
  for(i = 0; i < m->nb_tiles_world_h; i++)
    free(m->schema[i]);
  free(m->schema);
  free(m->props);
  free(m);
  return 0;
}

int			Display_Map(t_map *m)
{
  int			i;
  int			j;
  SDL_Rect		dest_rect;
  int			tile_num;

  for(i = 0; i < m->nb_tiles_world_w; i++)
    {
      for(j = 0; j < m->nb_tiles_world_h; j++)
	{
	  dest_rect.x = i * m->tile_w;
	  dest_rect.y = j * m->tile_h;
	  tile_num = m->schema[i][j];
	  SDL_BlitSurface(m->tileset, &(m->props[tile_num].rect), screen, &dest_rect);
	}
    }
  return 0;
}
