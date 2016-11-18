#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void archivo(char nombres[], float player[]);
void generador(float fichas[]);
void nrandom(int arreglo[], int size);
void nrepartir(int arreglo[], float fichas[], float p[], int *k);

main()
{
	int i,j;
	int jugadores = 4;
	float fichas[28], p1[6];
	float player[jugadores][6];
	generador(fichas);
	
	int arreglo[28];
	nrandom(arreglo, 28);
	
	int k = 0;
	for (i = 0; i < 4; i++) {
		nrepartir(arreglo, fichas, player[i], &k);	
	}
	printf("%d\n", k);
		
	
	for (i = 0; i < 4; i++) {
		printf("Jugador %d\n", i+1);
		for (j = 0; j < 6; j++) {
			printf("%.1f\n", player[i][j]);
		}
		archivo();
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

void archivo(char nombres[], float player[])
{
	int i;
	FILE *fe;
	strcat(nombres, ".txt");
	fe=fopen(nombres,"w");
	for (i=0;i<6;i++)
	{
		fprintf(fe,"%.1f",player[i]);
	}
	
}



