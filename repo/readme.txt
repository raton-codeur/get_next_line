compiler avec make all

on peut lancer l'exécutable avec ./gnl

le programme de base boucle sur l'entrée standard.
on peut taper le contenu ligne par ligne et tester le ctrl + d

on peut aussi utiliser le fichier test.txt
make test <-> ./gnl < test.txt

on peut aussi utiliser printf
make test-blabla <-> printf "blabla" | ./gnl

on peut aussi utiliser l'autre main commenté dans main.c qui ouvre le fichier test.txt et qui l'affiche

on peut clean avec "make clean"
