#include <stdio.h>
#include <stdlib.h>

int main()
{
	char szDatos[286][40];
	int numericos1, numericos2, diferencia;
	char szNombre[20];
	char aux = '\0', porcent = '%';
	int i = 0, j = 0, k = 0;
	int mes1, mes2;
	float prom[5], promFin;
	int otraVez = 1;

	//Abre el archivo
	FILE* fp;
	printf("Inserte el nombre y extension del archivo: ");
	gets_s(szNombre, 19);

	fopen_s(&fp, szNombre, "r");
	if (fp == NULL)
	{
		printf("No fue posible abrir el archivo");
	}

	while (!feof(fp)) //Mientras no se llegue al fin del archivo
	{
		aux = fgetc(fp); //Auxiliar toma el caracter


		if (aux != '\"') {
			if (aux != ',') {
				szDatos[i][j] = aux; //Si no son comillas y no es una coma guarda el caracter en el arreglo
				j++;
			}
			else {
				if (k == 2) { //Si encuentra una coma y ya habia encontrado dos comillas
					szDatos[i][j] = '\0';
					i++;
					j = 0;
					k = 0;
				}
				else { //Si encuentra la coma y no hubo comillas
					if (k == 0) {
						szDatos[i][j] = '\0';
						i++;
						j = 0;
					}
				}
			}
		}
		else { //Si son comillas incrementa k
			k++;
		}

	}

	printf("\n\n\t    ---- PRESENCIA EN LAS REDES TWITTER, FACEBOOK Y YOUTUBE ----\n\n");
	i = 0;
	while (285 > i) //Para imprimir todos los arreglos
	{
		printf("%s /", szDatos[i]);
		i++;
	}

	//Diferencia de seguidores en Twitter
	numericos1 = atoi(szDatos[128]);
	numericos2 = atoi(szDatos[123]);
	diferencia = numericos1 - numericos2;
	printf("\n\n -----> Diferencia de seguidores (followers) en Twitter entre enero y junio: %i seguidores", diferencia);

	//Diferencia entre los meses seleccionados
	while (otraVez == 1)
	{
		printf("\n\n -----> Diferencia de visualizaciones de YouTube, seleccione el numero de los meses a comparar:\n");
		printf("         | Enero: 1 | Febrero: 2 | Marzo: 3 | Abril: 4 |  Mayo: 5 | Junio: 6 |");
		printf("\n\n\tMes a comparar 1: ");
		scanf_s("%i", &mes1);
		if (mes1 == 1 || mes1 == 2 || mes1 == 3 || mes1 == 4 || mes1 == 5 || mes1 == 6) {
			printf("\n\tMes a comparar 2: ");
			scanf_s("%i", &mes2);
			if (mes2 == 1 || mes2 == 2 || mes2 == 3 || mes2 == 4 || mes2 == 5 || mes2 == 6) {
				numericos1 = atoi(szDatos[242 + mes1]);
				numericos2 = atoi(szDatos[242 + mes2]);
				diferencia = numericos1 - numericos2;
				printf("\n        Diferencia de visualizaciones en YouTube entre el mes %i y el mes %i: %i visualizaciones", mes1, mes2, diferencia);
				printf("\n\n        Desea hacer otra comparacion? Pulse 1 = Si | 2 = No \n        Respuesta:");
				scanf_s("%i", &otraVez);
			}
			else {
				printf("\t[ERROR: Seleccione una opcion valida]\n\n");
			}
		}
		else {
			printf("\t[ERROR: Seleccione una opcion valida]\n\n");
		}
	}

	//Promedio de crecimineto de Facebook y Twitter
	for (i = 0; i < 5; i++) {
		numericos1 = atof(szDatos[33 + i]);
		numericos2 = atof(szDatos[33 + 1 + i]);
		prom[i] = (numericos2 - numericos1);
		prom[i] = prom[i]/numericos1;
		prom[i] = prom[i] * 100;
	}
	promFin = (prom[0] + prom[1] + prom[2] + prom[3] + prom[4]) / 5;
	numericos1 = 0;
	numericos2 = 0;
	printf("\n\n -----> Promedio de crecimiento de Facebook de enero a junio: %.2f%c", promFin, porcent);

	for (i = 0; i < 5; i++) {
		numericos1 = atof(szDatos[138 + i]);
		numericos2 = atof(szDatos[138 + 1 + i]);
		prom[i] = (numericos2 - numericos1);
		prom[i] = prom[i] / numericos1;
		prom[i] = prom[i] * 100;
	}
	promFin = (prom[0] + prom[1] + prom[2] + prom[3] + prom[4]) / 5;

	printf("\n        Promedio de crecimiento de Twitter de enero a junio: %.2f%c\n\n", promFin, porcent);
}
