/*
 * Alumno: Nicolas E. Crivelli
 * Legajo: 1602410
*/
#include <cmath>
#include "Poligono.h"

void addVertice(const Punto& vertice, Poligono& p){
	p.puntos.push_back(vertice);
}

Punto getVertice(const unsigned& posicion, Poligono& p){
	return p.puntos.at(posicion);
}

void setVertice(const Punto& vertice, const unsigned& posicion, Poligono& p){
	p.puntos.at(posicion).x = vertice.x;
	p.puntos.at(posicion).y = vertice.y;
}

void removeVertice(const unsigned& posicion, Poligono& p){
	p.puntos.erase(p.puntos.begin()+ posicion);
}

int getCantidadDeLados(Poligono& p){
	return p.puntos.size();
}

double getPerimetro(Poligono& p){
	double perimetro = 0;
	int ultimo = getCantidadDeLados(p)-1;

	for (int i=0; i < ultimo; i++){
		perimetro += getDistanciaPuntos(getVertice(i,p), getVertice(i+1,p));
	}
	perimetro += getDistanciaPuntos(getVertice(0,p), getVertice(ultimo,p));

	return perimetro;
}

double getDistanciaPuntos(const Punto& a,const Punto& b){
	Punto aux = restaPuntos(a,b);
	double distancia = sqrt(aux.x * aux.x + aux.y * aux.y);

	return distancia;
}

Punto restaPuntos(const Punto& a,const Punto& b){
	Punto diferencia;

	diferencia.x = a.x - b.x;
	diferencia.y = a.y - b.y;

	return diferencia;
}

bool colorIsIgual (const Color& a, const Color& b){
	return (a.r == b.r and a.b == b.b and a.g == b.g);
}
