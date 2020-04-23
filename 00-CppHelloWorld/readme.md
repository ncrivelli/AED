En primer instancia, respecto al compilador, en este caso no instalé ninguno adicional ya que me encuentro trabajando en el sistema
operativo Linux, el cual posee por defecto el compilador gcc.
Pasando al programa, comienza con un header que posee el título del mismo, una breve descripción, mi nombre completo y la 
fecha en la que se realizó. Luego, incluímos la librería iostream para poder usar mas adelante la función std::cout, la cual permite
visualizar por consola la frase deseada: "Hola mundo". Por último retornamos el valor de "0" para indicar que el programa se ejecutó
con éxito y podemos dar por finalizado el mismo.
Ya en la consola primero accedemos a la carpeta donde se encuentra el archivo hello.cpp a traves del comando cd 00-CppHelloWorld y
luego ingresamos el comando g++ -o ejecutable hello.cpp, el cual linkea y compila el archivo obteniendo así un ejecutable.
A través del comando ./ejecutable vemos que la salida muestra correctamente un "Hola mundo" y a continuación, finalizada la ejecución,
ingresamos el comando ./ejecutable > output.txt para que la salida sea capturada por este archivo de texto, el cual queda guardado en
la carpeta que nos encontramos.
Finalizados los objetivos del trabajo, accedemos a mover los archivos hello.cpp output.txt al repositorio de Github, donde se encuentra
también el presente archivo readme.md
