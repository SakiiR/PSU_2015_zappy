/*
** server.h for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Jun  7 16:22:59 2016 Barthelemy Gouby
** Last update Mon Jun 13 13:26:48 2016 Barthelemy Gouby
*/

#ifndef _SERVER_H_
# define _SERVER_H_

# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <sys/time.h>
# include <sys/select.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <circular_buffer/circular_buffer.h>

# define MAX_CLIENTS			(50)
# define BUFFER_SIZE			(4096)

# define RETURN_SUCCESS			(0)
# define RETURN_FAILURE			(-1)

typedef enum
  {
    UP,
    DOWN,
    LEFT,
    RIGHT
  }					orientation;

typedef enum
  {
    FOOD				= 0,
    LINEMATE				= 1,
    DERAUMERE				= 2,
    SIBUR				= 3,
    MENDIANE				= 4,
    PHIRAS				= 5,
    THYSTAME				= 6,
    NUMBER_OF_TYPES			= 7
  }					object_type;

typedef enum
  {
    DRONE,
    GRAPHIC,
    UNSPECIFIED
  }					client_type;

typedef unsigned int			quantity;

struct					s_case;

typedef struct				s_character
{
  unsigned int				level;
  char					*team;
  quantity				quantities[NUMBER_OF_TYPES];
  orientation				orientation;
  struct s_case				*current_case;
  struct s_character			*next_in_case;
}					t_character;

typedef struct				s_case
{
  t_character				*characters;
  quantity				quantities[NUMBER_OF_TYPES];
}					t_case;

typedef struct				s_map
{
  t_case				*cases;
  unsigned int				width;
  unsigned int				height;
}					t_map;

typedef struct				s_client
{
  char					*host_name;
  char					*server_name;
  int					socket;
  struct sockaddr_in			in;
  t_circular_buffer			buffer_in;
  t_circular_buffer			buffer_out;
  client_type				type;
  t_character				*character;
  char					*team;
}					t_client;

typedef struct				s_team
{
  char					*name;
  t_client				*members;
  unsigned int				max_members;
}					t_team;

typedef struct				s_game_data
{
  t_map					map;
  int					speed;
  unsigned int				base_max_members;
  t_team				*teams;
  unsigned int				nbr_of_teams; 
}					t_game_data;

typedef struct				s_server
{
  int					socket;
  struct sockaddr_in			in;
  int					port;
  const char				*host_name;
  t_client				*clients;
  t_game_data				game_data;
  char					buffer[4096];
}					t_server;

typedef struct				s_command
{
  const char				*command;
  int					(*f)(char *command,
					     t_server *server,
					     t_client *client);
  int					require_auth;
}					t_command;

int					process_server(t_server *server);
int					handle_command(char *command,
						      t_server *server,
						      t_client *client);
int					define_client_type(t_server *server,
							   t_client *client,
							   char *input);

int					initialize_map(t_map *map);
void					initialize_ressources(t_server *server);
t_case					*map_get_case_at(const unsigned int x,
							 const unsigned int y,
							 const t_map *map);
void					text_display_map(t_map *map);

# define WELCOME			("BIENVENUE\n")

# define MIN_PORT			(0)
# define MAX_PORT			(65535)
# define MIN_WORLD_X			(1)
# define MAX_WORLD_X			(500)
# define MIN_WORLD_Y			(1)
# define MAX_WORLD_Y			(500)
# define MIN_MAX_CLIENTS		(1)
# define MAX_MAX_CLIENTS		(50)
# define MIN_SPEED			(1)
# define MAX_SPEED			(500)

typedef unsigned int			u64;

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
int					check_options(t_server *server, char *file_name);

/*
 * Function pointers
 */
int					option_id_port(char **args,
						       t_server *server);
int					option_id_worldx(char **args,
							 t_server *server);
int					option_id_worldy(char **args,
							 t_server *server);
int					option_id_maxmembers(char **args,
							     t_server *server);
int					option_id_speed(char **args,
							t_server *server);
int					option_id_teams(char **args,
							t_server *server);

int					send_map_size(t_server *server,
						      t_client *client,
						      char *operands
						      __attribute__((unused)));
int					send_speed(t_server *server,
						   t_client *client,
						   char *operands
						   __attribute__((unused)));
int					send_case_content(t_server *server,
							  t_client *client,
							  char *operands);
int					send_map_content(t_server *server,
							 t_client *client,
							 char *operands
							 __attribute__((unused)));
int					send_team_names(t_server *server,
							t_client *client,
							char *operands __attribute__((unused)));

#endif /* !_SERVER_H_ */
