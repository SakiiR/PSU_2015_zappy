/*
** map.c for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Jun  7 16:52:50 2016 Barthelemy Gouby
** Last update Fri Jun 17 14:05:14 2016 Barthelemy Gouby
*/

#include <time.h>
#include <stdlib.h>
#include "server.h"

int					initialize_map(t_map *map)
{
  t_case				*cases;
  t_u64					i;

  i = 0;
  if (!(cases = malloc(sizeof(*cases) * map->width * map->height)))
    return (RETURN_FAILURE);
  printf("building map\n");
  while (i < map->width * map->height)
    {
      cases[i].characters = NULL;
      cases[i].quantities[FOOD] = 0;
      cases[i].quantities[LINEMATE] = 0;
      cases[i].quantities[DERAUMERE] = 0;
      cases[i].quantities[SIBUR] = 0;
      cases[i].quantities[MENDIANE] = 0;
      cases[i].quantities[PHIRAS] = 0;
      cases[i].quantities[THYSTAME] = 0;
      cases[i].x = i % map->width;
      cases[i].y = i / map->height;
      printf("case %i x: %i y: %i\n", i, cases[i].x, cases[i].y);
      i++;
    }
  map->cases = cases;
  return (RETURN_SUCCESS);
}

t_case					*map_get_case_at(const t_u64 x,
							 const t_u64 y,
							 const t_map *map)
{
  t_u64					index;

  printf("looking for case at x: %i y: %i\n", x, y);
  index = y * map->width + x;
  if (index >= map->height * map->width)
    return (NULL);
  printf("found case %i at x: %i y: %i\n", index, map->cases[index].x, map->cases[index].y);
  return (&map->cases[index]);
}

void					spread_ressource(const e_object_type type,
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
  t_u64					base_max_members;
  t_map					*map;

  nbr_of_teams = server->game_data.nbr_of_teams;
  base_max_members = server->game_data.base_max_members;
  map = &server->game_data.map;
  srand(time(NULL));
  spread_ressource(FOOD, nbr_of_teams * base_max_members * 100, map);
  spread_ressource(LINEMATE, nbr_of_teams * base_max_members * 6, map);
  spread_ressource(DERAUMERE, nbr_of_teams * base_max_members * 5, map);
  spread_ressource(SIBUR, nbr_of_teams * base_max_members * 4, map);
  spread_ressource(MENDIANE, nbr_of_teams * base_max_members * 3, map);
  spread_ressource(PHIRAS, nbr_of_teams * base_max_members * 2, map);
  spread_ressource(THYSTAME, nbr_of_teams * base_max_members, map);
}

void					text_display_map(t_map *map)
{
  t_u64					i;

  i = 0;
  while (i < map->width * map->height)
    {
      printf("--------- case at x: %i y: %i\n",
	     i % map->height,
	     i / map->height);
      printf("Food: %i\n", map->cases[i].quantities[FOOD]);
      printf("Linemate: %i\n", map->cases[i].quantities[LINEMATE]);
      printf("Deraumere: %i\n", map->cases[i].quantities[DERAUMERE]);
      printf("Sibur: %i\n", map->cases[i].quantities[SIBUR]);
      printf("Mendiane: %i\n", map->cases[i].quantities[MENDIANE]);
      printf("Phiras: %i\n", map->cases[i].quantities[PHIRAS]);
      printf("Thystame: %i\n", map->cases[i].quantities[THYSTAME]);
      i++;
    }
}
