#################### sort_dataset.py ####################
#                                                       #
#    Script to sort JSON obtained from DataCollector    #
#    By Antonio Priego Raya                             #
#    Code created for the DeepPen project:              #
#    https://github.com/AntonioPriego/DeepPen           #
#                                                       #
#########################################################

import os
import sys
import json


# Comprobación de parámetros
if len(sys.argv) == 2:
    path_json = sys.argv[1]
else:
    print("Error: Debe introducir la ruta del dataset JSON a ordenar.")


# Apertura para lectura
with open(path_json, "r") as file:
    json_content = json.load(file)


# Obtención de número de instancias 'index' a ordenar
num_index = int( os.popen("grep -o index " + path_json + " | wc -l").read() )


# Ordenación
for i in range(0, num_index):
	json_content['strokes'][i]['index'] = i


# Escritura de los cambios
with open(path_json, "w") as file:
    json.dump(json_content, file, separators=(',', ':'))



file.close()
