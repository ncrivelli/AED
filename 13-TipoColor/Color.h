/*
 * Alumno: Nicolas E. Crivelli
 * Legajo: 1602410
*/
#include <cstdint>
//declaración de estructura para tipo "Color"
struct Color{
	uint8_t r,g,b;
};

//declaración de constantes para los colores pedidos
const Color rojo {255,0,0};
const Color verde {0,255,0};
const Color azul {0,0,255};
const Color cyan {0,255,255};
const Color magenta {255,0,255};
const Color amarillo {255,255,0};
const Color blanco {255,255,255};
const Color negro {0,0,0};

//prototipos de funciones para manipular los colores
Color mezclar(const Color&, const Color&);
Color mezclarProporciones (const unsigned& , const Color& , const unsigned& , const Color& );
Color sumar (const Color& , const Color&);
Color restar (const Color& , const Color&);
Color getComplementario (const Color&);
bool isIgual (const Color&, const Color&);
