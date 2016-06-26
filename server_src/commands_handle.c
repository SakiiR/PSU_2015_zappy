/*
** commands_handle.c for myirc in /home/dupard_e/rendus/PSU_2015_myirc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed May 18 16:39:43 2016 Erwan Dupard
** Last update Sun Jun 26 17:42:17 2016 Erwan Dupard
*/

#include <my_str_to_wordtab/my_str_to_wordtab.h>
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
    {"incantation", &incantation_command},
    {NULL, NULL}
};

int					handle_command(char *input,
						       t_server *server,
						       t_client *client)
{
  int					i;
  char					**line;

  if (strlen(input) > 1)
      input[strlen(input) - 1] = 0;
  if (client->type == UNSPECIFIED)
    define_client_type(server, client, input);
  else
    {
      if ((line = my_str_to_wordtab(input, " \t\n")) == NULL)
	return (RETURN_FAILURE);
      i = -1;
      while (g_commands[++i].command != NULL)
	{
	  if (strcmp(g_commands[i].command, line[0]) == RETURN_SUCCESS)
	    return (g_commands[i].f(server, client, line[1]));
	}
      write_to_buffer(&client->buffer_out, "ko\n", 3);
      free_word_tab(line);
    }
  return (RETURN_SUCCESS);
}
