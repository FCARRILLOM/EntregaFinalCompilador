#include "Quad.h"
#include <iostream>
#include <fstream>

void Quad::addQuad(const std::vector<std::string> tempQuad) {
    quads.push_back(tempQuad);
    //std::cout << tempQuad[0] <<  ", " << tempQuad[1] <<  ", " << tempQuad[2] <<  ", " << tempQuad[3] <<  "\n";

    int opCode = cubo.operatorMap[tempQuad[0]];
    std::vector<std::string> memQuad = tempQuad;
    // gosub, goto, era, endfunc, end. stay the same
    if (opCode == 15 || opCode == 16 || opCode == 17 || opCode == 18 || opCode == 22)  {
        // 
    } else if (opCode == 13) { // parameters
        if (tempQuad[1][0] == '(')
            memQuad[1] = getPointerAddress(tempQuad[1]);
        else 
            memQuad[1] = getVariableAddress(tempQuad[1]);

    } else if (opCode == 19) { // write
        if (tempQuad[3][0] != '"') { // ignore strings
            if (tempQuad[3][0] == '(')
                memQuad[3] = getPointerAddress(tempQuad[3]);
            else 
                memQuad[3] = getVariableAddress(tempQuad[3]);
        }

    } else if (opCode == 20) { // read
        if (tempQuad[3][0] == '(')
            memQuad[3] = getPointerAddress(tempQuad[3]);
        else
            memQuad[3] = getVariableAddress(tempQuad[3]);

    } else if (opCode == 21) { // return
        // look for function's memory address in global variables table
        memQuad[1] = std::to_string((*(*tablasDatos).funcDir[(*tablasDatos).programName].varDir)[tempQuad[1]].memoryAddr);

        if (tempQuad[3][0] == '(')
            memQuad[3] = getPointerAddress(tempQuad[3]);
        else
            memQuad[3] = getVariableAddress(tempQuad[3]);

    } else {
        if (tempQuad[1][0] == '(')
            memQuad[1] = getPointerAddress(tempQuad[1]);
        else if (tempQuad[1] != "-") 
            memQuad[1] = getVariableAddress(tempQuad[1]);

        if (tempQuad[2][0] == '(')
            memQuad[2] = getPointerAddress(tempQuad[2]);
        else if (tempQuad[2] != "-") 
            memQuad[2] = getVariableAddress(tempQuad[2]);

        if (tempQuad[3][0] == '(')
            memQuad[3] = getPointerAddress(tempQuad[3]);
        else if (tempQuad[3] != "-") 
            memQuad[3] = getVariableAddress(tempQuad[3]);
    }
    memQuad[0] = std::to_string(cubo.operatorMap[tempQuad[0]]);
    memQuads.push_back(memQuad);

    quadPtr++;
}

std::string Quad::getPointerAddress(const std::string pointerAddress) {
    std::string parsedAddress = pointerAddress;
    parsedAddress.pop_back();
    parsedAddress.erase(0, 1);
    std::string address = getVariableAddress(parsedAddress);
    address = '(' + address + ')';
    return address;
}

void Quad::addArithmeticQuad() {
    std::string right_operand = sOperands.back();
    sOperands.pop_back();
    std::string right_type = sTypes.back();
    sTypes.pop_back();

    std::string left_operand = sOperands.back();
    sOperands.pop_back();
    std::string left_type = sTypes.back();
    sTypes.pop_back();

    std::string op = sOperators.back();
    sOperators.pop_back();

    std::string resultType = cubo.getTypeFromCube(left_type, right_type, op);
    if (resultType.substr(0, 3) != "err") {
        std::string result = getNextAvail(resultType);
        // memory: local or global, resultType, temp
        std::vector<std::string> tempQuad {op, left_operand, right_operand, result};
        addQuad(tempQuad);
        sOperands.push_back(result);
        sTypes.push_back(resultType);
    } else {
        std::cout << resultType << std::endl;
    }
}

