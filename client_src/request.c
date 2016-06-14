/*
** request.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Wed Jun 08 15:17:57 2016 Gabriel Goude
** Last update Tue Jun 14 14:39:08 2016 Gabriel Goude
*/

#include <unistd.h>
#include <stdlib.h>
#include "resources.h"

int			avance(t_infos *infos)
{
  write(infos->socket, "avance\n", 7);
  add_elem(infos, AVANCE);
  return (RETURN_SUCCESS);
}

int			droite(t_infos *infos)
{
  write(infos->socket, "droite\n", 7);
  add_elem(infos, DROITE);
  return (RETURN_SUCCESS);
}

int			gauche(t_infos *infos)
{
  write(infos->socket, "gauche\n", 7);
  add_elem(infos, GAUCHE);
  return (RETURN_SUCCESS);
}

int			voir(t_infos *infos)
{
  write(infos->socket, "voir\n", 5);
  add_elem(infos, VOIR);
  return (RETURN_SUCCESS);
}

int			inventaire(t_infos *infos)
{
  write(infos->socket, "inventaire\n", 11);
  add_elem(infos, INVENTAIRE);
  return (RETURN_SUCCESS);
}
