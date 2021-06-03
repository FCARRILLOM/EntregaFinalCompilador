#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include <unordered_map>
#include <string>
#include <vector>
#include <stack>
#include <memory>

#include "Quad.h"
#include "MapaMemoria.h"
#include "CuboSemantico.h"
#include "TablasDatos.h"

/*

*/

class TablaSimbolos {
private:
   std::string programName;

   // directorio de funciones
   std::unordered_map<std::string, FuncEntry> *funcDir;

   // directorio de classes
   std::unordered_map<std::string, ClassEntry> *clasesDir;

   // Referencia a Tabla Datos, donde se guardan datos sobre el Dir. de Funciones, Tabla de variables, etc.
   TablasDatos *tablasDatos;

   // Referencia a clase Quad, donde se generan todos los cuádruplos
   Quad *quad;

   // Referencia al mapa de memoria utilizado para asignar nuevos espacios de memoria
   MapaMemoria *memoria;

   // Referencia al cubo semántico utilizado para verificar tipos y operadores 
   CuboSemantico cubo;

   // Stack de llamadas a funciones
   std::vector<std::string> functionCalls;

   // Nombre de la funcion que esta siendo declarada en el momento
   std::string currentFuncDecl = "main";

   // Nombre de la clase que esta siendo declarada en el momento
   std::string currentClassDecl = "main";

   // Vector para guardar los parametros declarados en la definicion de una funcion 
   // ej. int funcion f1(int: x, int y);
   std::vector<VarEntry> parameters;

   // Contador de parametros encontrados en la llamada de una funcion
   std::vector<int> parameterCounter;

   // Vector para guardar las variables que son declaradas en bloque VARIABLES dentro de una funcion
   // ej. variables ...
   std::vector<VarEntry> varsForDir;

   // Guarda el tipo utilizado para declarar una linea de variables en un bloque variables ...
   // ej. int var1, var2, var2;
   std::string currentVarType;

   // R utilizada para calculos de variables tipo arreglos
   int R;

public:
   TablaSimbolos(TablasDatos &tablasDatos, std::unordered_map<std::string, FuncEntry> &funcDir, std::unordered_map<std::string, ClassEntry> &clasesDir, 
            Quad &quad, MapaMemoria& memoria){
      this->tablasDatos = &tablasDatos;
      this->funcDir = &funcDir;
      this->clasesDir = &clasesDir;
      this->quad = &quad;
      this->memoria = &memoria;
   }

   // Agrega variables declaradas a la tabla de variables de una funcion
   void addVarsToDir(std::string funcId, std::vector<VarEntry> vars);
   
   ///// VARIABLES DECLARADAS DENTRO DEL BLOQUE (variables ...) /////
   // 1
   void saveCurrentVarType(const std::string varType);

   // 2
   void addVarToList(const std::string varName);

   // 3
   void addFirstArrNode();

   // 4
   void storeDimSize(int size);

   // 5
   void addArrNode();   

   // 6
   void endArrNode();
   
   ///// VARIABLES DECLARADAS COMO PARAMETROS EN FUNCIONES /////
   // Inicializa vector para guardar parametros declarados en la definicion de una funcion
   void initParameterVars();

   // Agrega variable a lista actual de variables locales (parametros) para una funcion
   void addParameterVar(std::string varName, std::string varType);

   // DEFINICION DE FUNCIONES
   // Inidica si ya existe una funcion en el directorio de funciones con un id
   int funcExists(const std::string funcId);

   // 1
   void createFunc(std::string funcId, const std::string returnType);

   // 2
   void addParameterVarsToDir();

   // 4
   void addNumParameters();

   // 5
   void addCurrLVarsToDir();

   // 6
   void addFuncCont();

   // 7
   void addEndFunc();

   // LLAMADAS DE FUNCIONES
   // 1
   void verifyFunction();
   void verifyVoidFunction();

   // 2
   void generateEra();

   // 3
   void verifyParameterType();

   // 4
   void moveToNextParam();

   // 5
   void verifyLastParam();

   // 6
   void addGoSub();

   // DECLARACION DE CLASES
   // 1
   void addClass(const std::string className);

   // 2
   void addVarsToClass();

   // 3
   void endCurrentClassDeclaration();

   // MAIN
   // 2
   void addPrincipalFunc(const std::string principalName);

   // 4
   void saveGlobalVars();

   // 5
   void addFuncGlobalVar();

   // 6
   void saveTempsUsed();

   // RETORNO
   // 1
   void saveReturnValue();

   // 2
   void addReturnValue();

   // Imprime directorio de funciones
   void printData();
};

#endif