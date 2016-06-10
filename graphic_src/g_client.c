/*
** g_client.c for PSU_2015_zappy in /home/mikaz3
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Fri Jun 10 14:56:18 2016 Thomas Billot
** Last update Fri Jun 10 15:12:29 2016 Thomas Billot
*/

#include "graphical.h"
#include "network.h"
#include "circular_buffer.h"
#include "xfunc.h"

static t_ptr	ftab[] =
  {
    {MSZ, NULL},
    {BCT, NULL},
    {TNA, NULL},
    {PNW, NULL},
    {PPO, NULL},
    {PLV, NULL},
    {PEX, NULL},
    {PBC, NULL},
    {PIC, NULL},
    {PIE, NULL},
    {PFK, NULL},
    {PDR, NULL},
    {PGT, NULL},
    {PDI, NULL},
    {ENW, NULL},
    {EHT, NULL},
    {EBO, NULL},
    {EBI, NULL},
    {SGT, NULL},
    {SEG, NULL},
    {SMG, NULL},
    {SUC, NULL},
    {SBP, NULL},
    {BIENVENUE, fct_welcome},
    {NULL, NULL}
  };

int			launch_client(t_option *options)
{
  char			**cmd;
  char			*buff;
  char			*message;
  int			i;
  
  while ((buff = get_next_line(options->sockfd)) != NULL)
    {
      if (write_to_buffer(options->circular_buffer, buff, strlen(buff)) == -1)
	return (-1);
      printf("buff: [%s]\n", buff);
      if ((message = get_next_message(options->circular_buffer)) != NULL)
	{
	  printf("message: [%s]\n", message);
	  if ((cmd = my_str_to_wordtab(message, " ")) != NULL && cmd[0] != NULL)
	    {
	      i = -1;
	      while (ftab[++i].id != NULL)
		{
		  if (strcmp(cmd[0], ftab[i].id) == 0 && ftab[i].f != NULL)
		    {
		      printf("Command found: %s\n", ftab[i].id);
		      if (ftab[i].f(options) == -1)
			return (-1);
		    }
		}
	      free_word_tab(cmd);
	    }
	  free(message);
	}
      free(buff);
    }
  return (0);
}
