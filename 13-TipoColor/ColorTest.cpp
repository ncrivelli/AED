/*
 * Alumno: Nicolas E. Crivelli
 * Legajo: 1602410
*/
#include "color.h"
#include <cassert>

int main(){

	//pruebas mezclar
	assert (isIgual(mezclar(rojo,verde), {127,127,0}));
	assert (isIgual(mezclar(rojo, azul), {127,0,127}));
	assert (isIgual(mezclar(blanco, negro), {127,127,127}));

	//prueba mezclarProporciones
	assert (isIgual(mezclarProporciones(2, rojo, 4, verde), {85,170,0}));
	assert (isIgual(mezclarProporciones(1, azul, 4, amarillo), {204,204,51}));

	//pruebas sumar
	assert(isIgual(sumar(magenta, amarillo), {255,255,255}));
	assert(isIgual(sumar(azul, rojo), {255,0,255}));

	//pruebas restar
	assert(isIgual(restar(verde, cyan), {0,0,0}));
	assert(isIgual(restar(amarillo, negro), {255,255,0}));

	//pruebas getComplementario
	assert(isIgual(getComplementario(rojo), {0,255,255}));
	assert(isIgual(getComplementario(magenta), {0,255,0}));

	return 0;
}
