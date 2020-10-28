/*
 * Alumno: Nicolas E. Crivelli
 * Legajo: 1602410
*/
#include <cassert>
#include <iostream>
#include "Poligono.h"
using namespace std;

int main() {

	Poligono p;

	addVertice({0,0},p);
	addVertice({0,2},p);
	addVertice({2,2},p);
	addVertice({2,0},p);

	assert(getCantidadDeLados(p) == 4);

	assert(getVertice(0,p).x == 0);
	assert(getVertice(0,p).y == 0);

	assert(getVertice(2,p).x == 2);
	assert(getVertice(2,p).y == 2);

	assert(getPerimetro(p) == 8);

	return 0;
}
