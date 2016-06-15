/*
** ai.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 10 14:31:29 2016 Gabriel Goude
** Last update Tue Jun 14 17:13:29 2016 Erwan Dupard
*/

#include <stdlib.h>
#include <circular_buffer/circular_buffer.h>
#include "resources.h"

int			ai(t_infos *infos)
{
  infos->select.tv.tv_sec = 5;
  infos->select.tv.tv_usec = 0;
  if (initialize_buffer(&(infos->buffer), 10 * 4096) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  if (enter_game(infos) == RETURN_FAILURE)
    return (RETURN_FAILURE);
  return (RETURN_SUCCESS);
}

/*
 * Qu-est-ce que ce code fou ici ? :)
 */
void			fill_set(t_infos *infos)
{
  FD_ZERO(&(infos->select.rfds));
  FD_ZERO(&(infos->select.wfds));
  FD_SET(infos->socket, &(infos->select.rfds));
  FD_SET(infos->socket, &(infos->select.wfds));
}