void Quad::addAssignQuad() {
    std::string op = sOperators.back();
    sOperators.pop_back();

    std::string res = sOperands.back();
    sOperands.pop_back();
    std::string res_type = sTypes.back();
    sTypes.pop_back();

    std::string left_operand = sOperands.back();
    sOperands.pop_back();
    std::string left_type = sTypes.back();
    sTypes.pop_back();

    std::string assignType = cubo.getTypeFromCube(left_type, res_type, op);
    
    if (assignType.substr(0, 3) != "err") {
        std::vector<std::string> tempQuad {op, res, "-", left_operand};
        addQuad(tempQuad);
    } else {
        std::cout << "ERROR: No se puede asignar " + left_operand + " = " + res + "\n";
        std::cout << assignType << std::endl;
    }
}

std::string Quad::getNextAvail(const std::string type) {
    if (sTemps.empty()) {
        std::cout << "ERROR: Contador temporal vacío para disponibilidad\n";
        return "err";
    }

    std::string avail =  "t" + std::to_string(sTemps.back());
    sTemps.back() += 1;

    int tempType = cubo.typeMap[type];
    std::string currentFunc = (*tablasDatos).currentFunc;
    std::vector<int> &tempTypes = sTempTypes.back();
    tempTypes[tempType]++;

    // asigna direccion virtual a temp
    int memAddr = -1;
    std::string scope = "local";
    if (currentFunc == "main") scope = "global";

    switch (tempType) {
        case 0: // int
            memAddr = memoria->reserveIntMemory(scope, true, 1);
            break;
        case 1: // float
            memAddr = memoria->reserveFloatMemory(scope, true, 1);
            break;
        case 3: // bool
            memAddr = memoria->reserveBoolMemory(scope);
            break;
    }

    VarEntry var { avail, type, memAddr , {}};
    if (currentFunc == "main") {
        (*(*tablasDatos).funcDir[(*tablasDatos).programName].varDir)[avail] = var;
    } else {
        (*(*tablasDatos).funcDir[currentFunc].varDir)[avail] = var;
    }

    return avail;
}

void Quad::fillGotoQuad(int position, int newValue) {
    quads[position][3] = std::to_string(newValue);
    memQuads[position][3] = std::to_string(newValue);
}

std::string Quad::getVariableAddress(const std::string name) {
    std::string currentFunc = (*tablasDatos).currentFunc;
    std::string programName = (*tablasDatos).programName;

    int addr = -1;
    if ((*tablasDatos).constDir.count(name) > 0) { // const table
        addr = (*tablasDatos).constDir[name];
    } else if (currentFunc != "main"  && (*(*tablasDatos).funcDir[currentFunc].varDir).count(name) > 0) { // local vars
        addr = (*(*tablasDatos).funcDir[currentFunc].varDir)[name].memoryAddr;
    } else if (programName != "" && (*(*tablasDatos).funcDir[programName].varDir).count(name) > 0) { // global vars
        addr = (*(*tablasDatos).funcDir[programName].varDir)[name].memoryAddr;
    } else {
        std::cout << "ERROR: Variable '" + name + "' no encontrada\n";
    }
    return std::to_string(addr);
}

void Quad::generateIntermediateCode() {
    std::ofstream outFile;
    outFile.open("codigo.cmm");
    // func dir
    for (auto &entry : (*tablasDatos).funcDir) {
        FuncEntry &funcData = entry.second;
        outFile << entry.first << ", " << funcData.quadCont << ", ";
        // local vars used
        outFile << funcData.numLVar[0] << ", ";
        outFile << funcData.numLVar[1] << ", ";
        outFile << funcData.numLVar[2] << ", ";
        // temps used
        outFile << funcData.numTemp[0] << ", ";
        outFile << funcData.numTemp[1]<< ", ";
        outFile << funcData.numTemp[3] << "\n";
    }

    // const table
    outFile << "%%\n";
    for (auto entry : (*tablasDatos).constDir) {
        outFile << entry.first << ", " << entry.second << "\n";
    }

    // quads
    outFile << "%%\n";
    for (auto quad : memQuads) {
        outFile << quad[0] << ", " << quad[1] << ", " << quad[2] << ", " << quad[3] << "\n";
    }
    outFile.close();

}

void Quad::clearQuad() {
    addQuad({"END", "-", "-", "-"});
    //printData();
    generateIntermediateCode();
    sOperators.clear();
    sOperands.clear();
    sTypes.clear();
    quads.clear();
    sTemps.clear();
    sTempTypes.clear();
    quadPtr = 0;
}

// REGLAS ARITMETICAS

