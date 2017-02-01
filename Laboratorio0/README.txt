*************************************************************************
*************************************************************************

			Juego de ecología en C++

	Autores:	
		Luis Diego Fernandez Coto
		Daniel Jimenez Leon

*************************************************************************
*************************************************************************

	Universidad de Costa Rica
	Estructuras Abstractas de Datos y Algoritmos
	Prof: Ricardo Román Brenes
	Asignacion: Laboratorio 0

*************************************************************************
*************************************************************************

	El presente, es un juego implementado en C++, donde se crea
	un escenario representando un ecosistema. Este puede contener
	animales de diferentes especies, y ellos cumplen algunas 
	funciones basicas para subsistir como comer, ya sea otros 
	animales o elementos presentes en el ecosistema, desplazarse, 
	reproducirse y morir. 

*************************************************************************
*************************************************************************

	Los datos del ecosistema se entregan al programa mediante un
	archivo de texto con el siguiente formato:

	3		//Columnas
	3		//Filas
	0 0 35 LM	//Posicion (0 0) 35 nivel de zacate y Lobo Macho
	0 1 56 OH	//Posicion (0 1) 56 nivel de zacate y Zorro Macho
	0 2 12		//Posicion (0 2) 12 nivel de zacate y sin animal
	.
	.
	.

	Asi para el resto de posiciones del terreno (representado como
	una matriz). Los animales son:
		
		LM o LH: Lobo Macho o Lobo Hembra
		OM o OH: Oveja Macho o Oveja Hembra
		ZM o ZH: Zorro Macho o Zorro Hembra
		RM o RH: Raton Macho o Raton Hembra

*************************************************************************
*************************************************************************

						     31 de Enero del 2017
