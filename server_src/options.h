/*
** resources.h for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun  7 15:51:58 2016 Erwan Dupard
** Last update Fri Jun 10 14:49:52 2016 Barthelemy Gouby
*/

#ifndef OPTIONS_H_
# define OPTIONS_H_

# include <stdlib.h>
# include <stdio.h>

# define RETURN_SUCCESS			(0)
# define RETURN_FAILURE			(-1)

# define MIN_PORT			(0)
# define MAX_PORT			(65535)
# define MIN_WORLD_X			(0)
# define MAX_WORLD_X			(500)
# define MIN_WORLD_Y			(0)
# define MAX_WORLD_Y			(500)
# define MIN_MAX_CLIENTS		(0)
# define MAX_MAX_CLIENTS		(50)
# define MIN_SPEED			(0)
# define MAX_SPEED			(500)

typedef unsigned int			u64;

/*
 * Command Line Options Structure
 */
typedef struct				s_options
{
  int					port;
  int					world_x;
  int					world_y;
  int					max_clients;
  int					speed;
  char					**teams;
  unsigned int				nbr_of_teams;
}					t_options;

/*
 * Pointer Function Array Definition
 */
typedef struct				s_option_id
{
  const char				id;
  int					(*f)(char **args, t_server *server);
}					t_option_id;

/*
 * Base Command Line Options Gesture
 */
int					get_options(u64 argc,
						    char **argv,
						    t_server *server);
void					init_options(t_server *server);
int					handle_option_id(const char id,
							 char **args,
							 t_server *server);
int					check_options(t_server *server);

/*
 * Function pointers
 */
int					option_id_port(char **args, t_server *server);
int					option_id_worldx(char **args, t_server *server);
int					option_id_worldy(char **args, t_server *server);
int					option_id_maxclients(char **args, t_server *server);
int					option_id_speed(char **args, t_server *server);
int					option_id_teams(char **args, t_server *server);

#endif /* ! OPTIONS_H_ */
