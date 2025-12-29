# get_next_line

## Description

get_next_line est un projet de l'école 42 qui consiste à créer une fonction capable de lire une ligne depuis un file descriptor. Ce projet permet de découvrir les notions de variables statiques, de gestion de buffers et de lecture de fichiers en C.

## Objectifs

- Comprendre le fonctionnement des file descriptors
- Maîtriser les variables statiques
- Gérer la mémoire de manière dynamique
- Optimiser la lecture par buffer

## Prototype

```c
char *get_next_line(int fd);
```

## Paramètres

- `fd` : le file descriptor depuis lequel lire

## Valeur de retour

- La ligne lue (incluant le `\n` si présent)
- `NULL` si la lecture est terminée ou en cas d'erreur

## Compilation

Pour compiler le projet :

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

Le `BUFFER_SIZE` peut être défini à la compilation et détermine la taille du buffer de lecture.

## Utilisation

Exemple d'utilisation :

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("fichier.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```

## Fonctionnement

La fonction `get_next_line` lit le contenu d'un fichier ligne par ligne :

1. Elle lit le fichier par blocs de `BUFFER_SIZE` octets
2. Elle stocke les données lues dans une variable statique
3. Elle retourne une ligne complète à chaque appel
4. Elle gère plusieurs file descriptors simultanément (bonus)

## Fichiers du projet

- `get_next_line.h` : header contenant le prototype et les includes
- `get_next_line.c` : fonction principale
- `get_next_line_utils.c` : fonctions utilitaires

### Bonus

- `get_next_line_bonus.h`
- `get_next_line_bonus.c`
- `get_next_line_utils_bonus.c`

Le bonus permet de gérer plusieurs file descriptors en même temps sans perdre le fil de lecture de chacun.

## Fonctions autorisées

- `read`
- `malloc`
- `free`

## Gestion des erreurs

La fonction gère les cas suivants :
- File descriptor invalide
- Erreur de lecture
- Erreur d'allocation mémoire
- Fichier vide
- Ligne sans `\n` (fin de fichier)

## Contraintes

- Utiliser une variable statique est obligatoire
- La fonction doit fonctionner avec des fichiers et l'entrée standard
- La lecture doit être optimale quel que soit le `BUFFER_SIZE`
- Pas de leak mémoire

## Tests

Pour tester la fonction avec différents `BUFFER_SIZE` :

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1 main.c get_next_line.c get_next_line_utils.c
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 main.c get_next_line.c get_next_line_utils.c
```

Cas de test recommandés :
- Fichier avec des lignes courtes
- Fichier avec des lignes très longues
- Fichier vide
- Fichier sans `\n` final
- Lecture depuis stdin
- BUFFER_SIZE = 1
- BUFFER_SIZE très grand

## Structure du projet

```
get_next_line/
├── get_next_line.h
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line_bonus.h (bonus)
├── get_next_line_bonus.c (bonus)
├── get_next_line_utils_bonus.c (bonus)
└── README.md
```

## Normes

Ce projet respecte la Norme de 42 :
- Pas plus de 25 lignes par fonction
- Maximum 5 fonctions par fichier
- Variables déclarées en début de fonction

## Auteur

mobenhab - École 42

## Licence

Ce projet est réalisé dans le cadre du cursus de l'école 42.
