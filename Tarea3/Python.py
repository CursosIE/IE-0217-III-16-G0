import sys
from time import time

def Selection_Sort(Lista):
    for n in range(0, len(Lista)-1):
        for m in range(0, len(Lista)):
            if (Lista[n] < Lista[m]):
                temp = Lista[n]
                Lista[n] = Lista[m]
                Lista[m] = temp
    return Lista


def Binary_Search(Lista, NUM):
    MIN = 0
    MAX = len(Lista)
    flag = 0

    while (flag == 0):
        if (Lista[(MIN + MAX)/2] == NUM):
            flag = 1
            return 1
        elif (Lista[(MIN + MAX)/2] > NUM):
            MAX = (MIN + MAX)/2
        elif (Lista[(MIN + MAX)/2] < NUM):
            MIN = (MIN + MAX)/2
        if(MAX == MIN + 1):
            return 0

if (sys.argv[1] == "BS"):
    num = int(sys.argv[2])

    datos = open(sys.argv[3], 'r')
    datos = datos.readline()
    Lista = datos.split(' ')
    for i in range(0,len(Lista)):
        Lista[i] = int(Lista[i]);

    start_time = time()
    BS = Binary_Search(Lista, num)
    elapsed_time = time() - start_time
    print BS
    print "\nTime: "
    print elapsed_time

if (sys.argv[1] == "SS"):
    datos = open(sys.argv[2], 'r')
    datos = datos.readline()
    Lista = datos.split(' ')
    for i in range(0,len(Lista)):
        Lista[i] = int(Lista[i]);

    start_time = time()
    SS = Selection_Sort(Lista)
    elapsed_time = time() - start_time
    print SS
    print "\nTime: "
    print elapsed_time
