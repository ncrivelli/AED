/*
 * Alumno: Nicolas E. Crivelli
 * Legajo: 1602410
*/
#include <cmath>
#include "Punto.h"

bool isIgual (const Punto& a, const Punto& b){
	return a.x == b.x and a.y == b.y;
}

double getDistancia (const Punto& a, const Punto& b){
	Punto aux;
	double distancia;

	aux.x = a.x - b.x;
	aux.y = a.y - b.y;

	distancia = sqrt(aux.x * aux.x + aux.y * aux.y);

	return distancia;
}

double getDistanciaAlOrigen(const Punto& a){
	double distancia;

	distancia = sqrt(a.x * a.x + a.y * a.y);

	return distancia;
}
