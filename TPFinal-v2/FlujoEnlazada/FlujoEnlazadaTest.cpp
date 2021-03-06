//============================================================================
// Name        : FlujoEnlazada.cpp
// Author      : Nicolas Crivelli
// Version     :
// Copyright   : AED 2020
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "FlujoEnlazada.h"
#include <fstream>
#include <cassert>

int main(){

    Poligono pol1;
    pol1.puntos = NULL;
    pol1.c = rojo;
    AddVerticeAlFinal (pol1, CrearPunto(0,0));
    AddVerticeAlFinal (pol1, CrearPunto(1,0));
    AddVerticeAlFinal (pol1, CrearPunto(1,1));
    AddVerticeAlFinal (pol1, CrearPunto(0,1));

    Poligono pol2;
    pol2.puntos = NULL;
    pol2.c = verde;
    AddVerticeAlFinal (pol2, CrearPunto(0,0));
    AddVerticeAlFinal (pol2, CrearPunto(1,0));
    AddVerticeAlFinal (pol2, CrearPunto(0,2));
    AddVerticeAlFinal (pol2, CrearPunto(1,1));

    Poligono pol3;
    pol3.puntos = NULL;
    pol3.c = verde;
    AddVerticeAlFinal (pol3, CrearPunto(0,0));
    AddVerticeAlFinal (pol3, CrearPunto(1,0));
    AddVerticeAlFinal (pol3, CrearPunto(0,2));
    AddVerticeAlFinal (pol3, CrearPunto(1,1));
    AddVerticeAlFinal (pol3, CrearPunto(3,4));

    std::ofstream ofs; //la clase ofstream instancia un objeto búfer de flujo interno, que realiza operaciones de entrada/salida

    ofs.open("datos.txt");
    EnviarPoligono(ofs, pol1);
    EnviarPoligono(ofs, pol2);
    EnviarPoligono(ofs, pol3);
    ofs.close();

    std::ifstream inAutomatico ("datos.txt"); //La clase ifstream es similar a ofstream,
    										  //la diferencia esta en que ofstream se usa para escribir archivos y ifstream para leerlos
    ExtraerPoligonos(inAutomatico); //Usa los datos enviados al archivo mediante EnviarPoligono de forma automática

    std::ifstream inManual ("datos2.txt");  //Usa un archivo creado con anterioridad de forma manual
    ExtraerPoligonos(inManual);

    std::ofstream out;
    std::ifstream inCond ("poligonosafiltrar.txt");

    double perimetroFilter = 20;

    out.open("resultados.txt");
    IOPoligonoCondicionado(inCond, out, perimetroFilter); //Lee y envía los poligonos de perimetro mayor a 20
    out.close();

    std::ifstream inAlm("resultados.txt");
	return 0;
}
