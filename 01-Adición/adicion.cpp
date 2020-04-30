/*	"Adición": Programa que realiza la suma de dos valores enteros ingresados por consola y muestra el resultado por la misma.
	Autor: Nicolas Emmanuel Crivelli
	Fecha: 29/04/2020
*/

#include <iostream>
 
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
}
