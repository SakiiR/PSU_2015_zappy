/*
** my_str_to_wordtab.c for myftp in /home/dupard_e/rendus/PSU_2015_myftp
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue May  3 11:38:55 2016 Erwan Dupard
** Last update Sun Jun 26 20:31:39 2016 Karine Aknin
*/

#include <stdlib.h>

static int				is_allowed_char(char c, const char *forbidden)
{
  int					i;

  i = -1;
  while (forbidden[++i])
    {
      if (c == forbidden[i])
	return (0);
    }
  return (1);
}

static int				count_words(const char *str, const char *forbidden)
{
  int					i;

  i = 0;
  while (str && *str)
    {
      if (str && *str && is_allowed_char(*str, forbidden))
	{
	  ++i;
	  while (str && *str && is_allowed_char(*str, forbidden))
	    str++;
	}
      if (*str)
	str++;
    }
  return (i);
}

static char				*getWord(const char *str, const char *forbidden)
{
  char					*ret;
  int					i;

  i = 0;
  while (str && str[i] && is_allowed_char(str[i], forbidden))
    ++i;
  if ((ret = malloc(sizeof(*str) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str && str[i] && is_allowed_char(str[i], forbidden))
    {
      ret[i] = str[i];
      ++i;
    }
  ret[i] = 0;
  return (ret);
}

void					free_word_tab(char **tab)
{
  unsigned int				i;

  if (tab)
    {
      i = -1;
      while (tab[++i])
	free(tab[i]);
      free(tab);
    }
}

char					**my_str_to_wordtab(const char *str,
							    const char *forbidden)
{
  char					**tab;
  unsigned int				j;

  if ((tab = malloc(sizeof(*tab) * (count_words(str, forbidden) + 1))) == NULL)
    return (NULL);
  j = 0;
  while (str && *str)
    {
      if (is_allowed_char(*str, forbidden))
	{
	  tab[j++] = getWord(str, forbidden);
	  while (str && *str && is_allowed_char(*str, forbidden))
	    str++;
	}
      if (*str)
	str++;
    }
  tab[j] = NULL;
  return (tab);
}
