#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define NOMBRE 20
typedef struct{
	char nombre[250];
	int nota[100];
}nombre;

typedef struct{
	char pregunta[250];
	char opcion1[250];
	char opcion2[250];
	char opcion3[250];
	char opcion4[250];
	char correcta[250];
}Pregunta;


//Funcion en la que haremos un examen completo con las preguntas;
void comenzar_con_examen(Pregunta* preguntas);

//Funcion en la que haremos un examen por temas
void comenzar_examen_por_temas(Pregunta* preguntas);


//Funcion que nos va a mostrar las preguntas de un tema en concreto
void ver_preguntas_tema_concreto(Pregunta* preguntas);


//Funcion que llena la estructura de datos
void llenar_estructuras(Pregunta* preguntas);


int main(){
	
	int op;
	nombre p[NOMBRE];
	Pregunta preguntas[50];
	llenar_estructuras(preguntas);
	
	
	
	
	while(op!=4){
		printf("-----------Elija la opcion que quiera hacer-----------\n");
		printf("[1] Hacer examen con preguntas aleatorias\n");
		printf("[2] Hacer examen de un tema en concreto\n");
		printf("[3] Ver las preguntas de un tema en concreto\n");
		printf("[4] Salir\n");
		scanf("%d", &op);
		
		system("cls");
		
		switch(op){
			case 1: comenzar_con_examen(preguntas);break;
			case 2: comenzar_examen_por_temas(preguntas);break;
			case 3: ver_preguntas_tema_concreto(preguntas);break;
			case 4: break;			
	       }
	
	}	
	return 0;
}




void llenar_estructuras(Pregunta* preguntas){
	

	FILE* fPointer;
	
	fPointer = fopen("tema1.txt","r");
	char linea[250];
	int i =0,j=5;
	
	
	while(!feof(fPointer)){
		
		j++;
		fgets(linea,250,fPointer);
		if(j%6==0){
			
		strcpy(preguntas[i].pregunta,linea);
		}else if(j%6==1){
			strcpy(preguntas[i].opcion1,linea);
		}else if(j%6==2){
			strcpy(preguntas[i].opcion2,linea);
		}else if(j%6==3){
			strcpy(preguntas[i].opcion3,linea);
		}else if(j%6==4){
			strcpy(preguntas[i].opcion4,linea);
		}else if(j%6==5){
			strcpy(preguntas[i].correcta,linea);
			i++;
		}
	}
	fclose(fPointer);
}


void comenzar_con_examen(Pregunta* preguntas){
	
        nombre p[NOMBRE];
	int puntuacion = 0,i,numero_aleatorio;
	char eleccion[5];
	srand(time(NULL));		
	
	printf("Introduce tu nombre: ");
	scanf("%s",p[0].nombre);
	
	system("cls");
	
	printf("Pulse una tecla para comenzar");
	
	getch();
	
	system("cls");
	
	printf("COMIENZA EL EXAMEN\n\n");
	
	
	/*En esta parte se muestran las preguntas por pantalla y se le pide al usuario la solucion*/
	
		for(i = 0; i<10;i++){
		numero_aleatorio = rand() % 10+1;
		printf("%s\n",preguntas[numero_aleatorio].pregunta);
		printf("a) %s\n",preguntas[numero_aleatorio].opcion1);
		printf("b) %s\n",preguntas[numero_aleatorio].opcion2);
		printf("c) %s\n",preguntas[numero_aleatorio].opcion3);
		printf("d) %s\n",preguntas[numero_aleatorio].opcion4);
		
		/*Hacemos un do while para que solo se puedan introducir numeros del 1 al 4*/
		do{
			printf("Introduce la opcion correcta -> ");
			scanf("%s",&eleccion);	
			if(!strcmp(eleccion,"a") == 0 && !strcmp(eleccion,"b") == 0 && !strcmp(eleccion,"c") == 0 && !strcmp(eleccion,"d") == 0){	
				printf("Debes introducir una opción correcta\n");
			}
		}while(!strcmp(eleccion,"a") == 0 && !strcmp(eleccion,"b") == 0 && !strcmp(eleccion,"c") == 0 && !strcmp(eleccion,"d") == 0);
		
		strcat(eleccion,"\n");
		
		
		if(strcmp(eleccion,preguntas[i].correcta)==0){
			puntuacion++;
		}
			
		system("cls");
	
	}
	
	system("cls");
	
	printf("%s, tu nota es ",p[0].nombre);
	printf("%i/10\n",puntuacion);
	printf("Pulse una tecla para continuar");
	
	getch();
	
	system("cls");
}


