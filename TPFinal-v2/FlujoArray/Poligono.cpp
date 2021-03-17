#include "Poligono.h"
#include <iostream>
#include <cmath>

//Definición de funciones

void AddVerticeAlFinal (Poligono& pol, const Punto& pun){
    pol.puntos.at( pol.n ).x = pun.x;
    pol.puntos.at( pol.n ).y = pun.y;
    pol.n ++;
}

Punto GetVertice (const Poligono& pol, const unsigned& pos){
return pol.puntos.at(pos);
}

void SetVertice (Poligono& pol, const unsigned& pos , const Punto& p){
if (pos < pol.n)
 pol.puntos.at( pos ).x = p.x ,
 pol.puntos.at( pos ).y = p.y ;
 else
 std::cout << "Necesita agregar mas puntos al poligono (Use AddVertice)";
}

void RemoveVertice (Poligono & pol){
    pol.n --;
}

unsigned GetCantidadDeLados (const Poligono& pol){
    return pol.n;
}

double GetPerimetro (const Poligono& pol){
double resultado = 0;
for (int i = 0; i < pol.n-1 ; i++){
    resultado = resultado + GetDistancia(pol.puntos.at(i), pol.puntos.at(i+1));
}
return resultado;
}

bool IsIgual (const Poligono& pol1, const Poligono &pol2){
    bool puntos = true;

    for (int i = pol1.n - 1; i >= 0 ; i--)
    puntos = puntos and IsIgualPunto(pol1.puntos.at(i), pol2.puntos.at(i));

    return pol1.n == pol2.n and puntos and IsIgualColor(pol1.c, pol2.c);

}

void MostrarPoligono (const Poligono& pol){
    std::cout <<"El color del poligono en formato rgb es es: " << GetHtmlrgb(pol.c) << "\n";
    std::cout <<"El poligono posee " << GetCantidadDeLados(pol) << " lados" << "\n";
    std::cout <<"Los puntos del poligono son: " <<"\n";

    for (unsigned i = 0; i < pol.n; ++i) MostrarPunto(pol.puntos.at(i));

    std::cout <<"\n";
}
