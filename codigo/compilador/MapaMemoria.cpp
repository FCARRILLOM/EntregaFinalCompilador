#include "MapaMemoria.h"

#include <iostream>

MapaMemoria::MapaMemoria() {
    // Calcula indices de los diferentes espacios de memoria y su tamano total
    // GLOBAL start indexes
    globalStart = 0;
    globalInt = globalStart;
    globalFloat = globalInt + globalTypeSize;
    globalChar = globalFloat + globalTypeSize;
    globalTempInt = globalChar + globalTypeSize;
    globalTempFloat = globalTempInt + globalTempSize;
    globalTempBool = globalTempFloat + globalTempSize;

    globalSize = globalTempBool + globalTempSize - globalStart;

    // LOCAL start indexes
    localStart = globalStart + globalSize;
    localInt = localStart;
    localFloat = localInt + localTypeSize;
    localChar = localFloat + localTypeSize;
    localTempInt = localChar + localTypeSize;
    localTempFloat = localTempInt + localTempSize;
    localTempBool = localTempFloat + localTempSize;

    localSize = localTempBool + localTempSize - localStart;

    // CONST start indexes
    constStart = localStart + localSize;
    constInt = constStart;
    constFloat = constInt + constTypeSize;
    constChar = constFloat + constTypeSize;

    constSize = constChar + constTypeSize - constStart;
}

int MapaMemoria::reserveIntMemory(std::string scope, bool temp, int size) {
    int memoryAddr = -1;

    if (scope == "global") {
        if (!temp) {
            if (globalIntMemory < globalTypeSize) {
                memoryAddr = globalInt + globalIntMemory;
                globalIntMemory += size;
            }
        } else {
            if (globalTempIntMemory < globalTempSize) {
                memoryAddr = globalTempInt + globalTempIntMemory;
                globalTempIntMemory++;
            }
        }
    } else if (scope == "local") {
        if (!temp) {
            if (localIntMemory < localTypeSize) {
                memoryAddr = localInt + localIntMemory;
                localIntMemory += size;
            }
        } else {
            if (localTempIntMemory < localTempSize) {
                memoryAddr = localTempInt + localTempIntMemory;
                localTempIntMemory++;
            }
        }
    } else {
        if (constIntMemory < constSize) {
            memoryAddr = constInt + constIntMemory;
            constIntMemory++;
        }
    }
    return memoryAddr;
}

int MapaMemoria::reserveFloatMemory(std::string scope, bool temp, int size) {
    int memoryAddr = -1;

    if (scope == "global") {
        if (!temp) {
            if (globalFloatMemory < globalTypeSize) {
                memoryAddr = globalFloat + globalFloatMemory;
                globalFloatMemory += size;
            }
        } else {
            if (globalTempFloatMemory < globalTempSize) {
                memoryAddr = globalTempFloat + globalTempFloatMemory;
                globalTempFloatMemory++;
            }
        }
    } else if (scope == "local") {
        if (!temp) {
            if (localFloatMemory < localTypeSize) {
                memoryAddr = localFloat + localFloatMemory;
                localFloatMemory += size;
            }
        } else {
            if (localTempFloatMemory < localTempSize) {
                memoryAddr = localTempFloat + localTempFloatMemory;
                localTempFloatMemory++;
            }
        }
    } else {
        if (constFloatMemory < constSize) {
            memoryAddr = constFloat + constFloatMemory;
            constFloatMemory++;
        }
    }

    return memoryAddr;
}

int MapaMemoria::reserveCharMemory(std::string scope, int size) {
    int memoryAddr = -1;

    if (scope == "global") {
        if (globalCharMemory < globalTypeSize) {
            memoryAddr = globalChar + globalCharMemory;
            globalCharMemory += size;
        }
    } else if (scope == "local") {
        if (localCharMemory < localTypeSize) {
            memoryAddr = localChar + localCharMemory;
            localCharMemory += size;
        }
    } else {
        if (constCharMemory < constSize) {
            memoryAddr = constChar + constCharMemory;
            constCharMemory++;
        }
    }

    return memoryAddr;
}

int MapaMemoria::reserveBoolMemory(std::string scope) {
    int memoryAddr = -1;

    if (scope == "global") {
        if (globalTempBoolMemory < globalTempSize) {
            memoryAddr = globalTempBool + globalTempBoolMemory;
            globalTempBoolMemory++;
        }
    } else if (scope == "local") {
        if (localTempBoolMemory < localTempSize) {
            memoryAddr = localTempBool + localTempBoolMemory;
            localTempBoolMemory++;
        }
    }

    return memoryAddr;
}

void MapaMemoria::resetLocalMemory() {
    localIntMemory = 0;
    localFloatMemory = 0;
    localCharMemory = 0;
    localTempIntMemory = 0;
    localTempFloatMemory = 0;
    localTempBoolMemory = 0;
}

void MapaMemoria::printData() {
    std::cout << "Global Chunk: " << globalStart << " - " << globalStart + globalSize << "\n";
    std::cout << "Local Chunk: " << localStart << " - " << localStart + localSize << "\n";
    std::cout << "Const Chunk: " << constStart << " - " << constStart + constSize << "\n";
}