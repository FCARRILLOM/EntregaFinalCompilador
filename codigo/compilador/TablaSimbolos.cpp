#include "TablaSimbolos.h"
#include <iostream>
#include <algorithm>

void TablaSimbolos::addVarsToDir(std::string funcId, std::vector<VarEntry> vars) {
   if ((*funcDir)[funcId].varDir == nullptr) {
      std::cout << "ERROR: Directorio de variables vacío para la función: " << funcId << "\n";
      return;
   }

   // guarda direcciones virtuales
   // memory: local or global, varType, non temp
   for (VarEntry& var : vars) {
      int memAddr = -1;
      std::string scope = "local";
      if (currentFuncDecl == "main") scope = "global";

      std::vector<ArrNode> arrNodes = var.arrNodes;
      bool notArray = arrNodes.empty();
      int size = 1;
      for (ArrNode& node : arrNodes) {
         size *= node.size;
      }

      int type = cubo.typeMap[var.varType];

      // caso especial para tipo objetos
      if (type == 0 && var.varType != "int") type = 4;

      if (type != 4) {
         if (scope == "global")
            (*funcDir)[programName].numLVar[type] += size;
         else 
            (*funcDir)[currentFuncDecl].numLVar[type] += size;
      }

      //delete std::cout << var.varName << " " << var.varType << "\n";
      switch (type) {
         case 0: {
            memAddr = memoria->reserveIntMemory(scope, false, size);
            break;
         }
         case 1: {
            memAddr = memoria->reserveFloatMemory(scope, false, size);
            break;
         }
         case 2: {
            memAddr = memoria->reserveCharMemory(scope, size);
            break;
         }
         case 4: {
            // checar que exista clase
            if ((*clasesDir).count(var.varType) == 0) { 
               std::cout << "ERROR: Clase no existe\n"; 
               return;
            }

            std::string className = var.varType;
            ClassEntry &classEntry = (*clasesDir)[className];

            std::vector<VarEntry> classVariables;
            for (auto classVar : classEntry.varTable) {
               classVariables.push_back({var.varName + "." + classVar.first, classVar.second, -1, {}});
               //std::cout << var.varName + "." + classVar.first << " " << classVar.second << "\n"
            }

            // agrega objeto a directorio de funciones pero no ocupa memoria
            (*(*funcDir)[funcId].varDir)[var.varName] = {var.varName, var.varType, -1, {}};

            addVarsToDir(funcId, classVariables);
         }
      }

      if (memAddr == -1 && type != 4) {
         std::cout << "ERROR: No se puede reservar espacio para la variable " + var.varName + "\n";
      }

     var.memoryAddr = memAddr;
   }

   for (VarEntry var : vars) {
     (*(*funcDir)[funcId].varDir)[var.varName] = var;
   }
}

///// VARIABLES DECLARADAS DENTRO DEL BLOQUE (variables ...) /////
// 1
void TablaSimbolos::saveCurrentVarType(const std::string varType) {
   currentVarType = varType;
}

// 2
void TablaSimbolos::addVarToList(const std::string varName) {
   for (VarEntry var : varsForDir) {
      if (var.varName == varName) {
         std::cout << "ERROR: Redeclaración de la variable nombrada '" + varName + "'\n";
         return;
      }
   }

   // check for duplicate variable declarations in global scope
   if (currentFuncDecl == "main") {
      std::unordered_map<std::string, VarEntry>& globalVars = *(*funcDir)[programName].varDir;
      for (auto var : globalVars) {
         if (var.first == varName) {
            std::cout << "ERROR: Redeclaración de la variable global nombrada '" + varName + "'\n";
            return;
         }
      }
   }

   for (VarEntry par : parameters) {
      if (par.varName == varName) {
         std::cout << "ERROR: Redeclaración del parámetro de la función nombrada '" + varName + "'\n";
         return;
      }
   }

   varsForDir.push_back(VarEntry {varName, currentVarType, -1, {}});
}

