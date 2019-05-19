#include"lab5ED.h"

void main(){
  FILE *p;
	AB *unArbol;
  p = fopen("textoArbol.txt","r");
  unArbol = malloc(sizeof(AB));
  unArbol = creaArbol(p);
  //char *arreglo = inicializaArreglo(15);
  /*arreglo = */creaArbolEnArreglo(unArbol);
  imprimirArbol(unArbol, 0);
  fclose(p);
}
