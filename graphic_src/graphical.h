/*
** graphical.h for PSU_2015_zappy in /home/mikaz3/Tek2/PSU_2015_zappy/graphic_src
** 
** Made by Thomas Billot
** Login   <mikaz3@epitech.net>
** 
** Started on  Thu Jun  9 14:43:41 2016 Thomas Billot
** Last update Mon Jun 13 18:11:11 2016 Thomas Billot
*/

#ifndef GRAPHICAL_H_
# define GRAPHICAL_H_

#include "network.h"
#include "../utils/circular_buffer/circular_buffer.h"

#define	MSZ "msz" /* Taille de la carte */
#define BCT "bct" /* Contenu de toute la carte (une case - toutes les cases) */
#define TNA "tna" /* Nom des équipes */
#define PNW "pnw" /* Connexion d'un nouveau joueur */
#define PPO "ppo" /* Position d'un joueur */
#define PLV "plv" /* Niveau d'un joueur */
#define PIN "pin" /* Inventaire d'un joueur */
#define PEX "pex" /* Expluse un joueur */
#define PBC "pbc" /* Un joueur fait un broadcast */
#define PIC "pic" /* Debut d'incantation pour tout les joueurs sur la case */
#define PIE "pie" /* Fin d'incantation avec resultat (1 ou 0) */
#define PFK "pfk" /* Le joueur pond un oeuf */   
#define PDR "pdr" /* Le joueur jete une ressource */
#define PGT "pgt" /* Le joueur prends une ressource */
#define PDI "pdi" /* Le joueur est mort de faim */
#define ENW "enw" /* L'oeuf a ete pondu sur la case par le joueur */
#define EHT "eht" /* L'oeuf eclos */
#define EBO "ebo" /* Un joueur s'est connecte pour l'oeuf */
#define EBI "ebi" /* L'oeuf eclos est mort de faim */
#define SGT "sgt" /* Demande l'unite de temps du serveur */
#define SEG "seg" /* Fin du jeu, l'equipe donne gagne */
#define SMG "smg" /* Message du serveur */
#define SUC "suc" /* Commande du serveur */
#define SBP "sbp" /* Mauvais parametres de commande */

#define BIENVENUE "BIENVENUE" /* Message du serveur pour 
				 initialisé le moniteur graphique */

typedef unsigned int	t_quantity;

typedef struct		s_info
{
  int			sockfd;
  t_circular_buffer	*circular_buffer;
  struct s_map		*map;
}			t_info;

typedef struct		s_ptr
{ 
  const char		*id;
  int			(*f)(t_info *);
}			t_ptr;

typedef enum
  {
    FOOD		= 0,
    LINEMATE		= 1,
    DERAUMERE		= 2,
    SIBUR		= 3,
    MENDIANE		= 4,
    PHIRAS		= 5,
    THYSTAME		= 6,
    NUMBER_OF_TYPES	= 7
  }			e_object_types;

typedef struct		s_tiles
{
  t_quantity		obj[NUMBER_OF_TYPES];
  unsigned int		players;
}			t_tiles;

typedef struct		s_map
{
  int			x;
  int			y;
  struct s_tiles	*tiles;
}			t_map;

int			launch_client(t_info *options);

int			fct_welcome(t_info *options);

#endif /* !GRAPHICAL_H_ */
