#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
* El programa recibe dos parámetros desde consola (Nombre del programa, cantidad de iteraciones) Ej: ./register 10000000000
* Calcula el tiempo que se tarda en terminar las iteraciones solicitadas
* argc - Indica la cantidad de parámetros
* argv[0] - Indica el primer parámetro (Nombre del programa)
* argv[1] - Indica el segundo parámetro (Cantidad de iteraciones)
*/

int main(int argc, char* argv[]){

	//Si la cantidad de argumentos no corresponde, se termina el programa y se le indica al usuario la forma de uso
	if(argc != 2){
		
		printf("Forma de uso: %s varLong\n", argv[0]);
		
		return -1;
		
	}
	
	//Se obtiene la cantidad de iteraciones indicada en la consola y se alamacena en una variable tipo long
	long valMax = atol(argv[1]);
	
	//Se inicia la cuenta para el cálculo del tiempo transcurrido
	clock_t t = clock();
	
	printf("Inicio\n");
	
	//Se le indica al Sistema Operativo que la variable i NO se almacene en memoria principal (RAM) si no que se almacene en registros del procesador
	register int i = 0;
	
	//Se realiza el número de iteraciones indicadas en la consola
	while(i < valMax)
		i++;
	
	printf("Fin\n");
	
	//Se termina la cuenta para el cálculo del tiempo transcurrido
	t = clock()-t;
	
	//Se calcula el tiempo transcurrido para las iteraciones solicitadas
	double tiempo = ((double) t)/CLOCKS_PER_SEC;
	
	printf("Tiempo de ejecucion: %f\n", tiempo);

	return 0;

}
