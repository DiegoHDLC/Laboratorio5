#include"lab5ED.h"

void main(){
  FILE *p;
	AB *unArbol;
  int h,tamano;
  p = fopen("textoArbol.txt","r");
  unArbol = malloc(sizeof(AB));
  unArbol = creaArbol(p);
  h = alturaArbol(unArbol);
  tamano = (pow(2,h+2))-1;
  char *arreglo = inicializaArreglo(tamano);
  arreglo = creaArbolEnArreglo(unArbol);
  imprimirArreglo(tamano,arreglo);
  imprimirArbol(unArbol, 0);
  fclose(p);
}
