# get_next_line

Go to [french version](#a-propos)

## About get_next_line
Get_next_line is a function that allows us to read a file line by line. This is a function that will be useful in a lot of later projects. 

# Getting Started

## Usage
```int	get_next_line(int fd, char **line)```
Get_next_line fills the line buffer by reading into the given fd. Line must be the address of a `char*` pointer. Get_next_line must not be used with any other reading function such as read on the same file. 
The function return -1 if an error occurs or 0 on success. 

Feel free to explore the source code to understand its detailed workings.

# Authors
- [Houdeyer Lucie](github.com/HdrLucie)


## A propos

Get_next_line est une fonction qui permet de lire un fichier ligne par ligne. Cette fonction sera utile pour plusieurs projets suivants.

# Pour commencer

## Utilisation
```int	get_next_line(int fd, char **line)```
Get_next_line remplit le buffer line en lisant sur le fd passé en paramètre. Line doit etre l'adresse d'un `char*`. La fonction ne doit en aucun cas être utilisé avec une autre fonction de lecture (comme read) pour le même fichier.
La fonction retourne -1 en cas d'erreur ou 0 en cas de succès.

N'hésitez pas à explorer le code source pour comprendre en détail son fonctionnement.

# Auteur
- [Houdeyer Lucie](github.com/HdrLucie)
