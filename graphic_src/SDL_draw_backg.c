/*
** SDL_draw_backg.c for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Wed Jun 15 18:31:27 2016 Thomas Beaudet
** Last update Sun Jun 26 20:53:18 2016 Thomas Billot
*/

#include <stdio.h>
#include "graphical.h"

int			draw_backg(t_render *ress)
{
  SDL_Surface		*backg;
  SDL_Texture		*backg_texture;

  if ((backg = load_bmp("graphic_src/Media/landscape.png")) == NULL)
    return (RETURN_FAILURE);
  if ((backg_texture = create_texture(ress, backg)) == NULL)
    return (RETURN_FAILURE);
  SDL_RenderCopy(ress->rend, backg_texture, NULL, NULL);
  return (RETURN_SUCCESS);
}

int			clear_surface(t_render *ress)
{
  if ((SDL_RenderClear(ress->rend)) < 0)
    {
      fprintf(stderr,
	      "Problem encountered while clearing renderer -> SDL Error : %s\n",
	      SDL_GetError());
      SDL_Quit();
      return (RETURN_FAILURE);
    }
  return (RETURN_SUCCESS);
}

void			put_delay(int delay)
{
  SDL_Delay(delay);
}
