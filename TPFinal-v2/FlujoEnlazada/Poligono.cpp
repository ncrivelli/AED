#include "Poligono.h"
#include <iostream>
#include <cmath>

//Definición de funciones

void AddVerticeAlFinal (Poligono& pol, const Punto& pun){

	Punto q = new struct node, t = new struct node;

	q->x = pun->x;
	q->y = pun->y;
	q->siguiente = NULL;

	if(pol.puntos == NULL){
		pol.puntos = q;
	}else{
		t = pol.puntos;

		while(t->siguiente != NULL){
			t = t->siguiente;
		}
		t->siguiente = q;
	}
}

Punto GetVertice (const Poligono& pol, const unsigned& pos){

	Punto aux = pol.puntos;

	for(int i=0; aux != NULL; i++){
		if (i == pos){
			return aux;
		}
		aux = aux->siguiente;
	}
	std::cout << "Posicion no encontrada";
}

void SetVertice (Poligono& pol, const unsigned& pos , const Punto& p){

	Punto aux = pol.puntos;

	for(int i=0; aux != NULL; i++){
		if(i == pos){
			aux->x = p->x;
			aux->y = p->y;
			return;
		}
		aux = aux->siguiente;
	}
	std::cout << "Posicion no encontrada, debe agregar mas puntos";
}

void RemoveUltimoVertice (Poligono & pol){

	Punto aux = pol.puntos;

	if(aux->siguiente == NULL){
		delete(pol.puntos);
	}else{
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		delete(aux);
	}
}

unsigned GetCantidadDeLados (const Poligono& pol){

	Punto aux = pol.puntos;
	unsigned cont = 1;

	if(aux != NULL){
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
			cont++;
		}
		return cont;
	}
	return 0;
}

double GetPerimetro (const Poligono& pol){
	double resultado = 0;
	unsigned lados = GetCantidadDeLados(pol);
	Punto aux = pol.puntos;

	for (int i = 1; i < lados ; i++){	//i comienza en uno ya que si el poligono solo tiene un lado, es que tiene un solo punto, por lo que el perimetro es cero.
    resultado = resultado + GetDistancia(aux, aux->siguiente);
    aux = aux->siguiente;
}
return resultado;
}

bool IsIgual (const Poligono& pol1, const Poligono &pol2){
    Punto aux1 = pol1.puntos;
    Punto aux2 = pol2.puntos;

    if (GetCantidadDeLados(pol1) == GetCantidadDeLados(pol2)){
    	int lados = GetCantidadDeLados(pol1);

    	for (int i = 0; i < lados ; i++){
    		if(aux1->x == aux2->x){
    			if(aux1->y == aux2->y){
    				aux1 = aux1->siguiente;
    				aux2 = aux2->siguiente;
    			}else return false;
    		}else return false;
    	}
    	return true;
    }
}

void MostrarPoligono (const Poligono& pol){
    std::cout <<"El color del poligono en formato rgb es es: " << GetHtmlrgb(pol.c) << "\n";
    std::cout <<"El poligono posee " << GetCantidadDeLados(pol) << " lados" << "\n";
    std::cout <<"Los puntos del poligono son: " <<"\n";

    Punto aux = pol.puntos;
    for (unsigned i = 0; i < GetCantidadDeLados(pol); ++i){
    	MostrarPunto(aux);
    	aux = aux->siguiente;
    };
    std::cout <<"\n";
}
