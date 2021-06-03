#ifndef QUAD_H
#define QUAD_H

#include <string>
#include <iostream>
#include <vector>

#include "CuboSemantico.h"
#include "MapaMemoria.h"
#include "TablasDatos.h"

/*
Esta clase se encarga de generar todos los cuádruplos para luego traducirlos a código intermedio

*/

class Quad {
private:
    CuboSemantico cubo;
    // Referencia al mapa de memoria que se utilizará para asignar direcciones virtuales a variables
    MapaMemoria *memoria;

    // Referecia a la Tabla de Datos donde se guarda toda la informcacion como Directorio de funciones,
    // Directorio de clases, tabla de variables y tabla de constantes
    TablasDatos *tablasDatos;

    std::vector<std::string> sOperators;
    std::vector<std::string> sOperands;
    std::vector<std::string> sTypes;
    std::vector<int> sJumps;

    // Stack que guarda el conteo de temporales utilizadas en cada contexto. Sera necesario para calcular
    // el ERA de una función
    std::vector<int> sTemps;

    // Stack que guarda la los tipos de los temporales utilizados en cada contexto
    std::vector<std::vector<int>> sTempTypes;

    // Vector que simula Queue donde se guardan los cuádruplos generados
    std::vector<std::vector<std::string>> quads;

    // Vector donde se guardan los cuádruplos generados con las variables reemplazadas por 
    // sus direcciones virtuales de memoria.
    std::vector<std::vector<std::string>> memQuads;

    // Contador que apunta al siguiente quad
    int quadPtr;

    // Vector que uarda los resultados de cada expresion para cada dimensiones [EXP] para los arreglos
    std::vector<std::string> resultadosDimensiones;

    // Variable que guarda el nombre de la variable tipo arreglo que se acaba de declarar
    std::string currentArrayVariable;

    // Variable que guarda el scope de una variable tipo arreglo que se acaba de declarar
    std::string currentArrayScope;

    // Agrega un cuádruplo a la lista de cuádruplos normal y de memoria virtual. También incrementa el contador
    // de quads.
    void addQuad(const std::vector<std::string> quad);

    // Parsea la dirección virtual tipo pointer y busca la dirección virtual de su tipo interno. (x) -> (1000)
    std::string getPointerAddress(const std::string pointerAddress);

    // Crea un cuádruplo con un operador binario y dos operandos. ex. +, A, B, t1
    void addArithmeticQuad();

    // Crea un cuádruplo de tipo asignacion. ex. =, A, -, B
    void addAssignQuad();

    // Retorna siguiente valor para t disponible e incrementa el contador del avail
    std::string getNextAvail(const std::string type);

    // Rellena un cuádruplo GOTO con un salto pendiente
    void fillGotoQuad(int position, int newValue);

    // Busca la una variable en las tablas de variables para los scopes local, main y cte.
    // en caso de que la encuentre regresa su dirección virtual.
    std::string getVariableAddress(const std::string name);

    // Genera el código intermedio como archivo 'codigo.cmm' recopilando los datos del Directorio de funciones
    // la tabla de constantes y los cuádruplos
    void generateIntermediateCode();

public:

    Quad(TablasDatos &tablasDatos, MapaMemoria &memoria) {
        this->tablasDatos = &tablasDatos;
        this->memoria = &memoria;
        quadPtr = 0;
    }

    // Elimina los datos previos de los stacks y vector de quadruplos para empezar el proceso de nuevo
    void clearQuad();

    // REGLAS ARITMETICAS tomadas del documento Exp PN and Quad, donde se describen las reglas para generar los cuadruplos
    // de las expresiones aritmeticas
    // 1
    void addOperand(const std::string name);

    // 2
    void addOperatorPlusMinus(const std::string op);

    // 3
    void addOperatorMultDiv(const std::string op);

    // 4
    void removeFromStackPlusMinus();

    // 5
    void removeFromStackMultDiv();

    // 6
    void addFalseBottom();

    // 7
    void removeFalseBottom();

    // 8
    void addOperatorRel(const std::string op);

    // 9
    void removeFromStackRel();

    // 10
    void addOperatorAnd(const std::string op);

    // 11
    void addOperatorOr(const std::string op);

    // 12
    void removeFromStackAnd();

    // 13
    void removeFromStackOr();

    // 14
    void addOperatorAsig(const std::string op);

    // 15
    void removeFromStackAssign();

    // ACCESO ATRIBUTOS DE CLASES
    // 1
    void checkValidAttribute(std::string attributeName);

    void checkValidMethod(std::string methodName);

    void checkValidVoidMethod(std::string methodName);

    // ACCESO ARREGLOS
    // 2
    void verifyArrayDimensions();

    // 3
    void getArrayDimensionResult();

    // 4
    void addArrayQuads();

    // CONSTANTES
    // 1
    void addConstOperand(const std::string value, const std::string type);

    // LECTURA Y ESCRITURA
    // 16
    void addRead(const std::string name);

    // 17
    void addWriteExp();

    // 18
    void addWriteStr(const std::string const_string);

    // DECISIONES
    // 1
    void addGotoIf();

    // 2
    void addDecisionEnd();

    // 3
    void addGotoElse();

    // CONDICIONALES
    // 1
    void addWhileCheckpoint();

    // 2
    void addGotoWhile();

    // 3
    void addConditionalEnd();

    void printData();

    // NO CONDICIONALES
    // 1
    void addLoopCounter(const std::string counterId);

    // 2
    void addLoopLimit();

    // 3
    void addGotoFor();

    // 4
    void addNonConditionalEnd(const std::string counterId);

    // FUNCIONES
    // 7
    void addEndFunc();

    // 2
    void generateEra(const std::string funcId);

    // 3
    void generateParameter(const std::string argument, const std::string paramArg);

    // 6
    void addGoSub(const std::string funcId, int quadLoc);

    // RETORNO FUNCIONES
    // 1
    void saveReturnValue(const std::string returnValue);

    // 2
    void addReturnValue(const std::string funcId, const std::string returnType);

    // MAIN
    // 1
    void savePrincipalLoc();

    // 3
    void addGotoPrincipalLoc();

    // UTILITY
    // Utilidad para la clase tabla simbolos (verifying parameter types)
    // habran casos donde se tiene que hacer pop desde Tabla Simbolos
    std::string popOperand();

    std::string popType();

    int getQuadCont() const;

    // Crea un contador para mantener la cuenta de los temps utilizados en el contexto actual
    // y lo agrega al stack de contadores
    void addNewTempCounter();

    // Regresa el conteo de las temporales utilizadas en el contexto más reciente.
    std::vector<int> getCurrentTempTypes();

    void reserveConstValue(std::string value);

};

#endif