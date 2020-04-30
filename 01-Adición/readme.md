# Análisis del problema

## Transcripción del problema
*Obtener dos valores enteros por parte del usuario y mostrar el resultado de la suma de ambos.*

## Refinamiento del problema e Hipótesis de trabajo

*Solicitar al usuario que se ingresen los valores a sumar, almacernarlos en dos variables del tipo entero (int) y mostrar por consola el resultado de la suma de ambos.*

## [Modelo IPO](https://drive.google.com/open?id=18nYVBR6hCSUzr6jGyvQmrBdTEExvDbNI)

# Diseño de la Solución
## Léxico del Algoritmo
*A,B ∊ Z*

## Representación del Algoritmo

## [Representación visual del algoritmo](https://drive.google.com/open?id=18NZBFAjC5H1sxyzk-Ewcl7mmtMuVHnPv)

## Representación textual del algoritmo

`#include <iostream>
 
int main () 
{
    int A, B;
    
    std::cout << "Ingrese el primer valor entero a sumar\n";
    std::cin >> A;
    std::cout << "Ingrese el segundo valor entero a sumar\n";
    std::cin >> B;
    
    std::cout << "El resultado de la suma es: ";
    std::cout << A + B;
    std::cout << "\n";
    
    return 0;
}`
