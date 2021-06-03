#include <iostream>
#include <string>

#include "CPU.h"

CPU cpu;

int main(int argc, char ** argv) {
    /*
    if (argc < 2) {
        std::cout << "Warning: code file not named\n";
    } else {
        std::string codeName = argv[1];
        cpu.readFile(codeName);
    }
    */

    cpu.parseFile("codigo.cmm");

    cpu.runCode();

    std::cout << "---End---\n";

    return 0;
}