/*
** fct_pfk.c for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy
**
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
**
** Started on  Thu Jun 16 14:43:26 2016 Thomas Billot
** Last update Sun Jun 26 20:42:27 2016 Karine Aknin
*/

#include <stdlib.h>
#include <stdio.h>
#include "../graphical.h"

t_character	*create_new_egg(int id)
{
  t_character	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->id = (t_u64)id;
  new->status = ALIVE;

  return (new);
}

int		fct_pfk(t_map *map,
			t_server *server __attribute__((unused)),
			char **cmd)
{
  t_character	*drone;

  if ((drone = get_player_by_id(map, (t_u64)atoi(cmd[1]))) == NULL)
    return (RETURN_FAILURE);
  put_delay(5000);
  create_new_egg(drone->id);
  return (RETURN_SUCCESS);
}
