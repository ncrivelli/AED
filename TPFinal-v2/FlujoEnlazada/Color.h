#pragma once
#include <string>
#include <cstdint>

struct Color {uint8_t r, g, b ;};


//Prototipo de funciones

Color LeerColor(); //Pide los valores correspondientes a r, g y b de un color al usuario por teclado y retorna el color que forma.

Color Mezclar(const Color&, const Color&); //Retorna un color correspondiente a la mezcla de dos colores en partes iguales (promedio)

Color MezclarConPartes (const unsigned& , const Color& , const unsigned& , const Color& ); //Retorna un color correspondiente a la mezcla permitiendo mezclar en partes desiguales, cada color es precedido por la cantidad de partes correspondientes

Color SumarColores (const Color& , const Color&); //Retorna un Color correspondiente a la suma de cada parte de dos colores

Color RestarColores (const Color& , const Color&); //Retorna un Color correspondiente a la resta de cada parte de dos colores

Color GetComplementario (const Color&); //Retorna el color complementario al ingresado en el argumento

std::string GetHtmlHex (const Color&); //Retorna una cadena correspondiente al color en hexadecimal siguiendo la siguiente forma "#rgb"

std::string GetHtmlrgb (const Color&); //Retorna una cadena correspondiente al color en formato "rgb(r,g,b)"

bool IsIgualColor (const Color&, const Color&); //Compara dos colores y retorna un booleano true si son iguales o false si no lo son

void CrearSvgConTextoEscritoEnAltoContraste (const std::string&, const std::string&, const Color&);

//Declaración de las constantes

const Color rojo {255, 0, 0};

const Color verde {0, 255, 0};

const Color azul {0, 0, 255};

const Color cyan = SumarColores(verde, azul);

const Color magenta = SumarColores(rojo, azul);

const Color amarillo = SumarColores(rojo, verde);

const Color blanco = SumarColores(SumarColores(rojo, verde), azul);

const Color negro = RestarColores(RestarColores(RestarColores (blanco, rojo), verde), azul);