void comenzar_examen_por_temas(Pregunta* preguntas){
	
		int op,i,puntuacion=0;
		char eleccion[5];
		nombre p[NOMBRE];
	
	printf("Introduce tu nombre: ");
	scanf("%s",p[0].nombre);
	
	system("cls");
		//Hacemos un do while para elegir siempre una opcion dentro de las existentes
		do{
			printf("Elige el tema del que quieres hacer el examen\n");
			printf("Tema 1\n");
			printf("Tema 2\n");
			printf("Tema 3\n");
			printf("Tema 4\n");
			printf("Tema 5\n");

			scanf("%d",&op);	
		}while(op < 1 || op>5);
		
		system("cls");
		
		printf("Has elegido hacer las preguntas del tema %d\n",op);
		printf("Pulse unaa tecla para comenzar");
	
	        getch();
	system("cls");
		for(i = (op*10)-10; i<op*10;i++){
		printf("%s\n",preguntas[i].pregunta);
		printf("a) %s\n",preguntas[i].opcion1);
		printf("b) %s\n",preguntas[i].opcion2);
		printf("c) %s\n",preguntas[i].opcion3);
		printf("d) %s\n",preguntas[i].opcion4);
		
		/*Hacemos un do while para que solo se puedan introducir números del 1 al 4*/
		do{
			printf("Introduce la opcion correcta -> ");
			scanf("%s",&eleccion);	
			if(!strcmp(eleccion,"a") == 0 && !strcmp(eleccion,"b") == 0 && !strcmp(eleccion,"c") == 0 && !strcmp(eleccion,"d") == 0){	
				printf("Debes introducir una opción correcta\n");
			}
		}while(!strcmp(eleccion,"a") == 0 && !strcmp(eleccion,"b") == 0 && !strcmp(eleccion,"c") == 0 && !strcmp(eleccion,"d") == 0);
		
		strcat(eleccion,"\n");
		
		
		if(strcmp(eleccion,preguntas[i].correcta)==0){
			puntuacion++;
		}
		system("cls");
	}
	system("cls");
	
	printf("%s, tu nota es ",p[0].nombre);
	printf("%i/10\n",puntuacion);
	printf("Pulse una tecla para continuar");
	
	getch();
	
	system("cls");
}


void ver_preguntas_tema_concreto(Pregunta* preguntas){
	

	
		int op,i;
		char siguiente;
		
		//Hacemos un do while para elegir siempre una opción dentro de las existentes
		do{
			printf("Elige el tema del que quieres ver las preguntas\n");
			printf("Tema 1\n");
			printf("Tema 2\n");
			printf("Tema 3\n");
			printf("Tema 4\n");
			printf("Tema 5\n");
			scanf("%d",&op);	
		}while(op < 1 || op>5);
		
	
		printf("Has elegido hacer las preguntas del tema %d\n",op);
		
	system("cls");
		for(i = (op*10)-10; i<op*10;i++){
		printf("%s\n",preguntas[i].pregunta);
		printf("%s\n",preguntas[i].opcion1);
		printf("%s\n",preguntas[i].opcion2);
		printf("%s\n",preguntas[i].opcion3);
		printf("%s\n",preguntas[i].opcion4);
		printf("---------------------------------\n");
		printf("Pulse una tecla para continuar");
		getch();
		
		system("cls");
	}
}