// 3
void TablaSimbolos::addFirstArrNode() {
   VarEntry& currVarEntry = varsForDir.back();
   ArrNode newNode;
   currVarEntry.arrNodes.push_back(newNode);
   R = 1;
}

// 4
void TablaSimbolos::storeDimSize(int size) {
   VarEntry& currVarEntry = varsForDir.back();
   ArrNode& lasttNode = currVarEntry.arrNodes.back();
   lasttNode.size = size;
   R = R * size;
}

// 5
void TablaSimbolos::addArrNode() {
   VarEntry& currVarEntry = varsForDir.back();
   ArrNode newNode;
   currVarEntry.arrNodes.push_back(newNode);
}

// 6
void TablaSimbolos::endArrNode() {
   VarEntry& currVarEntry = varsForDir.back();
   std::vector<ArrNode>& arrNodes = currVarEntry.arrNodes;

   for (ArrNode& node : arrNodes) {
      node.m = R / node.size;
      R = node.m;
   }
   // last node m = k = 0
   arrNodes.back().m = 0;
}


///// VARIABLES DECLARADAS COMO PARAMETROS EN FUNCIONES /////
// 1
void TablaSimbolos::initParameterVars() {
   parameters.clear();
}

// 2
void TablaSimbolos::addParameterVar(std::string varName, std::string varType) {
   // check existing variable name in parameter
   for (VarEntry par : parameters) {
      if (par.varName == varName) {
         std::cout << "ERROR: Redeclaración del parámetro nombrado '" + varName + "'\n";
         return;
      }
   }

   parameters.push_back(VarEntry {varName, varType, -1, {}});
}

// DEFINICIONES DE FUNCIONES
int TablaSimbolos::funcExists(const std::string funcId) {
   return((*funcDir).count(funcId));
}

// 1
void TablaSimbolos::createFunc(std::string funcId, const std::string returnType) {   
   if (currentClassDecl != "main") {
      funcId = currentClassDecl + "->" + funcId;
   }

   if (funcExists(funcId)) { 
      std::cout << "ERROR: Nombre de función duplicada\n"; 
      return;
   }
   currentFuncDecl = funcId;
   (*tablasDatos).currentFunc = funcId;

   (*funcDir)[funcId] = FuncEntry {funcId, returnType, std::vector<std::string>(), {0, 0, 0}, {0, 0, 0, 0}, -1,
                                 std::make_unique<std::unordered_map<std::string, VarEntry>>()};

   quad->addNewTempCounter();
}

// 2
void TablaSimbolos::addParameterVarsToDir() {
  addVarsToDir(currentFuncDecl, parameters);
  for (VarEntry par : parameters) {
     (*funcDir)[currentFuncDecl].parameterTable.push_back(par.varType);
   }
}

// 5 from FUNCIONES
void TablaSimbolos::addCurrLVarsToDir() {
   addVarsToDir(currentFuncDecl, varsForDir);
   varsForDir.clear(); 
}

// 6
void TablaSimbolos::addFuncCont() {
   (*funcDir)[currentFuncDecl].quadCont = quad->getQuadCont();
}

// 7
void TablaSimbolos::addEndFunc() {
   (*funcDir)[currentFuncDecl].varDir.reset();
   (*funcDir)[currentFuncDecl].numTemp = quad->getCurrentTempTypes();
   memoria->resetLocalMemory();
   quad->addEndFunc();
   
   currentFuncDecl = "main";
   (*tablasDatos).currentFunc = "main";
}

// LLAMADAS DE FUNCIONES
// 1
void TablaSimbolos::verifyFunction() {
   std::string funcId = quad->popOperand();
   std::string functionType = quad->popType();

   if (funcId.find("->") != std::string::npos) {
         // sustituir nombre de variable por nombre de clase ej. bmw.a() -> carro.a()
         std::size_t start = 0U, punto = funcId.find("->");
         std::string classVariable = funcId.substr(start, punto - start);

         std::string className = "default";
         std::unordered_map<std::string, VarEntry>& globalVars = *(*funcDir)[programName].varDir;
         for (auto var : globalVars) {
            if (var.first == classVariable) {
               className = var.second.varType;
            }
         }

         funcId.erase(start, punto+2);
         funcId = className + "->" + funcId;
    }

   if ((*funcDir).count(funcId) == 0) {
      std::cout << "ERROR: " + funcId + " no existe\n";
   }
   functionCalls.push_back(funcId);
}

