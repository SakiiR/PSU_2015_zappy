/*
** SDL_load_textures.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Tue Jun 21 12:17:09 2016 Thomas Beaudet
** Last update Sat Jun 25 17:32:16 2016 Thomas Billot
*/

#include "graphical.h"

SDL_Surface			*load_bmp(const char *file)
{
  SDL_Surface			*bmp;

  if ((bmp = IMG_Load(file)) == NULL)
    {
      fprintf(stderr,
              "Problem encountered while loading bmp -> SDL Error : %s\n",
              SDL_GetError());
      return (NULL);
    }
  return (bmp);
}

SDL_Texture			*create_texture(t_render *ress, SDL_Surface *bmp)
{
  SDL_Texture			*texture;

  if ((texture = SDL_CreateTextureFromSurface(ress->rend, bmp)) == NULL)
    {
      fprintf(stderr,
	      "Problem encountered while creating texture -> SDL Error : %s\n",
	      SDL_GetError());
      return (NULL);
    }
  return (texture);
}

int				display_texture(t_render *ress,
						t_texture *tile,
						int x,
						int y)
{
  if (ress->rend)
    {
      ress->dest_rect.x = x;
      ress->dest_rect.y = y;
      ress->dest_rect.w = TILE_W;
      ress->dest_rect.h = TILE_H;
      SDL_RenderCopy(ress->rend, tile->texture, NULL, &ress->dest_rect);
    }
  else if (!ress->rend)
    {
      fprintf(stderr,
	      "Problem encountered while finding renderer -> SDL Error : %s\n",
	      SDL_GetError());
      return (RETURN_FAILURE);
    }
  return (RETURN_SUCCESS);
}
