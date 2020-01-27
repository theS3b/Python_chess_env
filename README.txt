Version final de la bibliothèque
(Le code en python est 3x plus lent que le code en c++)

Le projet utilise pybind11 pour créer une bibliothèque python.

On ne peut pas modifier d'attribut depuis python.
Donc la bibliothèque ne permet que l'appelle des fonctions
get_bitboard_children(), get_result() et Board().

Pour obtenir la bibliothèque il faut "build" le projet c++ avec
Visual Studio 2019 pour produire une DLL. Puis nous obtenons un 
fichier .pyd dans le dossier x64/Release. Il faut copier ce fichier 
la où il y a les fichiers sources, puis executer la commande depuis 
le terminal dans ce dossier :

python setup.py install

Ce programme va créer la bibliothèque dans le dossier build.
Cette bibliothèque ne marche que pour un système Win64.

Le code met 15 sec à calculer 10^6 possibilités de coups depuis
la position initial des écheques.