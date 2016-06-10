/*
** drone.h for zappy in /home/goude_g/src/PSU_2015_zappy/client_src
** 
** Made by Gabriel Goude
** Login   <goude_g@epitech.net>
** 
** Started on  Tue Jun 07 15:48:50 2016 Gabriel Goude
** Last update Fri Jun 10 14:48:48 2016 Gabriel Goude
*/

#ifndef DRONE_H_
# define DRONE_H_

# include <netinet/ip.h>

typedef struct		s_inv
{
  int			food;
  int			linemate;
  int			deraumere;
  int			sibur;
  int			mendiane;
  int			phiras;
  int			thystame;
}			t_inv;

typedef struct		s_game
{
  int			world_x;
  int			world_y;
  t_inv			inv;
}			t_game;

typedef struct		s_client_settings
{
  char			*team_name;
  struct sockaddr_in	sock;
  int			s;

}		t_client_settings;

/*
** ai.c
*/
int		ai(t_client_settings *settings, t_game *game);

/*
** connect.c
*/
int		init_connection(t_client_settings *settings);
int		enter_game(t_client_settings *settings, t_game *game);
int		get_world_size(t_game *game, char *s);
void		init_inv(t_game *game);

/*
** parser.c
*/
int		get_param(int ac, char **av, t_client_settings *settings);
int		get_next_param(int i, char **av, t_client_settings *settings);

#endif /* !DRONE_H_ */
