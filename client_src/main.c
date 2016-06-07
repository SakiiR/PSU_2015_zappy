/*
** main.c for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 07 15:48:09 2016 Gabriel Goude
** Last update Tue Jun 07 17:42:11 2016 Gabriel Goude
*/

#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdlib.h>
#include "drone.h"

int			main(int ac, char **av)
{
  t_client_settings	settings;

  if (get_param(ac, av, &settings) == EXIT_FAILURE)
    return (0);
}

