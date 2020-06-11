/*	"isBisiesto": Desarrollo de una función para determinar si un año es bisiesto o no.
	Autor: Nicolas Emmanuel Crivelli
	Fecha: 10/06/2020
*/

#include <iostream>
#include <cassert>

using namespace std;

bool IsBisiesto (int);

int main ()
{
    assert (not IsBisiesto (780)); // Un número menor a 1582
    assert (IsBisiesto (2000)); // Un número divisible por 400
    assert (not IsBisiesto (1800)); // Un número divisible solo por 100 
    
    return 0;
}

bool IsBisiesto (int anio)
    {
        bool result = anio > 1582 and (anio%4 == 0) and ((anio%100 != 0) or anio%400 == 0);
        return result;
    }
    
// La lógica de la función está basada en el algoritmo: m ^ (p ^ (-q v r)) => m: anio > 1582; p: anio%4 == 0; q: anio%100 == 0; r: anio%400 == 0;
