#include "color.h"
#include <fstream>
#include <iostream>

//Definición de funciones

Color Mezclar(const Color& a, const Color& b){
    Color res;

    res.r = (a.r + b.r) / 2 ;
    res.g = (a.g + b.g) / 2 ;
    res.b = (a.b + b.b) / 2 ;

return res;
}

Color MezclarConPartes (const unsigned& n, const Color& a, const unsigned& m, const Color& b){
    Color res;

    res.r = (a.r * n + b.r * m) / (n+m) ;
    res.g = (a.g * n + b.g * m) / (n+m) ;
    res.b = (a.b * n + b.b * m) / (n+m) ;

    return res;
}

Color SumarColores (const Color& a, const Color& b){
    Color res;

    res.r = (a.r + b.r > 255) ? 255 : a.r + b.r ;
    res.g = (a.g + b.g > 255) ? 255 : a.g + b.g ;
    res.b = (a.b + b.b > 255) ? 255 : a.b + b.b ;

    return res;
}

Color RestarColores (const Color& a, const Color& b){
    Color res;

    res.r = (a.r - b.r < 0) ? 0 : a.r - b.r ;
    res.g = (a.g - b.g < 0) ? 0 : a.g - b.g ;
    res.b = (a.b - b.b < 0) ? 0 : a.b - b.b ;

    return res;
}

Color GetComplementario (const Color& a){
    Color comp;

    comp.r = blanco.r - a.r ;
    comp.g = blanco.g - a.g ;
    comp.b = blanco.b - a.b ;

    return comp;
}

std::string GetHtmlHex (const Color& c){
char resultado [7];

sprintf(resultado, "#%02X%02X%02X", c.r, c.g, c.b);

return resultado;
}

std::string GetHtmlrgb (const Color& c){
    std::string red = std::to_string (c.r);
    std::string green = std::to_string (c.g);
    std::string blue = std::to_string (c.b);

    return "rgb(" + red + "," + green + "," + blue + ")";
}

bool IsIgualColor (const Color& c1, const Color& c2){
return c1.r == c2.r and c1.g == c2.g and c1.b == c2.b ;
}

void CrearSvgConTextoEscritoEnAltoContraste (const std::string& arch, const std::string& mensaje, const Color& c){
std::ofstream archivo;

archivo.open(arch);
archivo << "<svg xmlns= \"http://www.w3.org/2000/svg\">"
<< "<rect x=\"0\" y=\"0\" height=\"30\" width=\"120\" "
<< "style= \"fill:" +GetHtmlHex(GetComplementario(c))+ "\"/>"
<< "<text x=\"5\" y=\"18\" style=\"fill:" +GetHtmlrgb(c)
<< "\">" <<mensaje
<< "</text></svg>";
}

Color LeerColor(){
    uint8_t r, g, b;
    Color c;
    std::cout << "Por favor, ingrese el numero correspondiente a la cantidad de color rojo: ";
    std::cin >> r;
    std::cout << "\n Por favor, ingrese el numero correspondiente a la cantidad de color verde: ";
    std::cin >> g;
    std::cout << "\n Por favor, ingrese el numero correspondiente a la cantidad de color azul: ";
    std::cin >> b;
    c.r = r;
    c.g = g;
    c.b = b;
    return c;
}
