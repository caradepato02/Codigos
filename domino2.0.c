#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void archivos(FILE *fp, char *nombre, float p[]);
void generador(float fichas[]);
void nrandom(int arreglo[], int size);
void nrepartir(int arreglo[], float fichas[], float p[], int *k);

main()
{
	int jugadores;
	int ciclar = 1;
	
	FILE *fp;
	
	printf("Cuantos jugadores? ");
	do {
		scanf("%d", &jugadores);
		if (jugadores < 2 || jugadores > 4) {
			printf("Numero de jugadores no valido\n");
		} else {
			ciclar = 0;
		}
		
	} while (ciclar);
	
	char nombres[jugadores][50];
	int i, j;
	for(i=0;i<jugadores;i++)
	{
		printf("Ingresa el nombre del jugador %d: ",i+1);
		fflush(stdin);
		gets(nombres[i]);
	}
	
	float fichas[28];
	float player[jugadores][6];
	
	generador(fichas);
	
	int arreglo[28];
	nrandom(arreglo, 28);
	
	int k = 0;
	
	for (i = 0; i < jugadores; i++) {
		nrepartir(arreglo, fichas, player[i], &k);	
	}
	printf("%d\n", k);
		
	archivos(fp, nombres[0], player[0]);
	archivos(fp, nombres[1], player[1]);
	
	for (i = 0; i < jugadores; i++) {
		printf("%s\n",nombres[i]);
		for (j = 0; j < 6; j++) {
			printf("%.1f\n", player[i][j]);
		}
	}	
	
}

/* nuevo random */
void nrandom(int arreglo[], int size)
{
	srand(time(NULL));
	int i;
	for (i = 0; i < size; i++) {
		arreglo[i] = i;
	}
	
	for (i = 0; i < size; i++) {
		int tmp = arreglo[i];
		int indice = rand() % size;
		
		arreglo[i] = arreglo[indice];
		arreglo[indice] = tmp;
	}
	
}

/* nuevo repartir v2.0 */
void nrepartir(int arreglo[], float fichas[], float p[], int *k)
{
	int j;
		for (j = 0; j < 6; j++) {
			p[j] = fichas[arreglo[*k]];
			*k += 1;
		}
		

}

//Generador de fichas
void generador(float fichas[])
{
	float k,c;
	int i,j,n,a,b,d;
	for(i=0,k=0,n=0;i<28;i++,k++)
	{
		fichas[i]=(k/10);
		if(k==6) 
		{	
			k=n++;
		}
	}
	for(a=0,b=0,c=0,d=7;a<28;a++,b++)
	{
		if(b==d) 
		{	
			c++;
			b=0;
			d--;
		}
		fichas[a]=(fichas[a]+c);
		//printf("%.1f\n",fichas[a]);
	}
}

/* escribir archivo */
void archivos(FILE *fp, char *nombre, float p[])
{
	strcat(nombre, ".txt");
	
	fp = fopen(nombre, "w");
	
	int i;
	for (i = 0; i < 6; i++) {
		fprintf(fp, "%.1f\n", p[i]);
	}
	
	fclose(fp);
}
