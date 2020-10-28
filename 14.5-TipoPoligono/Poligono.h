/*
 * Alumno: Nicolas E. Crivelli
 * Legajo: 1602410
*/
#include <vector>
#include <cstdint>
using namespace std;

struct Color{
	uint8_t r,g,b;
};

struct Punto{
	double x,y;
};

struct Poligono{
	Color color;
	vector<Punto> puntos;
};

void addVertice(const Punto&, Poligono&);

Punto getVertice(const unsigned&, Poligono&);

void setVertice(const Punto&, const unsigned&, Poligono&);

void removeVertice(const unsigned&, Poligono&);

int getCantidadDeLados(Poligono&);

double getPerimetro(Poligono&);

//funciones propias del tipo Puntos
double getDistanciaPuntos(const Punto& ,const Punto& );

Punto restaPuntos(const Punto& ,const Punto& );

//funcionPropia del tipo Color
bool colorIsIgual (const Color&, const Color&);

const Color rojo {255,0,0};
const Color verde {0,255,0};
const Color azul {0,0,255};
const Color cyan {0,255,255};
const Color magenta {255,0,255};
const Color amarillo {255,255,0};
const Color blanco {255,255,255};
const Color negro {0,0,0};
