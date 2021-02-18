//============================================================================
// Name        : FlujoPoligonos.cpp
// Author      : Nicolas Crivelli
// Version     : Con Arrays
// Copyright   : AED 2020
// Description : forma parte del proyecto Flujo Pol�gonos
//============================================================================

#include "FlujoArray.h"
#include <cmath>

struct NodoPoligono{
    Poligono Pol;
    NodoPoligono* NextPol;
};


//Funciones Extraer

bool ExtraerColor(std::istream& in, Color& c){
    short aux;
    in >> aux;
    c.r = aux;
    in >> aux;
    c.g = aux;
    in >> aux;
    c.b = aux;
    return bool (in);
}

bool ExtraerPunto(std::istream& in, Punto& p){
    in >> p.x;
    in >> p.y;

   return bool (in);
}

bool ExtraerPuntos(std::istream& in, Poligono& pol){
    pol.n = 0;
    for(Punto p; ExtraerPunto(in, p);){
        AddVerticeAlFinal (pol, p);
    }

return bool (in);
}

bool ExtraerPoligono(std::istream& in, Poligono& pol){
    ExtraerColor(in, pol.c);
    ExtraerPuntos(in, pol);
    return ExtraerSeparador(in);

}

bool ExtraerPoligonos(std::istream& in){
   for (Poligono pol; ExtraerPoligono(in, pol); ){
       MostrarPoligono(pol);
    }

   return not in.fail();
}

bool ExtraerSeparador (std::istream& in ){
    in.clear (); //Limpia el estado del flujo de entrada, en otro caso el booleano seguia dando falso, lo que no permitía extraer varios poligonos
    char c{'@'}; //Inicializo la variable con un valor distinto para poder verificar que se extrae el caracter deseado
    in >> c;
    return c == '#' and in;
}

//Funciones Enviar

bool EnviarPunto(std::ostream& os, Punto p){
 os << p.x << ' ' << p.y << ' ' ;
 return bool (os);
}

bool EnviarColor(std::ostream& os, Color c){
    os << static_cast <int> (c.r) << ' ' << static_cast <int> (c.g) << ' ' << static_cast <int> (c.b) << ' ' ; //El static cast es necesario para que interprete a las coordenadas rgb como numeros y no como caracteres ya que al ocupar 1 byte se considera como un caracter en codigo ascii de forma automática
    return bool (os);
}

bool EnviarPoligono(std::ostream& os, const Poligono& pol){
    EnviarColor(os, pol.c);

    for(unsigned i = 0; i < pol.n; ++i) EnviarPunto(os, pol.puntos.at(i));
    os << "# " <<"\n" ;
    return bool (os);
}


//Funciones para poder extraer y enviar polígonos con condición (perimetro mayor a uno dado)

bool IOPoligonoCondicionado (std::istream& in, std::ostream& out, double perimcond){
     for (Poligono pol; ExtraerPoligono(in, pol); ){
        if(GetPerimetro(pol) > perimcond) EnviarPoligono(out, pol);
    }

   return not in.fail();
}

//Funciones para ListaPoligonos

void MostrarLista(const ListaPoligonos& lista){
    for (auto aux = lista.PrimerPoligono; aux; aux = aux->NextPol) MostrarPoligono (aux->Pol);
}

void RemoveFirstPoligono (ListaPoligonos& lista){
    auto aux = lista.PrimerPoligono;
    lista.PrimerPoligono = lista.PrimerPoligono->NextPol;
    delete aux;
}

void LiberarMemoriaLista (ListaPoligonos& lista){
    while (lista.PrimerPoligono != nullptr) RemoveFirstPoligono(lista);
}

void AddPoligono(ListaPoligonos& lista, const Poligono& pol){
    auto n = new NodoPoligono; //probar
    n->Pol.c.r = pol.c.r;
    n->Pol.c.g = pol.c.g;
    n->Pol.c.b = pol.c.b;
    for(unsigned i = 0; i < pol.n; ++i) AddVerticeAlFinal(n->Pol, pol.puntos.at(i));
    n->NextPol = lista.PrimerPoligono;

    lista.PrimerPoligono = n;

}

bool ExtraerYAlmacenarPoligonos(std::istream& in, ListaPoligonos& lista){
    for (Poligono pol; ExtraerPoligono(in, pol); ){
       AddPoligono(lista, pol);
       }

   return not in.fail();
}

void MostrarListaClasificada (const ClasifPoligonosPorPerimetro& clasif){

    if (clasif.Listas.at(0).PrimerPoligono == nullptr) std::cout << "No hay poligonos con perimetro menor a " << clasif.limiteinferior << "\n";
    else {
        std::cout << "Los poligonos con perimetro menor a " << clasif.limiteinferior << " son: " << "\n";
        MostrarLista(clasif.Listas.at(0));
    }

    if (clasif.Listas.at(1).PrimerPoligono == nullptr) std::cout << "No hay poligonos con perimetro mayor a " << clasif.limiteinferior << " y menor a " << clasif.limitesuperior <<"\n";
    else{
        std::cout << "Los poligonos con perimetro mayor a " << clasif.limiteinferior << " y menor a " << clasif.limitesuperior << " son: " << "\n";
        MostrarLista(clasif.Listas.at(1));
    }

    if (clasif.Listas.at(2).PrimerPoligono == nullptr) std::cout << "No hay poligonos con perimetro mayor a " << clasif.limitesuperior <<"\n";
    else{
        std::cout << "Los poligonos con perimetro mayor a " << clasif.limitesuperior << " son: " <<"\n";
        MostrarLista(clasif.Listas.at(2));
    }

}

void ClasificarListaPorPerim (ListaPoligonos& lista, ClasifPoligonosPorPerimetro& clasif, double liminf, double limsup){
    clasif.limiteinferior = liminf;
    clasif.limitesuperior = limsup;
    for (auto aux = lista.PrimerPoligono; aux; aux = aux->NextPol){

        double perim = GetPerimetro(aux->Pol);

        if (perim < liminf) (AddPoligono(clasif.Listas.at(0), aux->Pol));

        if (liminf < perim and perim < limsup) AddPoligono(clasif.Listas.at(1), aux->Pol);

        else AddPoligono(clasif.Listas.at(2), aux->Pol);

    }
    LiberarMemoriaLista(lista);
}

bool IsEmpty (const ListaPoligonos& lista){
    return lista.PrimerPoligono == nullptr;
}

unsigned ListLength (const ListaPoligonos& lista){
    unsigned contador = 0;

    for(auto aux = lista.PrimerPoligono; aux; aux = aux->NextPol) ++contador;

    return contador;
}

bool IsIgualLista (const ListaPoligonos& lista1, const ListaPoligonos& lista2){
    if (ListLength(lista1) != ListLength(lista2)) return false;
    else
    {
        auto aux2 = lista2.PrimerPoligono;
        for (auto aux1 = lista1.PrimerPoligono; aux1; aux1 = aux1->NextPol){
            if (not IsIgual(aux1->Pol, aux2->Pol)) return false;
            aux2 = aux2->NextPol;
        };
        return true;
    }

}

void LiberarMemoriaClasif (ClasifPoligonosPorPerimetro& clasif){
    LiberarMemoriaLista(clasif.Listas.at(0));
    LiberarMemoriaLista(clasif.Listas.at(1));
    LiberarMemoriaLista(clasif.Listas.at(2));
}

bool IsEmptyClasif (const ClasifPoligonosPorPerimetro& clasif) {
    return IsEmpty(clasif.Listas.at(0)) and IsEmpty(clasif.Listas.at(1)) and IsEmpty(clasif.Listas.at(2));
}
