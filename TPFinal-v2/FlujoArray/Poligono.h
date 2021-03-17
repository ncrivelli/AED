#pragma once
#include "Punto.h"
#include "Color.h"
#include <array>

struct Poligono {
    unsigned n = 0;
    std::array <Punto, 20> puntos;
    Color c;
};

// Funciones de Polígono
void AddVerticeAlFinal (Poligono&, const Punto&); //Agrega al final del array de puntos del poligono el punto ingresado en el argumento

Punto GetVertice (const Poligono&, const unsigned&); //Retorna el valor del Punto del poligono ubicado en la posicion indicada

void SetVertice (Poligono &, const unsigned& , const Punto&); //Setea el valor del punto ingresado en la posicion indicada

void RemoveVertice (Poligono &); //Quita el punto en la ultima posición del polígono ingresado como argumento

unsigned GetCantidadDeLados (const Poligono&); //Retorna la cantidad de lados que posee el polígono ingresado (coincide con la cantidad de vertices)

double GetPerimetro (const Poligono&); //Retorna un double correspondiente al perímetro del polígono ingresado

bool IsIgual (const Poligono&, const Poligono&); //Retorna un booleano true si los dos polígonos ingresados son iguales o false si no lo son

void MostrarPoligono(const Poligono&);
