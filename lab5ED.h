typedef struct _nodo{
	char dato;
	struct _nodo *hizq, *hder;
}AB;

//arbol
AB *iniciaAB(){
	return NULL;
}
char *incializaArreglo(tamano){
	char *arreglo = malloc(sizeof(char)*tamano);
	return arreglo;
}
Dato *creaArbolEnArreglo(Arbol *unArbol){
	h = altura(unArbol);
	char *arreglo = inicializaArreglo(((2^h)+2)-1);
	copiaArbolenArreglo(unArbol,arreglo,posicion);
	return arreglo;
}

Dato *copiaArbolenArreglo(Arbol UnArbol, Dato *arreglo, int posicion){
	if(UnArbol == NULL){
		arreglo[posicion] = 'N';
	}
	arreglo[posicion] = arbol -> dato;
	copiaArbolenArreglo(unArbol->hizq,arreglo,posicion*2 + 1);
	copiaArbolenArreglo(unArbol->hder,arreglo,posicion*2 + 2);
	return;
}
printf("subiendo archivo")
printf("subiendo archivo")
