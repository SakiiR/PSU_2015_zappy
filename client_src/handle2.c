/*
** handle2.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 17 16:52:53 2016 Gabriel Goude
** Last update Tue Jun 21 17:58:38 2016 Gabriel Goude
*/

#include "resources.h"

int				handle_prend(t_infos *infos, char *msg)
{
  (void)msg;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

int				handle_pose(t_infos *infos, char *msg)
{
  (void)msg;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

int				handle_expulse(t_infos *infos, char *msg)
{
  (void)msg;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

int				handle_broadcast(t_infos *infos, char *msg)
{
  /*
  ** update map
  */
  (void)msg;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

int				handle_incantation(t_infos *infos, char *msg)
{
  /*
  ** update inventaire
  */
  (void)msg;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

