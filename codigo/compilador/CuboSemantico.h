#ifndef CUBO_SEMANTICO_H
#define CUBO_SEMANTICO_H

#include <unordered_map>
#include <string>
#include <vector>

/*
Esta clase tiene la funcion que mapear cada combinacion de las operaciones validas entre dos operandos y el
tipo resultante de esa operación.
También mapea los tipos a su representación numérica y las operaciones a su representación numérica
*/

class CuboSemantico {
private:
    std::vector<std::vector<std::vector<std::string>>> cubo {
    { // int
            // +,    -,     /,     *,     >,     <,      >=,      <=,     ==,     <>,     &,     |,     =
        { // int
            "int", "int", "int", "int", "bool", "bool", "bool", "bool", "bool", "bool", "err", "err", "int"
        }, 
        { // float
            "float", "float", "float", "float", "bool", "bool", "bool", "bool", "bool", "bool", "err", "err", "err"
        }, 
        { // char
            "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err"
        }, 
        { // bool
            "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err"
        }
    }, 
    { // float
        {},
        { // float
            "float", "float", "float", "float", "bool", "bool", "bool", "bool", "bool", "bool", "err", "err", "float"
        }, 
        { // char
            "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err"
        }, 
        { // bool
            "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err"
        }
    }, 
    { // char
        {}, {},
        { // char
            "err", "err", "err", "err", "err", "err", "err", "err", "bool", "bool", "err", "err", "char"
        }, 
        { // bool
            "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err", "err"
        }
    }, 
    { // bool
        {}, {}, {},
        { // bool
            "err", "err", "err", "err", "err", "err", "err", "err", "bool", "bool", "bool", "bool", "bool"
        }
    }
    };

public:
    std::unordered_map<std::string, int> typeMap {
        {"int", 0},
        {"float", 1},
        {"char", 2},
        {"bool", 3},
        {"custom", 4},
        {"void", 5}
    };

    std::unordered_map<std::string, int> operatorMap {
        {"+", 0},
        {"-", 1},
        {"/", 2},
        {"*", 3},
        {">", 4},
        {"<", 5},
        {">=", 6},
        {"<=", 7},
        {"==", 8},
        {"<>", 9},
        {"&", 10},
        {"|", 11},
        {"=", 12},
        {"PARAMETER", 13},
        {"GotoF", 14},
        {"GOSUB", 15},
        {"GOTO", 16},
        {"ERA", 17},
        {"ENDFUNC", 18},
        {"write", 19},
        {"read", 20},
        {"RETURN", 21},
        {"END", 22},
        {"VER", 23}
    };

    // Regresa el tipo resultante de aplicar una operacion con dos operandos
    std::string getTypeFromCube(std::string left_type, std::string right_type, std::string op) {
        int left_idx, right_idx, op_idx;

        if (typeMap.count(left_type) < 1) {
            return "err: Tipo del operando izquierdo invalido";
        } else {
            left_idx = typeMap[left_type];
        }

        if (typeMap.count(right_type) < 1) {
            return "err: Tipo del operando derecho invalido";
        } else {
            right_idx = typeMap[right_type];
        }

        if (operatorMap.count(op) < 1) {
            return "err: Operador '" + op + "' invalido";
        } else {
            op_idx = operatorMap[op];
        }

        // left value is always the smallest
        if (right_idx < left_idx) {
            std::swap(right_idx, left_idx);
        }

        std::string result =  cubo[left_idx][right_idx][op_idx];

        if (result == "err") return "err: Type mismatch - '" + left_type + "' y '" + right_type + "' con operador '" + op + "'.";
        else return result;
    }

};

#endif