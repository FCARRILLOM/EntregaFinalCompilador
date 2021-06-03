#ifndef MEMORIA_H
#define MEMORIA_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

class Memoria {
private:
    // Posiciones e indices de memoria
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
    std::vector<int> globalIntMemory;
    std::vector<float> globalFloatMemory;
    std::vector<char> globalCharMemory;
    std::vector<int> globalTempIntMemory;
    std::vector<float> globalTempFloatMemory;
    std::vector<bool> globalTempBoolMemory;

    std::vector<int> localIntMemory;
    std::vector<float> localFloatMemory;
    std::vector<char> localCharMemory;
    std::vector<int> localTempIntMemory;
    std::vector<float> localTempFloatMemory;
    std::vector<bool> localTempBoolMemory;

    std::vector<int> constIntMemory;
    std::vector<float> constFloatMemory;
    std::vector<char> constCharMemory;

    // stack de offsets que indica la posicion relativa de las variables en el scope local de la funcion
    // activa en el momento
    std::vector<std::vector<int>> sOffsets {
        // i   f   c   ti   tf   tb
        {0}, {0}, {0}, {0}, {0}, {0}
    };

    // stack que guara los contextos donde se encuentra la memoria actual para cada funcion
    std::vector<int> sContextos;

    // quita parentesis de una direccion de memoria (1000) -> 1000
    std::string stripPointerAddress(const std::string pointerAddress);

public:
    Memoria();

    void changeToNewContext() {
        sContextos.push_back(sOffsets[0].size()-1);
    }

    void changeContextBack() {
        sContextos.pop_back();
    }

    void generateERAConst(const std::map<std::string, std::string> &constTable);
    void generateERAMain(const std::vector<int> &numLVar, const std::vector<int> &numTemp);
    void generateERAFunc(const std::vector<int> &numLVar, const std::vector<int> &numTemp);
    void removeERAFunc(const std::vector<int> &numLVar, const std::vector<int> &numTemp);

    // returns the type of the address specified
    std::string getAddressType(const std::string address);

    // returns value for address in memory space
    int getIntValue(const std::string address);
    float getFloatValue(const std::string address);
    char getCharValue(const std::string address);
    bool getBoolValue(const std::string address);

    // saves value for address in memory space
    void saveIntValue(int value, const std::string address);
    void saveFloatValue(float value, const std::string address);
    void saveCharValue(char value, const std::string address);
    void saveBoolValue(bool value, const std::string address);

    // saves parameter value for address in memory space
    void saveParameterIntValue(int value, int parameterOffset);
    void saveParameterFloatValue(float value, int parameterOffset);
    void saveParameterCharValue(char value, int parameterOffset);
};


#endif