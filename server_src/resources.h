/*
** resources.h for zappy in /home/dupard_e/rendus/PSU_2015_zappy
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jun  7 15:51:58 2016 Erwan Dupard
** Last update Tue Jun  7 16:48:12 2016 Erwan Dupard
*/

#ifndef RESOURCES_H_
# define RESOURCES_H_

# include <stdlib.h>
# include <stdio.h>
# include "options.h"

# define RETURN_SUCCESS			(0)
# define RETURN_FAILURE			(-1)

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
}					t_options;

/*
 * Pointer Function Array Definition
 */
typedef struct				s_option_id
{
  const char				id;
  int					(*f)(char **args, t_options *options);
}					t_option_id;

/*
 * Base Command Line Options Gesture
 */
int					get_options(u64 argc,
						    char **argv,
						    t_options *options);
void					init_options(t_options *options);
int					handle_option_id(const char id,
							 char **args,
							 t_options *options);
int					check_options(t_options *options);

/*
 * Function pointers
 */
int					option_id_port(char **args, t_options *options);
int					option_id_worldx(char **args, t_options *options);
int					option_id_worldy(char **args, t_options *options);
int					option_id_maxclients(char **args, t_options *options);
int					option_id_speed(char **args, t_options *options);
int					option_id_teams(char **args, t_options *options);

#endif /* ! RESOURCES_H_ */
