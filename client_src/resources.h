/*
** resources.h for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jun 10 16:59:26 2016 Erwan Dupard
** Last update Fri Jun 10 17:03:24 2016 Erwan Dupard
*/

#ifndef RESOURCES_H_
# define RESOURCES_H_

# define RETURN_SUCCESS			(0)
# define RETURN_FAILURE			(-1)

# include <netinet/ip.h>

typedef struct				s_inv
{
  int					food;
  int					linemate;
  int					deraumere;
  int					sibur;
  int					mendiane;
  int					phiras;
  int					thystame;
}					t_inv;

typedef struct				s_game
{
  int					world_x;
  int					world_y;
  t_inv					inv;
}					t_game;

typedef struct				s_client_settings
{
  char					*team_name;
  struct sockaddr_in			sock;
  int					s;

}					t_client_settings;

/*
** ai.c
*/
int					ai(t_client_settings *settings, t_game *game);

/*
** connect.c
*/
int					init_connection(t_client_settings *settings);
int					enter_game(t_client_settings *settings, t_game *game);
int					get_world_size(t_game *game, char *s);
void					init_inv(t_game *game);

/*
** parser.c
*/
int					get_param(int ac, char **av, t_client_settings *settings);
int					get_next_param(int i, char **av, t_client_settings *settings);

#endif /* ! RESOURCES_H_ */
