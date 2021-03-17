#pragma once

typedef struct node{
	double x,y;
	struct node* siguiente;
}* Punto;

enum struct CuadrantesyEjes {Cuadrante_I, Cuadrante_II, Cuadrante_III, Cuadrante_IV, Eje_X, Eje_Y, Origen_de_Coordenadas};

//Prototipo de funciones

Punto CrearPunto(double x, double y); //Constructor de Punto

Punto SumarPuntos(const Punto&, const Punto&); /*Toma dos puntos y devuelve su suma*/

Punto leerpunto(); /*Pide las coordenadas de un punto por la entrada estándar y retorna el punto*/

void MostrarPunto(const Punto&); /*Muestra por la salida estándar un punto con el formato (x,y)*/

Punto ProductoPorEscalar(const double&, const Punto&); /*Multiplica las coordenadas de un punto por un valor escalar*/

CuadrantesyEjes GetCuadrante(const Punto&); /*Retorna el cuadrante al que pertenece el punto ingresado, en caso de no pertenecer a ningun cuadrante retorna el eje al que pertenece, o bien, indica que se trata del origen de coordenadas*/

Punto RestarPuntos(const Punto&, const Punto&); /*Retorna el punto resultado de la resta de los dos ingresados considerando RestarPuntos(minuendo, sustraendo)*/

double GetDistancia(const Punto&, const Punto&); /*Retorna el valor de la distancia entre dos puntos*/

double GetDistanciaAlOrigen (const Punto&); /*Retorna el valor de la distancia desde al punto al origen de coordenadas*/

Punto CoordenadasPolares(const Punto&); /*Retorna el punto expresado en sus coordenadas polares siguiendo la siguiente forma: {módulo, ángulo en grados}*/

double ProductoEscalar(const Punto&, const Punto&);/*Considerando a los puntos como extremos de vectores en el origen, retorna el valor de su producto escalar*/

void MoverPunto (Punto&, const Punto&); //Modifica las coordenadas del primer punto por las del segundo ingresado simulando asi moverlo

bool IsIgualPunto (const Punto&, const Punto&); //Compara 2 puntos y retorna un booleano true si son iguales y false si no lo son, en las pruebas se prueba primero para luego usarlo para comprar en los demas asserts
