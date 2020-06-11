# Análisis del problema

## Transcripción del problema
*Desarrollar una función que dado un año determine si es bisiesto o no.*

## Refinamiento del problema e Hipótesis de trabajo

*Para poder desarrollar la función nos basaremos en las condiciones necesarias para que un año sea bisiesto, las cuales son que el mismo sea mayor a 1582 y además, sea divisible por 4 y no por 100 o sea divisible por 4 y por 400.*

# Diseño de la Solución

## Arbol de expresión
![arbol 09](https://user-images.githubusercontent.com/63763410/84338485-96a15b80-ab72-11ea-8744-4d7c3b35cb55.PNG)

## Léxico del Algoritmo
*anio ∊ Z; isBisiesto ∊ B*

## Definición
*isBisiesto: Z -> B : m ∧ (p ∧ ( -q ∨ r)
m:año mayor a 1582
p:año divisible por 4
q:año divisible por 100
r: año divisible por 400*
