#ifndef CPU_H
#define CPU_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#include "Memoria.h"


struct FuncEntry {
    // quad counter where it begins
    int quadPos;

    // number of local variables {int, float, char}
    std::vector<int> numLVar;

    // number of temporal variables {int, float, bool}
    std::vector<int> numTemp; 
};

struct QuadEntry {
   std::string op;
   std::string oper1;
   std::string oper2;
   std::string res;
};

class CPU {
private:
    Memoria mem;

    std::string programName;

    // stack que guarda las llamadas a las funciones
    std::vector<std::string> currentFunc;

    // stack que guarda los checkpoints antes de irse a la llamada de una funcion
    std::vector<int> gosubCheckpoint;

public:
    std::unordered_map<std::string, FuncEntry> funcDir;

    // era data for main
    std::vector<int> mainVariableData;

    // <position, value>
    std::map<std::string, std::string> constTable;

    // contadores para lectura y asignacion de parametros a variables locales
    // de una funcion {int, float, char}
    std::vector<std::vector<int>> paramCounters;

    std::vector<QuadEntry> quads;

    void parseFile(const std::string fileName);

    void runCode();

};


#endif