// 1
void Quad::addOperand(const std::string name) {// asigna direccion virtual a tempOperand(const std::string name) {
    std::string currentFunc = (*tablasDatos).currentFunc;
    std::string programName = (*tablasDatos).programName;

    // look for variable type in var tables
    std::string type = "int";
    if (currentFunc != "main"  && (*(*tablasDatos).funcDir[currentFunc].varDir).count(name) > 0) { // local
        type = (*(*tablasDatos).funcDir[currentFunc].varDir)[name].varType;
    } else if ((*(*tablasDatos).funcDir[programName].varDir).count(name) > 0) { // global
        type = (*(*tablasDatos).funcDir[programName].varDir)[name].varType;
    } else {
        std::cout << "ERROR: Variable '" + name + "' no encontrada\n";
    }
    
    sOperands.push_back(name);
    sTypes.push_back(type);
}

// 2
void Quad::addOperatorPlusMinus(const std::string op) {
    sOperators.push_back(op);
}

// 3
void Quad::addOperatorMultDiv(const std::string op) {
    sOperators.push_back(op);
}

// 4
void Quad::removeFromStackPlusMinus() {
    if (sOperators.empty()) return;

    if (sOperators.back() == "+" || sOperators.back() == "-") {
        addArithmeticQuad();
    }
}

// 5
void Quad::removeFromStackMultDiv() {
    if (sOperators.empty()) return;

    if (sOperators.back() == "*" || sOperators.back() == "/") {
        addArithmeticQuad();
    }
}

// 6
void Quad::addFalseBottom() {
    sOperators.push_back("[");
}

// 7
void Quad::removeFalseBottom() {
    sOperators.pop_back();
}

// 8
void Quad::addOperatorRel(const std::string op) {
    sOperators.push_back(op);
}

// 9
void Quad::removeFromStackRel() {
    if (sOperators.empty()) return;
    
    std::string relOps = ">,<,>=,<=,<>,==";
    if (relOps.find(sOperators.back()) != std::string::npos) {
        addArithmeticQuad();
    }
}

// 10
void Quad::addOperatorAnd(const std::string op) {
    sOperators.push_back(op);
}

// 11
void Quad::addOperatorOr(const std::string op) {
    sOperators.push_back(op);
}

// 12
void Quad::removeFromStackAnd() {
    if (sOperators.empty()) return;

    if (sOperators.back() == "&") {
        addArithmeticQuad();
    }
}

// 13
void Quad::removeFromStackOr() {
    if (sOperators.empty()) return;

    if (sOperators.back() == "|") {
        addArithmeticQuad();
    }
}

// 14
void Quad::addOperatorAsig(const std::string op) {
    sOperators.push_back(op);
}

// 15
void Quad::removeFromStackAssign() {
    if (sOperators.empty()) return;

    if (sOperators.back() == "=") {
        addAssignQuad();
    } 
}

// ACCESO ATRIBUTOS DE CLASES
// 1
void Quad::checkValidAttribute(std::string attributeName) {
    std::string operand = sOperands.back();
    sOperands.pop_back();
    std::string operandClass = sTypes.back();
    sTypes.pop_back();

    std::unordered_map<std::string, ClassEntry> &clasesDir = (*tablasDatos).clasesDir;
    ClassEntry varClass =  clasesDir[operandClass];
    std::string attributeType = varClass.varTable[attributeName];

    std::string completeVariable = operand + "." + attributeName;

    sOperands.push_back(completeVariable);
    sTypes.push_back(attributeType);
}

// 2
void Quad::checkValidMethod(std::string methodName) {
    std::string operand = sOperands.back();
    sOperands.pop_back();
    std::string operandClass = sTypes.back();
    sTypes.pop_back();

    std::unordered_map<std::string, ClassEntry> &clasesDir = (*tablasDatos).clasesDir;
    ClassEntry varClass =  clasesDir[operandClass];
    std::string methodType = varClass.varTable[methodName];

    std::string completeVariable = operand + "->" + methodName;

    sOperands.push_back(completeVariable);
    sTypes.push_back(methodType);
}

// 3
void Quad::checkValidVoidMethod(std::string methodName) {
    std::string operand = sOperands.back();
    sOperands.pop_back();
    std::string operandClass = sTypes.back();
    sTypes.pop_back();

    std::string completeVariable = operand + "->" + methodName;

    sOperands.push_back(completeVariable);
    sTypes.push_back("void");
}


