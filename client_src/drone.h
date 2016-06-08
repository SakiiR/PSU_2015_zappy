/*
** drone.h for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 07 15:48:50 2016 Gabriel Goude
** Last update Wed Jun 08 13:50:26 2016 Gabriel Goude
*/

#ifndef DRONE_H_
# define DRONE_H_

#include <netinet/ip.h>

typedef struct		s_client_settings
{
  char			*team_name;
  struct sockaddr_in	sock;
  int			s;

}		t_client_settings;

/*
** main.c
*/
int		init_connection(t_client_settings *settings);

/*
** parser.c
*/
int		get_param(int ac, char **av, t_client_settings *settings);
int		get_next_param(int i, char **av, t_client_settings *settings);

#endif /* !DRONE_H_ */
