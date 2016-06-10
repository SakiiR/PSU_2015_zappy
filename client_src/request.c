/*
** request.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Wed Jun 08 15:17:57 2016 Gabriel Goude
** Last update Fri Jun 10 17:08:20 2016 Erwan Dupard
*/

#include <unistd.h>
#include <stdlib.h>
#include "resources.h"

int			avance(t_client_settings *settings)
{
  write(settings->s, "avance\n", 7);
  return (RETURN_SUCCESS);
}

int			droite(t_client_settings *settings)
{
  write(settings->s, "droite\n", 7);
  return (RETURN_SUCCESS);
}

int			gauche(t_client_settings *settings)
{
  write(settings->s, "gauche\n", 7);
  return (RETURN_SUCCESS);
}

int			voir(t_client_settings *settings)
{
  write(settings->s, "voir\n", 5);
  return (RETURN_SUCCESS);
}

int			inventaire(t_client_settings *settings)
{
  write(settings->s, "inventaire\n", 11);
  return (RETURN_SUCCESS);
}
