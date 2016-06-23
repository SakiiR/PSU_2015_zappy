/*
** commands_handle.c for myirc in /home/dupard_e/rendus/PSU_2015_myirc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed May 18 16:39:43 2016 Erwan Dupard
** Last update Wed Jun 22 18:44:47 2016 Barthelemy Gouby
*/

#include "server.h"

static const t_command			g_commands[] = {
    {"msz", &send_map_size},
    {"sst", &change_time_unit},
    {"ppo", &send_player_position},
    {"plv", &send_player_level},
    {"pin", &send_player_inventory},
    {"tna", &send_team_names},
    {"sgt", &send_speed},
    {"bct", &send_case_content},
    {"mct", &send_map_content},
    {"voir", &voir_command},
    {"inventaire", &inventaire_command},
    {"droite", &droite_command},
    {"gauche", &gauche_command},
    {"avance", &avance_command},
    {"prend", &prend_command},
    {"pose", &pose_command},
    {"fork", &fork_command},
    {"connect_nbr", &connect_nbr_command},
    {"broadcast", &broadcast_command},
    {NULL, NULL}
};

int					handle_command(char *input,
						       t_server *server,
						       t_client *client)
{
  int					i;
  char					*command_name;
  char					*operands;

  i = -1;
  if (strlen(input) > 1)
      input[strlen(input) - 1] = 0;
  if (client->type == UNSPECIFIED)
    define_client_type(server, client, input);
  else
    {
      command_name = strtok(input, " ");
      operands = strtok(NULL, "\n");
      while (g_commands[++i].command != NULL)
	{
	  if (strcmp(g_commands[i].command, command_name) == RETURN_SUCCESS)
	    return (g_commands[i].f(server, client, operands));
	}
    }
  return (RETURN_SUCCESS);
}
