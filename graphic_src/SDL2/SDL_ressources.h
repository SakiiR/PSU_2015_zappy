/*
** SDL_ressources.h for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL2
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Wed Jun 15 17:58:36 2016 Thomas Beaudet
** Last update Thu Jun 16 16:03:01 2016 Thomas Beaudet
*/

#ifndef _SDL_RESSOURCES_H_
# define _SDL_RESSOURCES_H_

#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct		s_res
{
  SDL_Window		*screen;
  SDL_Renderer		*rend;
  SDL_Event		event;

  // draw()
  SDL_Rect		rect;
  int			result;
  unsigned int		value;
  int			i;
  int			j;
}			t_res;

int			sdl_init();
void			draw_backg(t_res *ress);
void			put_delay(int delay);
int			Draw(t_res *ress);
int			sdl_create_win(t_res *ress, int x, int y);
int			sdl_event(t_res *ress);
void			sdl_quit();

#endif /* !_SDL_RESSOURCES_H_ */
