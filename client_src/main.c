/*
** main.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 07 15:48:09 2016 Gabriel Goude
** Last update Thu Jun 23 16:59:38 2016 Gabriel Goude
*/

#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include "resources.h"

int			main(int ac, char **av)
{
  t_infos		infos;
  t_map			map;
  t_client		client;

  infos.client = &client;
  infos.map = &map;
  infos.request = NULL;
  if (init_client(ac, av, &infos) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (play_loop(&infos) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}

int			init_client(int ac, char **av, t_infos *infos)
{
  if (get_param(ac, av, infos) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (init_connection(infos) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (initialize_buffer(&(infos->buffer), 10 * 4096) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (enter_game(infos) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}

int			play_loop(t_infos *infos)
{
  int			(*fct[NUMBER_OF_REQUESTS])(t_infos *, char *);

  init_fct(fct);
  while (infos->client->alive)
  {
    if (update(infos, fct) == RETURN_FAILURE)
      return (RETURN_FAILURE);
    if (ai(infos) == RETURN_FAILURE)
      return (RETURN_FAILURE);
    if (send_update(infos) == RETURN_FAILURE)
      return (RETURN_FAILURE);
  }
  return (RETURN_SUCCESS);
}

void			init_fct(int (**fct)(t_infos *, char *))
{
  fct[AVANCE] = handle_avance;
  fct[DROITE] = handle_droite;
  fct[GAUCHE] = handle_gauche;
  fct[VOIR] = handle_voir;
  fct[INVENTAIRE] = handle_inventaire;
  fct[PREND] = handle_prend;
  fct[POSE] = handle_pose;
  fct[EXPULSE] = handle_expulse;
  fct[BROADCAST] = handle_broadcast;
  fct[INCANTATION] = handle_incantation;
  fct[CONNECT_NBR] = handle_connect_nbr;
}