// ACCESO ARREGLOS
// 2
void Quad::verifyArrayDimensions() {
    std::string operand = sOperands.back();
    sOperands.pop_back();
    std::string type = sTypes.back();
    sTypes.pop_back();

    // name of array variable that was popped and will be used in step 4
    currentArrayVariable = operand;

    std::string currentFunc = (*tablasDatos).currentFunc;
    std::string programName = (*tablasDatos).programName;
    VarEntry currentVar;

    // look for variable in scopes
    if (currentFunc != "main" && (*(*tablasDatos).funcDir[currentFunc].varDir).count(operand) > 0) { // local
        currentVar = (*(*tablasDatos).funcDir[currentFunc].varDir)[operand];
        currentArrayScope = "local";
    } else if ((*(*tablasDatos).funcDir[programName].varDir).count(operand) > 0) { // global
        currentVar = (*(*tablasDatos).funcDir[programName].varDir)[operand];
        currentArrayScope = "global";
    } else {
        std::cout << "ERROR: variable '" + operand + "' no encontrada\n";
    }

    if (currentVar.arrNodes.empty()) {
        std::cout << "ERROR: variable " + currentFunc + "/" + operand + " no es un arreglo\n";
        return;
    }
    
    resultadosDimensiones.clear();

    addFalseBottom(); 
}

// 3
void Quad::getArrayDimensionResult() {
    std::string operand = sOperands.back();
    sOperands.pop_back();
    std::string type = sTypes.back();
    sTypes.pop_back();

    if (type != "int") {
        std::cout << "Array index not 'int'\n";
        return;
    }

    resultadosDimensiones.push_back(operand);
}

// 4
void Quad::addArrayQuads() {
    // calcula donde buscar la variable
    std::string currentFunc = (*tablasDatos).currentFunc;
    if (currentArrayScope == "global") {
        currentFunc = (*tablasDatos).programName;
    }

    VarEntry& currentVar = (*(*tablasDatos).funcDir[currentFunc].varDir)[currentArrayVariable];
    std::vector<ArrNode> arrNodes = currentVar.arrNodes;

    // add sizes to const table;
    for (ArrNode& node : arrNodes) {
        std::string value = std::to_string(node.size);
        std::string lsup = std::to_string(node.size - 1);

        if ((*tablasDatos).constDir.count(value) <= 0) {
            int memAddr = memoria->reserveIntMemory("const", false, 1);
            if (memAddr == -1)
                std::cout << "ERROR: No se puede reservar memoria para la constante " +  value + " \n";

            (*tablasDatos).constDir[value] = memAddr;
        }
        if ((*tablasDatos).constDir.count(lsup) <= 0) {
            int memAddr = memoria->reserveIntMemory("const", false, 1);
            if (memAddr == -1)
                std::cout << "ERROR: No se puede reservar memoria para la constante " + lsup  + " \n";

            (*tablasDatos).constDir[lsup] = memAddr;
        }
    }

    int numNodes = resultadosDimensiones.size();

    if (numNodes == 1) {
        // verify s1
        std::vector<std::string> tempQuad {"VER", resultadosDimensiones[0], "0", std::to_string(arrNodes[0].size - 1)};
        addQuad(tempQuad);

        // s1
        sOperands.push_back(resultadosDimensiones[0]);
        sTypes.push_back("int");

    } else if (numNodes == 2){
        // verify s1
        std::vector<std::string> tempQuad {"VER", resultadosDimensiones[0], "0", std::to_string(arrNodes[0].size - 1)};
        addQuad(tempQuad);

        // s1 * m1
        std::string result_t0 = getNextAvail("int");
        tempQuad = std::vector<std::string>({"*", resultadosDimensiones[0], std::to_string(arrNodes[0].m), result_t0});
        sOperands.push_back(result_t0);
        sTypes.push_back("int");
        addQuad(tempQuad);

        // ver s2
        tempQuad = std::vector<std::string>({"VER", resultadosDimensiones[1], "0", std::to_string(arrNodes[1].size - 1)});
        addQuad(tempQuad);

        // (s1*m1) + s2
        std::string s1m1 = sOperands.back();
        sOperands.pop_back();
        sTypes.pop_back();

        std::string result_t1 = getNextAvail("int");
        tempQuad = std::vector<std::string>({"+", s1m1, resultadosDimensiones[1], result_t1});
        addQuad(tempQuad);
        sOperands.push_back(result_t1);
        sTypes.push_back("int");

    } else {
        std::cout << "ERROR: Exceso de dimensiones\n";
        return;
    }

    // s1 o (s1*m1 + s2 or s1) + base
    std::string dirBase = std::to_string(currentVar.memoryAddr);
    reserveConstValue(dirBase);
    std::string result = getNextAvail("int");

    // s1 o (s1*m1 + s2 or s1)
    std::string address = sOperands.back();
    sOperands.pop_back();
    std::string type = sTypes.back();
    sTypes.pop_back();
    std::vector<std::string> tempQuad = std::vector<std::string>({"+", address, dirBase, result});
    addQuad(tempQuad);

    sOperands.push_back("(" + result + ")");
    sTypes.push_back(currentVar.varType);

    removeFalseBottom();
}

