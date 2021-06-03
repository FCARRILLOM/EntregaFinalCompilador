#ifndef MAPA_MEMORIA_H
#define MAPA_MEMORIA_H

#include <unordered_map>
#include <string>
#include <vector>

/*
Esta clase tiene la funcion que calcular y asignar las direcciones de memoria virtuales a las distintas variables
que se van encontrando en el código fuente.
Para lograr esto primero se calculan los rangos de los espacios que ocupa cada tipo de variable, y se crea un 
contador para calcular la siguente direccion disponible
*/

class MapaMemoria {
private:
    // Posiciones e indices de mapa de memoria
    int globalStart, globalSize,
        localStart, localSize,
        constStart, constSize;

    int globalInt, globalFloat, globalChar,
        globalTempInt, globalTempFloat, globalTempBool,
        globalTypeSize = 2000,
        globalTempSize = 3000;

    int localInt, localFloat, localChar,
        localTempInt, localTempFloat, localTempBool,
        localTypeSize = 2000,
        localTempSize = 3000;

    int constInt, constFloat, constChar,
        constTypeSize = 3000;

    // Estructura de memoria
    int globalIntMemory = 0;
    int globalFloatMemory = 0;
    int globalCharMemory = 0;
    int globalTempIntMemory = 0;
    int globalTempFloatMemory = 0;
    int globalTempBoolMemory = 0;

    int localIntMemory = 0;
    int localFloatMemory = 0;
    int localCharMemory = 0;
    int localTempIntMemory = 0;
    int localTempFloatMemory = 0;
    int localTempBoolMemory = 0;

    int constIntMemory = 0;
    int constFloatMemory = 0;
    int constCharMemory = 0;

public:
    MapaMemoria();

    /*
    Calcula el espacio de memoria para un tipo int y regresa su valor
    scope: si es una variable "global" o "local"
    temp: si es una variable temporal o no
    size: el tamaño de espacios que ocupa la variable [1..n]
    */
    int reserveIntMemory(std::string scope, bool temp, int size);

    /*
    Calcula el espacio de memoria para un tipo float y regresa su valor
    scope: si es una variable "global" o "local"
    temp: si es una variable temporal o no
    size: el tamaño de espacios que ocupa la variable [1..n]
    */
    int reserveFloatMemory(std::string scope, bool temp, int size);

    /*
    Calcula el espacio de memoria para un tipo char y regresa su valor. En este caso no se incluye el parametro
    temp ya que no hay operaciones con chars y por ende existen los chars tipo temp
    scope: si es una variable "global" o "local"
    size: el tamaño de espacios que ocupa la variable [1..n]
    */
    int reserveCharMemory(std::string scope, int size);

    /*
    Calcula el espacio de memoria para un tipo bool y regresa su valor. Los bools siempre serán temporales
    ya que son tipos intermedios en las expresiones, y nunca serán tipo arreglo por lo que su tamaño será siempre 1
    scope: si es una variable "global" o "local"
    */
    int reserveBoolMemory(std::string scope);

    /*
    Hace un reset a los contadores para la variables locales para que 
    sus direcciones calculadas inicien desde 0.
    */
    void resetLocalMemory();

    /*
    Imprime algunos datos sobre el mapa de memoria como los indices de cada partición
    */
    void printData();

};

#endif