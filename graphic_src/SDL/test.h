/*
** test.h for zappy in /home/beaude_t/PSU_2015_zappy/graphic_src/SDL
**
** Made by Thomas Beaudet
** Login   <beaude_t@epitech.net>
**
** Started on  Wed Jun 15 10:42:09 2016 Thomas Beaudet
** Last update Wed Jun 15 14:44:56 2016 Thomas Beaudet
*/

#ifndef _TEST_H_
# define _TEST_H_

#define CASH_SIZE 5000;

typedef struct	s_proper
{
  SDL_Rect	rect;
}		t_proper;

typedef struct	s_display
{
  int		tile_w;
  int		tile_h;
  int		nb_tileX;
  int		nb_tileY;
  SDL_Surface	*tileset;
  t_proper	*props;
  tile_index	**schema;
  int		nb_tiles_world_w;
  int		nb_tiles_world_h;
}		t_display;

typedef struct	s_bct
{

}		t_bct;

SDL_Surface	*Load_image(const char *file_img);
#endif /* !_TEST_H_ */