// CONSTANTES
// 1
void Quad::addConstOperand(const std::string value, const std::string type) {
    //std::cout << type << " " << value << "\n";
    sOperands.push_back(value);
    sTypes.push_back(type);

    // add to const table;
    if ((*tablasDatos).constDir.count(value) > 0) return;

    int memAddr = -1;
    if (type == "int") {
        memAddr = memoria->reserveIntMemory("const", false, 1);
    } else if (type == "float") {
        memAddr = memoria->reserveFloatMemory("const", false, 1);
    } else if (type == "char") {
        memAddr = memoria->reserveCharMemory("const", 1);
    }
    
    if (memAddr == -1) {
        std::cout << "ERROR: No se puede reservar memoria para la constante " +  value + " \n";
    }

    (*tablasDatos).constDir[value] = memAddr;
}

// LECTURA Y ESCRITURA
// 16
void Quad::addRead(const std::string name) {
    std::vector<std::string> tempQuad {"read", "-", "-", name};
    addQuad(tempQuad);
}

// 17
void Quad::addWriteExp() {
    if (sOperands.empty()) {
        std::cout << "Write EXP error: No quedan operandos\n";
        return;
    }
    std::string res = sOperands.back();
    sOperands.pop_back();

    std::vector<std::string> tempQuad {"write", "-", "-", res};
    addQuad(tempQuad);
}

// 18
void Quad::addWriteStr(const std::string const_string) {
    std::vector<std::string> tempQuad {"write", "-", "-", const_string}; 
    addQuad(tempQuad);
}

// DECISIONES
// 1
void Quad::addGotoIf() {
    std::string expType = sTypes.back();
    sTypes.pop_back();

    if (expType != "bool") {
        std::cout << "ERROR: La expresión de decisión no es de tipo 'bool'\n";
    } else {
        std::string result = sOperands.back();
        sOperands.pop_back();

        std::vector<std::string> tempQuad {"GotoF", result, "-", "-"}; 
        addQuad(tempQuad);

        sJumps.push_back(quadPtr-1);
    }
}

// 2
void Quad::addDecisionEnd() {
    int end = sJumps.back();
    sJumps.pop_back();

    fillGotoQuad(end, quadPtr);
}

// 3
void Quad::addGotoElse() {
    std::vector<std::string> tempQuad {"GOTO", "-", "-", "-"}; 
    addQuad(tempQuad);

    int falseLoc = sJumps.back();
    sJumps.pop_back();

    sJumps.push_back(quadPtr-1);

    fillGotoQuad(falseLoc, quadPtr);
}

// CONDICIONALES
// 1
void Quad::addWhileCheckpoint() {
    sJumps.push_back(quadPtr);
}

// 2
void Quad::addGotoWhile() {
    std::string expType = sTypes.back();
    sTypes.pop_back();

    if (expType != "bool") {
        std::cout << "ERROR: La expresión condicional no es de tipo 'bool'\n";
    } else {
        std::string result = sOperands.back();
        sOperands.pop_back();

        std::vector<std::string> tempQuad {"GotoF", result, "-", "-"}; 
        addQuad(tempQuad);

        sJumps.push_back(quadPtr-1);
    }
}

// 3
void Quad::addConditionalEnd() {
    int end = sJumps.back();
    sJumps.pop_back();

    int returnStart = sJumps.back();
    sJumps.pop_back();

    std::vector<std::string> tempQuad {"GOTO", "-", "-", std::to_string(returnStart)}; 
    addQuad(tempQuad);

    fillGotoQuad(end, quadPtr); 
}

