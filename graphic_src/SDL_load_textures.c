/*
** SDL_load_textures.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Tue Jun 21 12:17:09 2016 Thomas Beaudet
** Last update Tue Jun 21 16:31:15 2016 Thomas Billot
*/

#include "graphical.h"

SDL_Surface			*load_bmp(const char *file)
{
  SDL_Surface			*bmp;

  if ((bmp = SDL_LoadBMP(file)) == NULL)
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

int				display_texture(t_render *ress, t_texture *tile, int x, int y)
{
  if (ress->rend)
    {
      ress->dest_rect.x = x - tile->bmp->w / 2;
      ress->dest_rect.y = y - tile->bmp->h / 2;
      ress->dest_rect.w = tile->bmp->w;
      ress->dest_rect.h = tile->bmp->h;
      SDL_RenderCopy(ress->rend, tile->texture, NULL, &ress->dest_rect);
      SDL_RenderPresent(ress->rend);
    }
  else if (!ress->rend)
    {
      fprintf(stderr,
	      "Problem encountered while finding renderer -> SDL Error : %s\n",
	      SDL_GetError());
      return (-1);
    }
  return (0);
}
