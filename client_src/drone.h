/*
** drone.h for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
**
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
**
** Started on  Tue Jun 07 15:48:50 2016 Gabriel Goude
** Last update Tue Jun 07 16:18:06 2016 Gabriel Goude
*/

#ifndef DRONE_H_
# define DRONE_H_

typedef struct		s_client_settings
{
  char			*team_name;
  struct sockaddr_in	sock;

}		t_client_settings;


#endif /* !DRONE_H_ */
