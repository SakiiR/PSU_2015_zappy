/*
** server.h for zappy in /home/barthe_g/rendu/tek2/unix_reseau/PSU_2015_zappy/server_src
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Jun  7 16:22:59 2016 Barthelemy Gouby
** Last update Sat Jun 25 19:30:47 2016 Karine Aknin
*/

#ifndef SERVER_H_
# define SERVER_H_

#define _BSD_SOURCE
#define _SVID_SOURCE
#define _DEFAULT_SOURCE

# include <stdlib.h>
# include <arpa/inet.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <sys/time.h>
# include <sys/select.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <math.h>
# include <circular_buffer/circular_buffer.h>

# define MAX_CLIENTS			(50)
# define CIRC_PAGE_NBR			(10)
# define PAGE_SIZE			(4096)

# define RETURN_SUCCESS			(0)
# define RETURN_FAILURE			(-1)

typedef unsigned int			t_u64;

typedef enum
  {
    MIN					= -1,
    NORTH				= 0,
    EAST				= 1,
    SOUTH				= 2,
    WEST				= 3,
    UNDEFINED				= 4
  }					e_orientation;

typedef enum
  {
    RIGHT				= 0,
    LEFT				= 1
  }					e_turn;

typedef enum
  {
    NOURRITURE				= 0,
    LINEMATE				= 1,
    DERAUMERE				= 2,
    SIBUR				= 3,
    MENDIANE				= 4,
    PHIRAS				= 5,
    THYSTAME				= 6,
    NUMBER_OF_TYPES			= 7
  }					e_ressource_type;

typedef struct				s_ressource_name_c
{
  char					*name;
  e_ressource_type			type_identifier;
}					t_ressource_name_c;

typedef enum
  {
    DRONE,
    GRAPHIC,
    UNSPECIFIED
  }					e_client_type;

typedef unsigned int			t_quantity;

struct					s_case;

struct					s_action;
typedef struct s_action			t_action;

struct					s_team;
typedef struct s_team			t_team;

typedef struct				s_character
{
  t_u64					level;
  t_u64				        id;
  t_team				*team;
  t_quantity				quantities[NUMBER_OF_TYPES];
  e_orientation			        orientation;
  t_action				*action_queue;
  t_u64					hunger_timer;
  char					base_member;
  struct s_case				*current_case;
  struct s_character			*next_in_case;
}					t_character;

typedef struct				s_case
{
  t_character				*characters;
  t_quantity				quantities[NUMBER_OF_TYPES];
  int					x;
  int					y;
}					t_case;

typedef struct				s_map
{
  t_case				*cases;
  int					width;
  int					height;
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
}					t_client;

typedef struct				s_egg
{
  t_u64					id;
  int					hatched;
  t_u64					timer;
  t_u64					x;
  t_u64					y;
  struct s_egg				*next;
}					t_egg;

struct					s_team
{
  char					*name;
  t_client				*members;
  t_egg					*eggs;
  t_u64					max_members;
  t_u64					base_members;
};

