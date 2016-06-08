/*
** request.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Wed Jun 08 15:17:57 2016 Gabriel Goude
** Last update Wed Jun 08 16:12:10 2016 Gabriel Goude
*/

#include <unistd.h>
#include "drone.h"

int			avance(t_client_settings *settings)
{
  write(settings->s, "avance\n", 7);
}

int			droite(t_client_settings *settings)
{
  write(settings->s, "droite\n", 7);
}

int			gauche(t_client_settings *settings)
{
  write(settings->s, "gauche\n", 7);
}

int			voir(t_client_settings *settings)
{
  write(settings->s, "voir\n", 5);
}

int			inventaire(t_client_settings *settings)
{
  write(settings->s, "inventaire\n", 11);
}
