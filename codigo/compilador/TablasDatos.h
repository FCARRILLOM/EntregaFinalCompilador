#ifndef TABLAS_DATOS_H
#define TABLAS_DATOS_H

#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

/*
Clase donde se guardan estructuras de datos como 
- Directorio de Funciones
- Directorio de Clases
- Tablas de Variables
- Tabla de Constantes
todas estas pueden ser accedidas para actualizar o leer su datos
*/

struct ArrNode {
   int size;
   int m;
};

struct VarEntry {
   std::string varName;
   std::string varType;
   int memoryAddr;
   std::vector<ArrNode> arrNodes;
};

struct FuncEntry {
   std::string funcName;
   std::string returnType;

   // signature of parameter types
   std::vector<std::string> parameterTable;

   // number of local variables {int, float, char}
   std::vector<int> numLVar;

   // number of temporal variables {int, float, -char-, bool}
   std::vector<int> numTemp; 

   // quad counter where it begins
   int quadCont;

   std::unique_ptr<std::unordered_map<std::string, VarEntry>> varDir;
};

struct ClassEntry {
   std::unordered_map<std::string, std::string> varTable; // { nombre, tipo }
   std::unordered_set<std::string> funcNames;
};

class TablasDatos {
public:
   // directorio de funciones
   std::unordered_map<std::string, FuncEntry> funcDir;

   // tablas de constantes
   std::unordered_map<std::string, int> constDir;

   // indica el scope actual, si estamos dentro de una funcion o en el main
   std::string currentFunc = "main";

   std::string programName = "";

   // directorio de classes
   std::unordered_map<std::string, ClassEntry> clasesDir;
};

#endif