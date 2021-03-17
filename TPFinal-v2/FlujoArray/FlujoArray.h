//============================================================================
// Name        : FlujoPoligonos.h
// Author      : Nicolas Crivelli
// Version     : Con Arrays
// Copyright   : AED 2020
// Description : forma parte del proyecto Flujo Pol�gonos
//============================================================================

#pragma once
#include "Poligono.h"
#include <iostream>
#include <array>

struct NodoPoligono;

struct ListaPoligonos{
    NodoPoligono* PrimerPoligono = nullptr;
};

struct ClasifPoligonosPorPerimetro{
    double limiteinferior, limitesuperior;
    std::array <ListaPoligonos, 3> Listas;
};

bool ExtraerPunto(std::istream&, Punto&); //Lee de un flujo de entrada las coordenadas x e y de un punto

bool ExtraerPuntos(std::istream&, Poligono&); //Repite la accion de ExtraerPunto para poder extraer varios puntos juntos

bool ExtraerColor(std::istream&, Color&); //Extrae los valores correspondientes a r, g y b de un color

bool ExtraerPoligono(std::istream&, Poligono&); //Extrae un color y una serie de puntos de un flujo de entrada y las almacena en un poligono

bool ExtraerPoligonos(std::istream&); //Extrae todos los poligonos que puede extraer de un flujo de entrada y los muestra por pantalla.

bool EnviarPunto(std::ostream&, Punto); //Envia las coordenadas de un punto por un flujo de salida

bool EnviarColor(std::ostream&, Color); //Envia las componentes de un color por un flujo de salida

bool EnviarPoligono(std::ostream&, const Poligono&); //Envia un color y una serie de puntos correspondientes a un poligono por un flujo de salida

bool ExtraerSeparador (std::istream&); //Limpia el flujo de entrada y extrae el caracter '#' utilizado para separar los poligonos

bool IOPoligonoCondicionado (std::istream&, std::ostream&, double); //Lee poligonos de un flujo de entrada y luego envía por un flujo de salida los que tengan un perimetro mayor al pasado al argumento

void AddPoligono (ListaPoligonos &, const Poligono&); //Añade el poligono al comienzo de la lista

bool ExtraerYAlmacenarPoligonos (std::istream&, ListaPoligonos&); //Extrae poligonos de un flujo de entrada y los almacena en la lista pasada al argumento

void MostrarLista (const ListaPoligonos&); //Muestra por pantalla el contenido de la lista

void LiberarMemoriaLista (ListaPoligonos&); //Libera la reserva en memoria heap de los poligonos de la lista

void RemoveFirstPoligono (ListaPoligonos&); //Remueve el primer poligono de la lista liberando la reserva en memoria heap

void ClasificarListaPorPerim (ListaPoligonos&, ClasifPoligonosPorPerimetro&, double, double); //Clasifica los poligonos de la lista y los almacena en una estructura que los divide segun su perimetro en 3 categorias dependiendo de los valores reales pasados al argumento

void MostrarListaClasificada (const ClasifPoligonosPorPerimetro&); //muestra por pantalla la clasificacion almacenada

bool IsEmpty(const ListaPoligonos&); //Retorna true si la lista esta vacía o false e.o.c

unsigned ListLength (const ListaPoligonos& lista); //Retorna un numero natural correspondiente a la cantidad de poligonos almacenados

bool IsIgualLista (const ListaPoligonos&, const ListaPoligonos&); //Compara los poligonos de las listas retornando true en caso de ser iguales y false e.o.c

void LiberarMemoriaClasif (ClasifPoligonosPorPerimetro&);//Remueve todos los poligonos de las listas de la clasificacion

bool IsEmptyClasif (const ClasifPoligonosPorPerimetro&);//Retorna un booleano true si las listas de la clasificación están vacias y false e.o.c
