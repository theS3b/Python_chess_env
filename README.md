# Python_chess_env

Le code consiste à créer un .pyd, c'est-à-dire une dll pour python.
Il faut d'abord compiler le projet. Ensuite, la commande :
python setup.py install
doit être executée dans le dossier des fichiers sources.
Finalement la bibliothèque chess_env.cp37-win_amd64.pyd est créée dans le dossier Python_chess_env/chess_env_cpp/build/lib.win-amd64-3.7/

Pour utiliser les fonctions en Python, il suffit de mettre le .pyd dans le même dossier que votre script.
Finalement, on importe la bibliothèque avec la commande:

from chess_env import *