// NO CONDICIONALES
// 1
void Quad::addLoopCounter(const std::string counterId) {
    std::string counterType = sTypes.back();
    sTypes.pop_back();

    if (counterType != "int") {
        std::cout << "ERROR: Contador de bucle no de tipo 'int'\n";
    } else {
        std::string counterExp = sOperands.back();
        sOperands.pop_back();

        // add counter as non-temp variable
        std::string currentFuncDecl = (*tablasDatos).currentFunc;
        std::string scope = "local";
        if (currentFuncDecl == "main")  {
            currentFuncDecl = (*tablasDatos).programName;
            scope = "global";
        }
        int memAddr = memoria->reserveIntMemory(scope, false, 1);
        
        VarEntry var {counterId, "int", memAddr, {}};
        (*(*tablasDatos).funcDir[currentFuncDecl].varDir)[counterId] = var;
        (*tablasDatos).funcDir[currentFuncDecl].numLVar[0] += 1;

        std::vector<std::string> tempQuad {"=", counterExp, "-", counterId}; 
        addQuad(tempQuad);

        sOperands.push_back(counterId);
        sTypes.push_back("int");
    }
}

// 2
void Quad::addLoopLimit() {
    std::string limitType = sTypes.back();
    sTypes.pop_back();

    if (limitType != "int") {
        std::cout << "ERROR: El límite del contador de bucles no es de tipo 'int'\n";
    } else {
        std::string limitExp = sOperands.back();
        sOperands.pop_back();

        std::string counterId = sOperands.back();
        sOperands.pop_back();
        std::string counterType = sTypes.back();
        sTypes.pop_back();

        sJumps.push_back(quadPtr);

        std::string result = getNextAvail("bool");
        // memory: temp, bool, 
        std::vector<std::string> tempQuad {"<", counterId, limitExp, result}; 
        addQuad(tempQuad);

        sOperands.push_back(result);
        sTypes.push_back("bool");
    }
}

// 3
void Quad::addGotoFor() {
    std::string resultType = sTypes.back();
    sTypes.pop_back();

    if (resultType != "bool") {
        std::cout << "ERROR: Expresión de bucle no de tipo 'bool'\n";
    } else {
        std::string result = sOperands.back();
        sOperands.pop_back();

        std::vector<std::string> tempQuad {"GotoF", result, "-", "-"}; 
        addQuad(tempQuad);
        sJumps.push_back(quadPtr - 1);
    }
}

// 4
void Quad::addNonConditionalEnd(const std::string counterId) {
    int end = sJumps.back();
    sJumps.pop_back();

    int returnStart = sJumps.back();
    sJumps.pop_back();

    // increment for loop counter by 1
    std::string result = getNextAvail("int");
    // memory:
    std::vector<std::string> tempQuad {"+", counterId, "1", result}; 
    addQuad(tempQuad);
    tempQuad = std::vector<std::string> {"=", result, "-", counterId}; 
    addQuad(tempQuad);

    tempQuad = std::vector<std::string> {"GOTO", "-", "-", std::to_string(returnStart)}; 
    addQuad(tempQuad);

    fillGotoQuad(end, quadPtr); 
}

// FUNCIONES
// 7
void Quad::addEndFunc() {
    std::vector<std::string> tempQuad {"ENDFUNC", "-", "-", "-"}; 
    addQuad(tempQuad);
}

// 2
void Quad::generateEra(const std::string funcId) {
    std::vector<std::string> tempQuad {"ERA", funcId, "-", "-"}; 
    addFalseBottom(); 
    addQuad(tempQuad);
}

// 3
void Quad::generateParameter(const std::string argument, const std::string paramArg) {
    std::vector<std::string> tempQuad {"PARAMETER", argument, "-", paramArg}; 
    addQuad(tempQuad);
}

// 6
void Quad::addGoSub(const std::string funcId, int quadLoc) {
    std::vector<std::string> tempQuad {"GOSUB", funcId, "-", std::to_string(quadLoc)}; 
    removeFalseBottom();
    addQuad(tempQuad);
}

