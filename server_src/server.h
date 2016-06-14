/*
** server.h for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Jun  7 16:22:59 2016 Barthelemy Gouby
<<<<<<< HEAD
** Last update Tue Jun 14 15:39:02 2016 Barthelemy Gouby
=======
** Last update Tue Jun 14 15:52:08 2016 Erwan Dupard
>>>>>>> 8477b46a05f9655364a08f8d836f988690b63562
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
# define CIRC_PAGE_NBR			(10)			
# define PAGE_SIZE			(4096)

# define RETURN_SUCCESS			(0)
# define RETURN_FAILURE			(-1)

typedef enum
  {
    NORTH				= 1,
    EST					= 2,
    SOUTH				= 3,
    WEST				= 4
  }					e_orientation;

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
  }					e_object_type;

typedef enum
  {
    DRONE,
    GRAPHIC,
    UNSPECIFIED
  }					e_client_type;

typedef unsigned int			t_quantity;

struct					s_case;

typedef struct				s_character
{
  unsigned int				id;
  unsigned int				level;
  char					*team;
  t_quantity				quantities[NUMBER_OF_TYPES];
  e_orientation			        orientation;
  struct s_case				*current_case;
  struct s_character			*next_in_case;
}					t_character;

typedef struct				s_case
{
  t_character				*characters;
  t_quantity				quantities[NUMBER_OF_TYPES];
  unsigned int				x;
  unsigned int				y;
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
  e_client_type				type;
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
  unsigned int				next_drone_id;
}					t_game_data;

typedef struct				s_server
{
  int					socket;
  struct sockaddr_in			in;
  int					port;
  t_client				*clients;
  t_game_data				game_data;
  char					buffer[PAGE_SIZE];
}					t_server;

typedef struct				s_command
{
  const char				*command;
  int					(*f)(t_server *server,
					     t_client *client,
					     char *operands);
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
void					place_character_randomly(t_map *map,
								 t_character *character);
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

typedef unsigned int			t_u64;

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
int					get_options(t_u64 argc,
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
int					change_time_unit(t_server *server,
							 t_client *client,
							 char *operands
							 __attribute__((unused)));
int				        send_player_level(t_server *server,
							 t_client *client,
							 char *operands
							 __attribute__((unused)));
int				        send_player_inventory(t_server *server,
							 t_client *client,
							 char *operands
							 __attribute__((unused)));

int				        send_player_position(t_server *server,
							 t_client *client,
							 char *operands
							 __attribute__((unused)));

#endif /* !_SERVER_H_ */