typedef struct				s_game_data
{
  t_map					map;
  int					speed;
  struct timeval			last_tick;
  struct timeval			tick_length;
  t_u64					base_max_members;
  t_team				*teams;
  t_u64					nbr_of_teams;
  t_u64					next_drone_id;
  t_u64					next_egg_id;
  t_action				*pending_actions;
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

typedef struct				s_voir
{
  e_orientation				orientation;
  int					(*f)(t_map *map, t_client *client,
					     t_case **cases);
}					t_voir;

int					process_server(t_server *server);
int					select_sockets(t_server *server,
						       fd_set *si,
						       fd_set *so);
int					handle_command(char *command,
						      t_server *server,
						      t_client *client);
int					handle_events(t_server *server);
int					player_food_consumption(t_server *server);
int					define_client_type(t_server *server,
							   t_client *client,
							   char *input);

void					set_time_speed(t_server *server);
int					initialize_map(t_map *map);
void					initialize_ressources(t_server *server);
t_case					*map_get_case_circular(int x,
							       int y,
							       t_map *map);
t_case					*map_get_case_at(const t_u64 x,
							 const t_u64 y,
							 const t_map *map);
void					add_character_to_case(t_case *c,
							      t_character *character);
void					remove_character_from_case(t_case *c,
								   t_character *character);
void					place_character_randomly(t_map *map,
								 t_character *character);
int					place_character_at_egg(t_map *map,
							       t_character *character,
							       t_egg **eggs);
void					change_coordinate(unsigned int *coordinate,
							  int change,
							  unsigned int max_value);
void					text_display_map(t_map *map);
void					add_egg(t_egg **egg_list, t_egg *new_egg);
t_egg					*remove_egg(t_egg **egg_list, t_egg *egg);
int					number_of_hatched_eggs(t_egg *egg_list);
t_egg					*retrieve_hatched_egg(t_egg **egg_list);

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
int					check_options(t_server *server,
						      char *file_name);

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

int				        graphic_broadcast(t_server *server, char *message);
int					send_map_size(t_server *server,
						      t_client *client,
						      char *operands);
int					send_speed(t_server *server,
						   t_client *client,
						   char *operands);
int					send_case_content(t_server *server,
							  t_client *client,
							  char *operands);
int					send_map_content(t_server *server,
							 t_client *client,
							 char *operands);
int					send_team_names(t_server *server,
							t_client *client,
							char *operands);
int					change_time_unit(t_server *server,
							 t_client *client,
							 char *operands);
int				        send_player_level(t_server *server,
							  t_client *client,
							  char *operands);
void					write_inventory_string(t_server *server,
							       t_character *character);
void					write_case_content_string(t_server *server,
								  int x,
								  int y);
int				        send_player_inventory(t_server *server,
							      t_client *client,
							      char *operands);
int				        send_player_position(t_server *server,
							     t_client *client,
							     char *operands);

int					voir_command(t_server *server,
						     t_client *client,
						     char *operands);
int				        inventaire_command(t_server *server,
							   t_client *client,
							   char *operands);
int					droite_command(t_server *server,
						       t_client *client,
						       char *operands);
int					gauche_command(t_server *server,
						       t_client *client,
						       char *operands);
int				        avance_command(t_server *server,
						       t_client *client,
						       char *operands);
int					prend_command(t_server *server,
						      t_client *client,
						      char *operands);
int					pose_command(t_server *server,
						     t_client *client,
						     char *operands);
int					fork_command(t_server *server,
						     t_client *client,
						     char *operands);
int					connect_nbr_command(t_server *server,
							    t_client *client,
							    char *operands);
int					broadcast_command(t_server *server,
							  t_client *client,
							  char *operands);
int					incantation_command(t_server *server,
							    t_client *client,
							    char *operands);
int					voir_north(t_map *map,
						   t_client *client,
						   t_case **cases);
int					voir_south(t_map *map,
						   t_client *client,
                                                   t_case **cases);
int					voir_west(t_map *map,
						  t_client *client,
                                                   t_case **cases);
int					voir_east(t_map *map,
						  t_client *client,
                                                   t_case **cases);
int					generate_base_size_level(int level);
int					generate_message_voir(t_client *client,
							      t_case **cases);
int					count_character(t_case *cases);
int					write_elem_case(char *message, t_case *cases,
							t_client *client, int i);
/*
 * Incantations
 */
typedef struct				s_incantation
{
  t_u64					level;
  int					players;
  t_quantity				obj[NUMBER_OF_TYPES];
}					t_incantation;

t_character				**get_incantation_players(int count,
								  t_character *all);
void					incantation_failed(t_server *server,
							   t_client *client);
int					do_incantation(t_case *c,
						       t_incantation *incantation);
int					check_incantation(t_incantation *incantation,
							  t_case *c,
							  t_character ***characters
							  __attribute__((unused)));
int					check_resources(t_case *c,
							t_incantation *incantation);
int					check_characters_incase(t_case *c,
								t_character **characters);
t_incantation				*get_incantation_by_level(t_u64 level);
int					incantation_broadcast_b(t_server *server,
								t_client *client,
								t_incantation *incantation,
								t_character **players);
int					incantation_broadcast_e(t_server *server,
								t_client *client,
								t_character **players);
/*
 * Expulse
 */
int					expulse_player(t_map *map,
						       t_character *character,
						       e_orientation orientation);
typedef struct				s_expulse_case
{
  e_orientation				type;
  void					(*f)(int x,
					     int y,
					     int *new_x,
					     int *new_y);
}					t_expulse_case;

void					expulse_north(int x,
						      int y,
						      int *new_x,
						      int *new_y);
void					expulse_south(int x,
						      int y,
						      int *new_x,
						      int *new_y);
void					expulse_west(int x,
						      int y,
						      int *new_x,
						      int *new_y);
void					expulse_east(int x,
						      int y,
						      int *new_x,
						      int *new_y);

# include "events.h"

#endif /* !SERVER_H_ */
