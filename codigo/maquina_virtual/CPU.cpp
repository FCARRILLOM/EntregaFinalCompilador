#include "CPU.h"

void CPU::parseFile(const std::string fileName) {
    std::ifstream codeFile("../compilador/" + fileName);
    std::string codeLine;

    std::vector<std::string> funcDirData, constTableData, quadData;
    int currentDataType = 0; // 0-funcDir, 1-constTable, 2-quad

    while (std::getline(codeFile, codeLine)) {
        if (codeLine == "%%") {
            currentDataType++;
        } else {
            if (currentDataType == 0)
                funcDirData.push_back(codeLine);
            else if (currentDataType == 1)
                constTableData.push_back(codeLine);
            else
                quadData.push_back(codeLine);
        }
    }

    // parse funcDir
    for (std::string entry : funcDirData) {
        std::string name;
        int quadPos, i, f, c, ti, tf, tb;

        std::size_t start = 0U, comma = entry.find(",");
        if (comma != std::string::npos) {
            name = entry.substr(start, comma - start);
            entry.erase(start, comma+2);
        } else {
            std::cout << "ERROR: No se puede analizar la entrada funcdir name: " + entry + "\n";
        }
        comma = entry.find(",");
        if (comma != std::string::npos) {
            quadPos = stoi(entry.substr(start, comma - start));
            entry.erase(start, comma+2);
        } else {
            std::cout << "ERROR: No se puede analizar la entrada funcdir quadpos: " + entry + "\n";
        }

        std::vector<int> varSizes;
        for (int a = 0; a < 5; a++) {
            comma = entry.find(",");
            if (comma != std::string::npos) {
                varSizes.push_back(stoi(entry.substr(start, comma - start)));
                entry.erase(start, comma+2);
            } else {
                std::cout << "ERROR: No se puede analizar la entrada funcdir var size: " + entry + "\n";
            }
        }
        varSizes.push_back(stoi(entry)); // push last element after last comma

        if (varSizes.size() != 6) {std::cout << "Invalid var sizes - " << varSizes.size() << "\n";}
        std::vector<int> lVars = {varSizes[0], varSizes[1], varSizes[2]};
        std::vector<int> tempVars = {varSizes[3], varSizes[4], varSizes[5]};

        FuncEntry tempEntry {quadPos, lVars, tempVars};
        funcDir[name] = tempEntry;
        //std::cout << name << ", " << quadPos << ", " << varSizes[0] << ", " << varSizes[1] << ", " << varSizes[2] << ", " << varSizes[3];
        //std::cout << ", " << varSizes[4] << ", " << varSizes[5] << "\n";
        // program name sera sobreescrito y el ultimo dato sera el main ya que se lee al final
        programName = name;
    }

    // parse constTable
    for (std::string entry : constTableData) {
        std::string value, position;

        std::size_t start = 0U, comma = entry.find(",");
        if (comma != std::string::npos) {
            value = entry.substr(start, comma - start);
            position = entry.substr(comma+2); // ', '
            constTable[position] = value;
        } else {
            std::cout << "ERROR: No se puede analizar la entrada const table: " + entry + "\n";
        }
    }

    // parse quads
    for (std::string entry : quadData) {
        std::string op, oper1, oper2, res;

        std::size_t start = 0U, comma = entry.find(",");
        if (comma != std::string::npos) {
            op = entry.substr(start, comma - start);
            entry.erase(start, comma+2);
        } else {
            std::cout << "ERROR: No se puede analizar la entrada quad: " + entry + "\n";
        }
        comma = entry.find(",");
        if (comma != std::string::npos) {
            oper1 = entry.substr(start, comma - start);
            entry.erase(start, comma+2);
        } else {
            std::cout << "ERROR: No se puede analizar la entrada quad: " + entry + "\n";
        }
        comma = entry.find(",");
        if (comma != std::string::npos) {
            oper2 = entry.substr(start, comma - start);
            entry.erase(start, comma+2);
        } else {
            std::cout << "ERROR: No se puede analizar la entrada quad: " + entry + "\n";
        }
        res = entry;

        //std::cout << op << "," << oper1 << "," << oper2 << "," << res << std::endl;
        quads.push_back({op, oper1, oper2, res});
    }
    

    codeFile.close();
}

