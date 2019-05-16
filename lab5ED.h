#include<stdio.h>
#include<stdlib.h>

typedef struct _nodo{
	char dato;
	struct _nodo *hizq, *hder;
}AB;

//prototipos
AB *iniciaAB();
char *inicializaArreglo(int);
int max(int, int);
int alturaArbol(AB *);
char *copiaArbolenArreglo(AB *, char *, int, int);
char *creaArbolEnArreglo(AB *);
AB *creaArbol(FILE *);

//arbol
AB *iniciaAB(){
	return NULL;
}

AB *creaNodo(char c){
	AB *nuevo;
	nuevo = malloc(sizeof(AB));
	nuevo->dato = c;
	nuevo->hizq = NULL;
	nuevo->hder = NULL;
	return nuevo;
}

AB *creaArbol(FILE *p){
	char c;
	if(feof(p)){
		return NULL;
	}
	c = fgetc(p);
	if(c == 'N'){
		return NULL;
	}
	else{
		AB *nuevoArbol = creaNodo(c);
		nuevoArbol->hizq = creaArbol(p);
		nuevoArbol->hder = creaArbol(p);
		return nuevoArbol;
	}
}

void imprimirArbol(AB *arbol, int cont){
	if(arbol == NULL){
		return;
	}
	else{
		imprimirArbol(arbol->hder,cont+1);
		for(int i = 0; i < cont; i++){
			printf("  ");
		}
		printf("%c\n",arbol->dato);
		imprimirArbol(arbol->hizq,cont+1);
	}
}

int max(int a, int b){
	if(a > b){
		return (a);
	}
	return (b);
}

int alturaArbol(AB *unArbol){
	if(unArbol == NULL){
		return (-1);
	}
	return (1 + max(alturaArbol(unArbol->hizq),alturaArbol(unArbol->hder)));
}

char *inicializaArreglo(int tamano){
	char *arreglo = malloc(sizeof(char)*tamano);
	return arreglo;
}

char *copiaArbolenArreglo(AB *unArbol, char *arreglo, int posicion, int tamanoMax){
	if(unArbol == NULL){
		arreglo[posicion] = 'N';
	}
	arreglo[posicion] = unArbol->dato;
	copiaArbolenArreglo(unArbol->hizq,arreglo,posicion*2 + 1,tamanoMax);
	copiaArbolenArreglo(unArbol->hder,arreglo,posicion*2 + 2,tamanoMax);
	printf("\n");
	/*for(int i = 0; i < tamanoMax; i++){
		printf("[%i] ", arreglo[i]);
	}*/
	return arreglo;
}
char *creaArbolEnArreglo(AB *unArbol){
	printf("\nentra\n");
	int h, tamanoMax,posicion;
	h = alturaArbol(unArbol);
	//printf("\naltura: %i\n",h);
	tamanoMax = ((2^h)+2)-1;
	char *arreglo = inicializaArreglo(tamanoMax);
	copiaArbolenArreglo(unArbol,arreglo,posicion,tamanoMax);
	return arreglo;
}
