/*
** request.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Wed Jun 08 15:17:57 2016 Gabriel Goude
** Last update Mon Jun 13 17:53:10 2016 Gabriel Goude
*/

#include <unistd.h>
#include <stdlib.h>
#include "resources.h"

int			avance(t_infos *infos)
{
  write(infos->socket, "avance\n", 7);
  return (RETURN_SUCCESS);
}

int			droite(t_infos *infos)
{
  write(infos->socket, "droite\n", 7);
  return (RETURN_SUCCESS);
}

int			gauche(t_infos *infos)
{
  write(infos->socket, "gauche\n", 7);
  return (RETURN_SUCCESS);
}

int			voir(t_infos *infos)
{
  write(infos->socket, "voir\n", 5);
  return (RETURN_SUCCESS);
}

int			inventaire(t_infos *infos)
{
  write(infos->socket, "inventaire\n", 11);
  return (RETURN_SUCCESS);
}
