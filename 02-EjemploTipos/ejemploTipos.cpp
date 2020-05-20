#include <iostream>
#include <assert.h>
#include <string.h>

int main(){
    
    int numero = 9;
    int numero2 = -4;
    
    double grande = 1231452352355;
    double grande2 = 77682910921;
    
    bool positivo = false;
    bool negativo = true;
    
    float real = 8.25;
    float real2 = 2.00;
    
    std::string cadena = "Frase del tipo 'String'.";
    std::string cadena2 = "Otra frase mas";
    
    char simbolo = 'a';
    char simbolo2 = '+';
    
    unsigned numPositivo = 324;
    unsigned numPositivo2 = 4434;
    
    int suma = numero + numero2;
    //Si la suma es positiva, se cumple la condición del assert y el programa sigue con su ejecución.
    assert(suma>0);
    positivo = true;
    negativo = false;
    
    float cociente = real / real2;
    assert(cociente>4);
    
    std::string frase = cadena + cadena2;
    assert(frase=="Frase del tipo 'String'.Otra frase mas");
    
    return 0;
}
