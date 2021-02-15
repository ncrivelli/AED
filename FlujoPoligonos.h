//============================================================================
// Name        : FlujoPoligonos.h
// Author      : Nicolas Crivelli
// Version     :
// Copyright   : AED 2020
// Description : forma parte del proyecto Flujo Pol�gonos
//============================================================================

#pragma once
#include <array>
#include <cstdint>
#include <string>
#include <iostream>

struct Punto{double x,y;};

struct Color {uint8_t r, g, b ;};

struct Poligono {
    unsigned n;
    std::array <Punto, 20> puntos;
    Color c;};

void MostrarPunto(Punto); //Imprime por salida estandar un punto en formato x,y

std::string GetHtmlrgb (Color); //Muestra el color

bool ExtraerPunto(std::istream&, Punto&); //Lee un punto con formato x,y desde un flujo de entrada

bool ExtraerPuntos(std::istream&, Poligono&);

bool ExtraerColor(std::istream&, Color&); //Lee un color con formato r,g,b desde un flujo de entrada

bool ExtraerPoligono(std::istream&, Poligono&); //Extrae un poligono con sus elementos (color y puntos) desde un flujo de entrada

bool ExtraerPoligonos(std::istream&); //Repite la función ExtraerPoligono las veces posibles y muestra los resultados en pantalla

void MostrarPoligono(const Poligono&); //Muestra por pantalla un poligono

void AddVertice (Poligono&, const Punto&); //Agrega al final del array de puntos del poligono el punto ingresado en el argumento

bool EnviarPunto(std::ostream&, Punto); //Envia las coordenadas de un punto por un flujo de salida

bool EnviarColor(std::ostream&, Color); //Envia las componentes de un color por un flujo de salida

bool EnviarPoligono(std::ostream&, const Poligono&); //Envia un color y una serie de puntos correspondientes a un poligono por un flujo de salida

bool ExtraerSeparador (std::istream& in ); //Limpia el flujo de entrada y extrae el caracter '#' utilizado para separar los poligonos

double GetPerimetro (const Poligono&); //Retorna un double correspondiente al per�metro del pol�gono ingresado

double GetDistancia(Punto,  Punto); //Retorna el valor de la distancia entre dos puntos

Punto RestarPuntos(Punto , Punto); //Retorna el punto resultado de restar ambos

bool IOPoligonoCondicionado (std::istream&, std::ostream&, double); //Extrae poligonos de un flujo de entrada y los que cumplen con la condicion del 3er argumento se envian por un flujo de salida