// RETORNO FUNCIONES
// 1
void Quad::saveReturnValue(const std::string returnValue) {
    std::vector<std::string> tempQuad {"RETURN", (*tablasDatos).currentFunc, "-", returnValue}; 
    addQuad(tempQuad);
}

// 2
void Quad::addReturnValue(const std::string funcId, const std::string returnType) {
    std::string temp = getNextAvail(returnType);
    // memory: global/local, return type, temp, 
    std::vector<std::string> tempQuad {"=", funcId, "-", temp}; 
    addQuad(tempQuad);

    sOperands.push_back(temp);
    sTypes.push_back(returnType);
}

// MAIN
// 1
void Quad::savePrincipalLoc() {
    sJumps.push_back(quadPtr);

    std::vector<std::string> tempQuad {"GOTO", "principal", "-", "-"}; 
    addQuad(tempQuad);

    // agrega al inicio dos constantes muy probables de ser utilizadas en ciclos y arreglos
    if ((*tablasDatos).constDir.count("0") <= 0) {
        int memAddr = memoria->reserveIntMemory("const", false, 1);
        if (memAddr == -1)
            std::cout << "ERROR: No se puede reservar memoria para constante '0' \n";

        (*tablasDatos).constDir["0"] = memAddr;
    }
    if ((*tablasDatos).constDir.count("1") <= 0) {
        int memAddr = memoria->reserveIntMemory("const", false, 1);
        if (memAddr == -1)
            std::cout << "ERROR: No se puede reservar memoria para constante '1' \n";

        (*tablasDatos).constDir["1"] = memAddr;
    }
}

// 3
void Quad::addGotoPrincipalLoc() {
    int principalBegin = sJumps.back();
    sJumps.pop_back();

    fillGotoQuad(principalBegin, quadPtr);
}


// UTILIDAD
std::string Quad::popOperand() {
    if (sOperands.empty()) {
        return "ERROR: Funcion no puede regresar operandos. Lista vacia\n";
    }
    std::string temp = sOperands.back();
    sOperands.pop_back();
    return temp;
}

std::string Quad::popType() {
    if (sTypes.empty()) {
        return "ERROR: Funcion no puede regresar tipo. Lista vacia\n";
    }
    std::string temp = sTypes.back();
    sTypes.pop_back();
    return temp;
}

int Quad::getQuadCont() const {
    return quadPtr;
}

void Quad::addNewTempCounter() {
    sTemps.push_back(0);
    sTempTypes.push_back({0, 0, 0, 0});
}

std::vector<int> Quad::getCurrentTempTypes() {
    if (sTemps.size() <= 0) {
        std::cout << "ERROR: No quedan contadores temporales\n";
        return {-1};
    }

    int tempsUsed = sTemps.back();
    sTemps.pop_back();

    std::vector<int> tempTypes = sTempTypes.back();
    sTempTypes.pop_back();

    return tempTypes;
}

void Quad::reserveConstValue(std::string value) {
    if ((*tablasDatos).constDir.count(value) <= 0) { // reserva valor constante en tabla de ctes.
        int memAddr = memoria->reserveIntMemory("const", false, 1);
        if (memAddr == -1)
            std::cout << "ERROR: No se puede reservar memoria para constante " +  value + " \n";

        (*tablasDatos).constDir[value] = memAddr;
    }
}

void Quad::printData() {
    std::cout << "\n---------\n";
    int quadCounter = 0;
    
    for (auto quad : quads) {
        std::cout << quadCounter++ << " " << quad[0] <<  ", " << quad[1] <<  ", " << quad[2] <<  ", " << quad[3] <<  "\n";
    }

    std::cout << "\n---------\n";
    quadCounter = 0;
    for (auto quad : memQuads) {
        std::cout << quadCounter++ << " " << quad[0] <<  ", " << quad[1] <<  ", " << quad[2] <<  ", " << quad[3] <<  "\n";
    }

    std::cout << "Operators left in stack: " << sOperators.size() << " - ";
    while(!sOperators.empty()) {
        std::cout << sOperators.back() << ", ";
        sOperators.pop_back();
    }
    std::cout << "Operands left in stack: " << sOperands.size() << " - ";
    while(!sOperands.empty()) {
        std::cout << sOperands.back() << ", ";
        sOperands.pop_back();
    }
    std::cout << "\nQuad ptr: " << quadPtr << "\n";
    std::cout << "\n---------\n";
}