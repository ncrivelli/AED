/*
 * Alumno: Nicolas E. Crivelli
 * Legajo: 1602410
*/
#include <cassert>
#include "Punto.h"
using namespace std;

int main() {

	//pruebas para isIgual
	assert(!isIgual({2,9},{8,4}));
	assert(isIgual({2,9},{2,9}));

	//pruebas para getDistancia
	assert(!(getDistancia({3,1},{2,7}) == 9));
	assert(getDistancia({0,1},{3,5}) == 5);

	//pruebas para getDistanciaAlOrigen
	assert(getDistanciaAlOrigen({0,7}) == 7);
	assert(getDistanciaAlOrigen({11,0}) != 6);

	return 0;
}