void TablaSimbolos::verifyVoidFunction() {
   std::string funcId = quad->popOperand();
   std::string functionType = quad->popType();

   if (funcId.find("->") != std::string::npos) {
         // sustituir nombre de variable por nombre de clase ej. bmw.a() -> carro.a()
         std::size_t start = 0U, punto = funcId.find("->");
         std::string classVariable = funcId.substr(start, punto - start);

         std::string className = "default_void";
         std::unordered_map<std::string, VarEntry>& globalVars = *(*funcDir)[programName].varDir;
         for (auto var : globalVars) {
            if (var.first == classVariable) {
               className = var.second.varType;
            }
         }

         funcId.erase(start, punto+2);
         funcId = className + "->" + funcId;
    }

   if ((*funcDir).count(funcId) == 0) {
      std::cout << "ERROR: " + funcId + " no existe\n";
   }
   functionCalls.push_back(funcId);
}

// 2
void TablaSimbolos::generateEra() {
   parameterCounter.push_back(0);
   quad->generateEra(functionCalls.back());
}

// 3
void TablaSimbolos::verifyParameterType() {
   std::string argument = quad->popOperand();
   std::string argumentType = quad->popType();
   std::string currentFunc = functionCalls.back();

   int currentParameterCount = parameterCounter.back();

   if (currentParameterCount < (*funcDir)[currentFunc].parameterTable.size()) {
      if (argumentType != (*funcDir)[currentFunc].parameterTable[currentParameterCount]) {
         std::cout << "ERROR: Tipos de parámetros no coincidentes para la función '" + currentFunc + "'\n";
         std::cout << "Tipo dado: " + argumentType + ", tipo esperado: " + (*funcDir)[currentFunc].parameterTable[currentParameterCount] + "\n";
         return;
      }

      quad->generateParameter(argument, "param" + std::to_string(currentParameterCount));

   } else {
      std::cout << "ERROR: Parámetros extraños para la función '" + currentFunc + "'\n";
   }
}

// 4
void TablaSimbolos::moveToNextParam(){
   parameterCounter.back()++;
}

// 5
void TablaSimbolos::verifyLastParam(){
   if (parameterCounter.back() != (*funcDir)[functionCalls.back()].parameterTable.size()) {
      std::cout << "ERROR: Coherencia en el número de parámetros para la llamada de función '" + functionCalls.back() + "'\n";
   }
   parameterCounter.pop_back();
}

// 6
void TablaSimbolos::addGoSub(){
   std::string currentFunc = functionCalls.back();
   quad->addGoSub(currentFunc, (*funcDir)[currentFunc].quadCont);
   // se puede hacer pop aqui porque no necesitamos guardar el funcId para obtener su valor de retorno void mas adelante
   if ((*funcDir)[currentFunc].returnType == "void") functionCalls.pop_back();
}

// DECLARACION DE CLASES
// 1
void TablaSimbolos::addClass(const std::string className) {
   if ((*clasesDir).count(className) > 0) { 
      std::cout << "ERROR: Clase duplicada\n"; 
      return;
   }

   currentClassDecl = className;

   (*clasesDir)[className] = ClassEntry{ {}, {} };
}

// 2
void TablaSimbolos::addVarsToClass() {
   ClassEntry &classEntry = (*clasesDir)[currentClassDecl];

   for (VarEntry var : varsForDir) {
      if (classEntry.varTable.count(var.varName) > 0) {
         std::cout << "ERROR: Attributo " + var.varName + " duplicado\n";
         return;
      }

      classEntry.varTable[var.varName] = var.varType;
   }
   varsForDir.clear(); 
}

