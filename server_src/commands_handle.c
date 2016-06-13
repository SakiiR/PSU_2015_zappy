/*
** commands_handle.c for myirc in /home/dupard_e/rendus/PSU_2015_myirc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Wed May 18 16:39:43 2016 Erwan Dupard
** Last update Mon Jun 13 13:26:23 2016 Barthelemy Gouby
*/

#include "server.h"

static const t_command			g_commands[] = {
  {NULL, NULL, 0}
};

int					handle_command(char *input,
						       t_server *server,
						       t_client *client)
{
  int					i;
  char					*command_name;
  char					*operands;

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
	    {
	      return (g_commands[i].f(operands, server, client));
	    }
	}
    }
  return (RETURN_SUCCESS);
}
