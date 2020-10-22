/*
 * Alumno: Nicolas E. Crivelli
 * Legajo: 1602410
*/
#include "color.h"

//declaración de funciones

Color mezclar(const Color& a, const Color& b){
	Color resultado;

	resultado.r = (a.r + b.r)/2;
	resultado.b = (a.b + b.b)/2;
	resultado.g = (a.g + b.g)/2;

	return resultado;
}

Color mezclarProporciones (const unsigned& pa, const Color& a, const unsigned& pb, const Color& b){
	Color resultado;

	resultado.r = (a.r*pa + b.r*pb)/(pa+pb);
	resultado.b = (a.b*pa + b.b*pb)/(pa+pb);
	resultado.g = (a.g*pa + b.g*pb)/(pa+pb);

	return resultado;
}

Color sumar (const Color& a, const Color& b){
	Color resultado;

	resultado.r = (a.r + b.r < 255) ? (a.r+b.r) : 255;
	resultado.b = (a.b + b.b < 255) ? (a.b+b.b) : 255;
	resultado.g = (a.g + b.g < 255) ? (a.g+b.g) : 255;

	return resultado;
}

Color restar (const Color& a, const Color& b){
	Color resultado;

	resultado.r = (a.r - b.r > 0) ? (a.r-b.r) : 0;
	resultado.b = (a.b - b.b > 0) ? (a.b-b.b) : 0;
	resultado.g = (a.g - b.g > 0) ? (a.g-b.g) : 0;

	return resultado;
}

Color getComplementario (const Color& color){
	Color resultado;

	resultado.r = blanco.r - color.r;
	resultado.b = blanco.b - color.b;
	resultado.g = blanco.g - color.g;

	return resultado;
}

bool isIgual (const Color& a, const Color& b){
	bool resultado;

	resultado = a.r == b.r and a.b == b.b and a.g == b.g;

	return resultado;
}
