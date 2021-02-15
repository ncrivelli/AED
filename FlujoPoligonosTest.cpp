//============================================================================
// Name        : FlujoPoligonosTest.cpp
// Author      : Nicolas Crivelli
// Version     :
// Copyright   : AED 2020
// Description : forma parte del proyecto Flujo Pol�gonos
//============================================================================

#include "FlujoPoligonos.h"
#include <fstream>

int main(){
    std::ofstream ofs;
    Poligono pol1{
        3,
        {2,3, 9,2, 1.0,3},
        {255,255,255}
    };
    Poligono pol2{
        4,
        {9,0, 13,4, 0,2.3, 1,1.5},
        {125,125,125}
    };

    Poligono pol3{
        4,
        {1,0, 1,4, 2,2.3, 5,1.5},
        {0,125,255}
    };

    ofs.open("datos.txt");
    EnviarPoligono(ofs, pol1);
    EnviarPoligono(ofs, pol2);
    EnviarPoligono(ofs, pol3);
    ofs.close();

    std::ifstream inAutomatico ("datosGenerado.txt"); //Muestra los poligonos del archivo generado anteriormente
    ExtraerPoligonos(inAutomatico);

    std::ifstream inManual ("datosManual.txt");  //Muestra los poligonos de un archivo local cargado manualmente
    ExtraerPoligonos(inManual);

    std::ofstream out;
    std::ifstream inCond ("poligonos.txt");

    double perimetroFilter = 15;

    out.open("resultados.txt");
    IOPoligonoCondicionado(inCond, out, perimetroFilter);
    out.close();

    std::cout << "Fin.";

    return 0;
}