// 3
void TablaSimbolos::endCurrentClassDeclaration() {
   currentClassDecl = "main";
}

// MAIN
// 2
void TablaSimbolos::addPrincipalFunc(const std::string principalName) {
   programName = principalName;
   (*tablasDatos).programName = programName;
   (*funcDir)[principalName] = FuncEntry {principalName, "NP", std::vector<std::string>(), {0, 0, 0}, {0, 0, 0, 0}, 0,
                                 std::make_unique<std::unordered_map<std::string, VarEntry>>()};
   
   quad->addNewTempCounter();
}

// 4
void TablaSimbolos::saveGlobalVars() {
   addVarsToDir(programName, varsForDir);
   varsForDir.clear(); 
}

// 5
void TablaSimbolos::addFuncGlobalVar() {
   if ((*funcDir)[currentFuncDecl].returnType == "void") {
      VarEntry var { currentFuncDecl, "void", -1, {}};
      (*(*funcDir)[programName].varDir)[var.varName] = var;
      return;
   }

   // mapea todas las variables dentro del directorio de variables
   if ((*funcDir)[programName].varDir == nullptr) {
      std::cout << "ERROR: Directorio de variables vacío para la función: " << programName << "\n";
      return;
   }

   int memAddr = -1;
   // memory: global, returntype, not temp
   switch (cubo.typeMap[(*funcDir)[currentFuncDecl].returnType]) {
      case 0:
         memAddr = memoria->reserveIntMemory("global", false, 1);
         break;
      case 1:
         memAddr = memoria->reserveFloatMemory("global", false, 1);
         break;
      case 2:
         memAddr = memoria->reserveCharMemory("global", 1);
         break;
   }

   if (memAddr == -1) {
      std::cout << "ERROR: No se puede reservar espacio para la función var\n";
      return;
   }

   std::string returnType = (*funcDir)[currentFuncDecl].returnType;
   VarEntry var { currentFuncDecl, returnType, memAddr, {}};
   (*(*funcDir)[programName].varDir)[var.varName] = var;

   int type = cubo.typeMap[returnType];
   (*funcDir)[programName].numLVar[type]++;
}

// 6
void TablaSimbolos::saveTempsUsed() {
   (*funcDir)[programName].numTemp = quad->getCurrentTempTypes();
}

// RETORNO
// 1 - retorno en declaracion de una funcion
void TablaSimbolos::saveReturnValue() {
   std::string result = quad->popOperand();
   std::string resultType = quad->popType();

   if (result.substr(0, 3) != "err") {
      if (resultType != (*funcDir)[currentFuncDecl].returnType) {
         std::cout << "ERROR: el tipo de retorno de la función no es válido para la función '" + currentFuncDecl + "'\n";
      } else {
         quad->saveReturnValue(result);
      }
   } else {
      std::cout << result;
   }
}

// 2 - retorno despues de terminar llamada a una funcion que retorna un valor
void TablaSimbolos::addReturnValue() {
   std::string currentFunc = functionCalls.back();
   quad->addReturnValue(currentFunc, (*funcDir)[currentFunc].returnType);
   functionCalls.pop_back();
}


void TablaSimbolos::printData() {
   std::cout << "FUNC_DIR\n";
   for (auto &f_entry : (*funcDir)) {

      std::cout << f_entry.second.quadCont << " " << f_entry.first << ": " << f_entry.second.returnType << "\n";
      std::cout << "Signature: ";
      for (std::string par : f_entry.second.parameterTable) {
         std::cout << par << ", ";
      }
      /*
      std::cout << std::endl;
      std::cout << "\nLocal int vars (" << f_entry.second.numLVar[0] << ") - ";
      std::cout << "\nLocal float vars (" << f_entry.second.numLVar[1] << ") - ";
      std::cout << "\nTemp ints used (" << f_entry.second.numTemp[0] << ") - ";
      */
     
     std::cout << "\n\n";
   }
   
}
