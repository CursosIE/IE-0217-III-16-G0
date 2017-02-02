##
#@brief Tarea 3. Tiempos y Ordenes de Duracion
#@author Luis Diego Fernandez 
#@author Daniel Jimenez
#@date 1 de Febrero del 2017
#@version 1.0

import sys
from time import time

##@brief Metodo ordena un vector de numeros en orden ascendente utilizando el Selection Sort.
#@param Lista Lista en la cual vienen los numeros no ordenados.

def Selection_Sort(Lista):
    temp = 0
    posMin = 0
    #primer for de ordenamiento	
    for n in range(0, len(Lista)-1):
        posMin = n
	#segundo for de ordenamiento
	for m in range(n + 1, len(Lista)):
            if (Lista[m] < Lista[posMin]):
                posMin = m
	#intercambio de valores en caso de que haya que ordenar
        if(posMin != n):
            temp = Lista[n]
            Lista[n] = Lista[posMin]
            Lista[posMin] = temp
    return Lista

##@brief Metodo que hace una busqueda en una lista ordenada del tipo Binary Search
#@param Lista Lista en la cual buscar el numero.
#@param NUM Numero que se desa encontrar.
def Binary_Search(Lista, NUM):
    MIN = 0
    MAX = len(Lista)
    flag = 0

    while (flag == 0):
	#si el elemento en la posicion de buscqueda es igual a find hay exito
        if (Lista[(MIN + MAX)/2] == NUM):
            flag = 1
            return 1
	#Si el numero encontrado es mayor que el buscado, se cambia el limite mayor.
        elif (Lista[(MIN + MAX)/2] > NUM):
            MAX = (MIN + MAX)/2
	#Si el numero encontrado es menor que el buscado, se cambia el limite menor.        
	elif (Lista[(MIN + MAX)/2] < NUM):
            MIN = (MIN + MAX)/2
	#si se revisaron todos los numeros se acaba la ejecucion con una condicio de no exito        
	if(MAX == MIN + 1):
            return 0


#Programa Principal
#Leo cual algoritmo quiero ejecutar.
if (sys.argv[1] == "bs"):
    #Guardo el numero que deseo buscar.
    num = int(sys.argv[2])

    #Abro el archivo, leo la primer linea y la paso a una lista de enteros.
    datos = open(sys.argv[3], 'r')
    datos = datos.readline()
    Lista = datos.split(' ')
    for i in range(0,len(Lista)):
        if(Lista[i] != ""):
            Lista[i] = int(Lista[i]);
        else:
            Lista.pop(i)

    #Inicio la medicion de tiempo.
    start_time = time()
    #Llamo la funcion.
    BS = Binary_Search(Lista, num)
    #Determino el tiempo. 
    elapsed_time = time() - start_time
    #Imprimo la informacion.
    print BS
    print "\nTime: "
    print elapsed_time*1000 , "ms."

if (sys.argv[1] == "ss"):
    #Abro el archivo, leo la primer linea y la paso a una lista de enteros.
    datos = open(sys.argv[2], 'r')
    datos = datos.readline()
    Lista = datos.split(' ')
    for i in range(0,len(Lista)):
        if(Lista[i] != ""):
            Lista[i] = int(Lista[i]);
        else:
            Lista.pop(i)
    
    #Inicio la medicion de tiempo.
    start_time = time()
    #Llamo la funcion.
    SS = Selection_Sort(Lista)
    #Determino el tiempo. 
    elapsed_time = time() - start_time
    #Imprimo la informacion.
    print SS
    print "\nTime: "
    print elapsed_time*1000 , "ms."
