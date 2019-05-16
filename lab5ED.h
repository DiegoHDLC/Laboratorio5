typedef struct _nodo{
	char dato;
	struct _nodo *hizq, *hder;
}AB;

typedef struct _arreglo{
	char contenido;
}Dato;

//prototipos
AB *iniciaAB();
char *inicializaArreglo(int);
int max(int, int);
int alturaArbol(AB *);
Dato *copiaArbolenArreglo(AB *, Dato *, int);
Dato *creaArbolEnArreglo(AB *);

//arbol
AB *iniciaAB(){
	return NULL;
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

char *incializaArreglo(int tamano){
	char *arreglo = malloc(sizeof(char)*tamano);
	return arreglo;
}

Dato *copiaArbolenArreglo(AB *UnArbol, Dato *arreglo, int posicion){
	if(UnArbol == NULL){
		arreglo[posicion]->contenido = 'N';
	}
	arreglo[posicion]->contenido = arbol->dato;
	copiaArbolenArreglo(unArbol->hizq,arreglo,posicion*2 + 1);
	copiaArbolenArreglo(unArbol->hder,arreglo,posicion*2 + 2);
	return arreglo;
}
Dato *creaArbolEnArreglo(AB *unArbol){
	h = alturaArbol(unArbol);
	char *arreglo = inicializaArreglo(((2^h)+2)-1);
	copiaArbolenArreglo(unArbol,arreglo,posicion);
	return arreglo;
}