void CPU::runCode() {
    int insPtr = 0;
    int end = quads.size() - 1;
    int errorFound = false;

    mem.generateERAConst(constTable);
    mem.generateERAMain(funcDir[programName].numLVar, funcDir[programName].numTemp);

    while (insPtr < end && !errorFound) {
        QuadEntry quad = quads[insPtr];
        int operation = stoi(quad.op);

        //delete
        //std::cout << insPtr << " - ";
        //std::cout << quad.op << ", " << quad.oper1 << ", " << quad.oper2 << ", " << quad.res << std::endl;
        
        switch(operation) {
            case 0: { // suma
                std::string type1 = mem.getAddressType(quad.oper1);
                std::string type2 = mem.getAddressType(quad.oper2);

                if (type1 == "int" && type2 == "int") {
                    int res = mem.getIntValue(quad.oper1) + mem.getIntValue(quad.oper2);
                    mem.saveIntValue(res, quad.res);
                } else if (type1 == "int" && type2 == "float") {
                    float res = mem.getIntValue(quad.oper1) + mem.getFloatValue(quad.oper2);
                    mem.saveFloatValue(res, quad.res);
                } else if (type1 == "float" && type2 == "int") {
                    float res = mem.getFloatValue(quad.oper1) + mem.getIntValue(quad.oper2);
                    mem.saveFloatValue(res, quad.res);
                } else if (type1 == "float" && type2 == "float") {
                    float res = mem.getFloatValue(quad.oper1) + mem.getFloatValue(quad.oper2);
                    mem.saveFloatValue(res, quad.res);
                }
                break;
            }
            case 1:
            { // resta
                std::string type1 = mem.getAddressType(quad.oper1);
                std::string type2 = mem.getAddressType(quad.oper2);

                if (type1 == "int" && type2 == "int")
                {
                    int res = mem.getIntValue(quad.oper1) - mem.getIntValue(quad.oper2);
                    mem.saveIntValue(res, quad.res);
                }
                else if (type1 == "int" && type2 == "float")
                {
                    float res = mem.getIntValue(quad.oper1) - mem.getFloatValue(quad.oper2);
                    mem.saveFloatValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "int")
                {
                    float res = mem.getFloatValue(quad.oper1) - mem.getIntValue(quad.oper2);
                    mem.saveFloatValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "float")
                {
                    float res = mem.getFloatValue(quad.oper1) - mem.getFloatValue(quad.oper2);
                    mem.saveFloatValue(res, quad.res);
                }
                break;
            }
            case 2:
            { // division
                std::string type1 = mem.getAddressType(quad.oper1);
                std::string type2 = mem.getAddressType(quad.oper2);

                if (type1 == "int" && type2 == "int")
                {
                    int res = mem.getIntValue(quad.oper1) / mem.getIntValue(quad.oper2);
                    mem.saveIntValue(res, quad.res);
                }
                else if (type1 == "int" && type2 == "float")
                {
                    float res = mem.getIntValue(quad.oper1) / mem.getFloatValue(quad.oper2);
                    mem.saveFloatValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "int")
                {
                    float res = mem.getFloatValue(quad.oper1) / mem.getIntValue(quad.oper2);
                    mem.saveFloatValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "float")
                {
                    float res = mem.getFloatValue(quad.oper1) / mem.getFloatValue(quad.oper2);
                    mem.saveFloatValue(res, quad.res);
                }
                break;
            }
            case 3:
            { // multiplicacion
                std::string type1 = mem.getAddressType(quad.oper1);
                std::string type2 = mem.getAddressType(quad.oper2);

                if (type1 == "int" && type2 == "int")
                {
                    int res = mem.getIntValue(quad.oper1) * mem.getIntValue(quad.oper2);
                    mem.saveIntValue(res, quad.res);
                }
                else if (type1 == "int" && type2 == "float")
                {
                    float res = mem.getIntValue(quad.oper1) * mem.getFloatValue(quad.oper2);
                    mem.saveFloatValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "int")
                {
                    float res = mem.getFloatValue(quad.oper1) * mem.getIntValue(quad.oper2);
                    mem.saveFloatValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "float")
                {
                    float res = mem.getFloatValue(quad.oper1) * mem.getFloatValue(quad.oper2);
                    mem.saveFloatValue(res, quad.res);
                }
                break;
            }
            case 4:
            { // mayor que
                std::string type1 = mem.getAddressType(quad.oper1);
                std::string type2 = mem.getAddressType(quad.oper2);

                if (type1 == "int" && type2 == "int")
                {
                    bool res = mem.getIntValue(quad.oper1) > mem.getIntValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "int" && type2 == "float")
                {
                    bool res = mem.getIntValue(quad.oper1) > mem.getFloatValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "int")
                {
                    bool res = mem.getFloatValue(quad.oper1) > mem.getIntValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "float")
                {
                    bool res = mem.getFloatValue(quad.oper1) > mem.getFloatValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                break;
            }
            case 5:
            { // menor que
                std::string type1 = mem.getAddressType(quad.oper1);
                std::string type2 = mem.getAddressType(quad.oper2);

                if (type1 == "int" && type2 == "int")
                {
                    bool res = mem.getIntValue(quad.oper1) < mem.getIntValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "int" && type2 == "float")
                {
                    bool res = mem.getIntValue(quad.oper1) < mem.getFloatValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "int")
                {
                    bool res = mem.getFloatValue(quad.oper1) < mem.getIntValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "float")
                {
                    bool res = mem.getFloatValue(quad.oper1) < mem.getFloatValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                break;
            }
            case 6:
            { // mayor igual que
                std::string type1 = mem.getAddressType(quad.oper1);
                std::string type2 = mem.getAddressType(quad.oper2);

                if (type1 == "int" && type2 == "int")
                {
                    bool res = mem.getIntValue(quad.oper1) >= mem.getIntValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "int" && type2 == "float")
                {
                    bool res = mem.getIntValue(quad.oper1) >= mem.getFloatValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "int")
                {
                    bool res = mem.getFloatValue(quad.oper1) >= mem.getIntValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "float")
                {
                    bool res = mem.getFloatValue(quad.oper1) >= mem.getFloatValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                break;
            }
            case 7:
            { // menor igual que
                std::string type1 = mem.getAddressType(quad.oper1);
                std::string type2 = mem.getAddressType(quad.oper2);

                if (type1 == "int" && type2 == "int")
                {
                    bool res = mem.getIntValue(quad.oper1) <= mem.getIntValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "int" && type2 == "float")
                {
                    bool res = mem.getIntValue(quad.oper1) <= mem.getFloatValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "int")
                {
                    bool res = mem.getFloatValue(quad.oper1) <= mem.getIntValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "float")
                {
                    bool res = mem.getFloatValue(quad.oper1) <= mem.getFloatValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                break;
            }
            case 8:
            { // igual que
                std::string type1 = mem.getAddressType(quad.oper1);
                std::string type2 = mem.getAddressType(quad.oper2);

                if (type1 == "int" && type2 == "int")
                {
                    bool res = mem.getIntValue(quad.oper1) == mem.getIntValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "int" && type2 == "float")
                {
                    bool res = mem.getIntValue(quad.oper1) == mem.getFloatValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "int")
                {
                    bool res = mem.getFloatValue(quad.oper1) == mem.getIntValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "float")
                {
                    bool res = mem.getFloatValue(quad.oper1) == mem.getFloatValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "bool" && type2 == "bool")
                {
                    bool res = mem.getBoolValue(quad.oper1) == mem.getBoolValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                break;
            }
            case 9:
            { // no es igual que
                std::string type1 = mem.getAddressType(quad.oper1);
                std::string type2 = mem.getAddressType(quad.oper2);

                if (type1 == "int" && type2 == "int")
                {
                    bool res = mem.getIntValue(quad.oper1) != mem.getIntValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "int" && type2 == "float")
                {
                    bool res = mem.getIntValue(quad.oper1) != mem.getFloatValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "int")
                {
                    bool res = mem.getFloatValue(quad.oper1) != mem.getIntValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "float" && type2 == "float")
                {
                    bool res = mem.getFloatValue(quad.oper1) != mem.getFloatValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                else if (type1 == "bool" && type2 == "bool")
                {
                    bool res = mem.getBoolValue(quad.oper1) != mem.getBoolValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                break;
            }
            case 10:
            { // and
                std::string type1 = mem.getAddressType(quad.oper1);
                std::string type2 = mem.getAddressType(quad.oper2);

                if (type1 == "bool" && type2 == "bool")
                {
                    bool res = mem.getBoolValue(quad.oper1) && mem.getBoolValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                break;
            }
            case 11:
            { // or
                std::string type1 = mem.getAddressType(quad.oper1);
                std::string type2 = mem.getAddressType(quad.oper2);

                if (type1 == "bool" && type2 == "bool")
                {
                    bool res = mem.getBoolValue(quad.oper1) || mem.getBoolValue(quad.oper2);
                    mem.saveBoolValue(res, quad.res);
                }
                break;
            }
            case 12: { // asignacion
                std::string type1 = mem.getAddressType(quad.oper1);
                if (type1 == "int") {
                    int val = mem.getIntValue(quad.oper1);
                    mem.saveIntValue(val, quad.res);
                } else if (type1 == "float") {
                    float val = mem.getFloatValue(quad.oper1);
                    mem.saveFloatValue(val, quad.res);
                } else if (type1 == "char") {
                    char val = mem.getCharValue(quad.oper1);
                    mem.saveCharValue(val, quad.res);
                }
                break;
            }
            case 13: { // PARAMETRO
                std::string paramType = mem.getAddressType(quad.oper1);
                if (paramType == "int") {
                    int val = mem.getIntValue(quad.oper1);
                    mem.saveParameterIntValue(val, paramCounters.back()[0]);
                    paramCounters.back()[0]++;
                } else if (paramType == "float") {
                    float val = mem.getFloatValue(quad.oper1);
                    mem.saveParameterFloatValue(val, paramCounters.back()[1]);
                    paramCounters.back()[1]++;
                } else if (paramType == "char") {
                    char val = mem.getCharValue(quad.oper1);
                    mem.saveParameterCharValue(val, paramCounters.back()[2]);
                    paramCounters.back()[2]++;
                }
                break;
            }
            case 14: { // GoToF
                bool res = mem.getBoolValue(quad.oper1);
                if (!res) {
                    int falseLoc = stoi(quad.res);
                    insPtr = falseLoc - 1; // -1 porque al finall switch hace ++
                }
                break;
            }
            case 15: { // GOSUB
                gosubCheckpoint.push_back(insPtr);
                mem.changeToNewContext();
                int subLoc = stoi(quad.res);
                insPtr = subLoc - 1; // -1 porque al finall switch hace ++
                break;
            }
            case 16: { // GOTO
                insPtr = stoi(quad.res) - 1; // -1 porque al finall switch hace ++
                break;
            }
            case 17: { // ERA
                currentFunc.push_back(quad.oper1);
                mem.generateERAFunc(funcDir[quad.oper1].numLVar, funcDir[quad.oper1].numTemp);
                paramCounters.push_back({0, 0, 0});
                break;
            }
            case 18: { // ENDFUNC
                mem.removeERAFunc(funcDir[currentFunc.back()].numLVar, funcDir[currentFunc.back()].numLVar);
                mem.changeContextBack();
                currentFunc.pop_back();
                insPtr = gosubCheckpoint.back();
                gosubCheckpoint.pop_back();
                paramCounters.pop_back();
                break;
            }
            case 19: { // write
                std::string printType = mem.getAddressType(quad.res);
                if (printType == "int") {
                    std::cout << mem.getIntValue(quad.res) << "\n";
                } else if (printType == "float") {
                    std::cout << mem.getFloatValue(quad.res) << "\n";
                } else if (printType == "char") {
                    std::cout << mem.getCharValue(quad.res) << "\n";
                } else if (printType == "string") {
                    std::cout << quad.res << "\n";
                }
                break;
            }
            case 20: { // read
                std::string readType = mem.getAddressType(quad.res);
                std::cout << "Lectura: ";
                if (readType == "int") {
                    int userInput;
                    std::cin >> userInput;
                    mem.saveIntValue(userInput, quad.res);
                } else if (readType == "float") {
                    float userInput;
                    std::cin >> userInput;
                    mem.saveFloatValue(userInput, quad.res);
                } else if (readType == "char") {
                    char userInput;
                    std::cin >> userInput;
                    mem.saveCharValue(userInput, quad.res);
                }
                break;
            }
            case 21: { // return
                // TODO: jump out of function andlete ERA ENDFUNC)
                std::string varType = mem.getAddressType(quad.res);
                if (varType == "int") {
                    mem.saveIntValue(mem.getIntValue(quad.res), quad.oper1);
                } else if (varType == "float") {
                    mem.saveFloatValue(mem.getFloatValue(quad.res), quad.oper1);
                } else if (varType == "char") {
                    mem.saveCharValue(mem.getCharValue(quad.res), quad.oper1);
                }
                break;
            }
            case 22: { // END
                break;
            }
            case 23: { // VER
                int idx = mem.getIntValue(quad.oper1);
                int linf = mem.getIntValue(quad.oper2);
                int lsup = mem.getIntValue(quad.res);
                if (idx < linf || idx > lsup) {
                    std::cout << "ERROR: Índice " << idx << " fuera de los límites [";
                    std::cout <<  linf << ", " << lsup << "]\n";
                    errorFound = true;
                }
                break;
            }

        }

        insPtr++;
    }

    // getAddr(di1) getAddr(Dir2) if (dir1 == int and dir2 == int) int res = getIntvalue(dir1) + getIntValue(Dir2) memory.saveInt(dirRes, res)

}