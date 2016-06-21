/*
** handle1.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Fri Jun 17 16:52:53 2016 Gabriel Goude
** Last update Tue Jun 21 17:58:44 2016 Gabriel Goude
*/

#include "resources.h"

int				handle_avance(t_infos *infos, char *msg)
{
  (void)msg;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

int				handle_droite(t_infos *infos, char *msg)
{
  (void)msg;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

int				handle_gauche(t_infos *infos, char *msg)
{
  (void)msg;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

int				handle_voir(t_infos *infos, char *msg)
{
  /*
  ** update map
  */
  (void)msg;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

int				handle_inventaire(t_infos *infos, char *msg)
{
  /*
  ** update inventaire
  */
  (void)msg;
  remove_elem(infos);
  return (RETURN_SUCCESS);
}

