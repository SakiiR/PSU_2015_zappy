/*
** map.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Jun  7 16:52:50 2016 Barthelemy Gouby
** Last update Sun Jun 26 15:10:17 2016 Erwan Dupard
*/

#include <time.h>
#include <stdlib.h>
#include "server.h"

int					initialize_map(t_map *map)
{
  t_case				*cases;
  int					i;

  i = -1;
  printf("[^] Creating Map.\n");
  if ((cases = malloc(sizeof(*cases) * map->width * map->height)) == NULL)
    return (RETURN_FAILURE);
  while (++i < (int)(map->width * map->height))
    {
      cases[i].characters = NULL;
      cases[i].quantities[NOURRITURE] = 0;
      cases[i].quantities[LINEMATE] = 0;
      cases[i].quantities[DERAUMERE] = 0;
      cases[i].quantities[SIBUR] = 0;
      cases[i].quantities[MENDIANE] = 0;
      cases[i].quantities[PHIRAS] = 0;
      cases[i].quantities[THYSTAME] = 0;
      cases[i].x = i % map->width;
      cases[i].y = i / map->width;
    }
  map->cases = cases;
  return (RETURN_SUCCESS);
}

t_case					*map_get_case_circular(int x,
							       int y,
							       t_map *map)
{
  if (x >= (int) map->width)
    x = 0;
  else if (x < 0)
    x = map->width - 1;
  if (y >= (int) map->height)
    y = 0;
  else if (y < 0)
    y = map->height - 1;
  return (&map->cases[y * map->width + x]);
}

t_case					*map_get_case_at(const t_u64 x,
							 const t_u64 y,
							 const t_map *map)
{
  int					index;
  t_case				*c;

  index = y * map->width + x;
  c = (index >= map->height * map->width ? NULL : &map->cases[index]);
  return (c);
}

void					spread_ressource(const e_ressource_type type,
							 t_u64 quantity,
							 t_map *map)
{
  while (quantity > 0)
    {
      map->cases[rand() % (map->width * map->height)].quantities[type]++;
      quantity--;
    }
}

void					initialize_ressources(t_server *server)
{
  t_u64					nbr_of_teams;
  t_map					*map;
  t_u64					width;
  t_u64					height;

  width = server->game_data.map.width;
  height = server->game_data.map.height;
  nbr_of_teams = server->game_data.nbr_of_teams;
  map = &server->game_data.map;
  srand(time(NULL));
  spread_ressource(NOURRITURE, nbr_of_teams * (width * height / 50) * 50, map);
  spread_ressource(LINEMATE, nbr_of_teams * (width * height / 50) * 6, map);
  spread_ressource(DERAUMERE, nbr_of_teams * (width * height / 50) * 5, map);
  spread_ressource(SIBUR, nbr_of_teams * (width * height / 50) * 4 , map);
  spread_ressource(MENDIANE, nbr_of_teams * (width * height / 50) * 3, map);
  spread_ressource(PHIRAS, nbr_of_teams * (width * height / 50) * 2, map);
  spread_ressource(THYSTAME, nbr_of_teams * (width * height / 50), map);
}
