#include<vector>
#include "cpu.h"

int main(){
        std::vector<std::string> program = {
        "MOV A 5",
        "MOV B 10",
        "ADD A B",
        "PRINT A",
        "SUB A B",
        "PRINT A",
        "HALT"
    };

    CPU cpu;
    cpu.load_program(program);
    cpu.run();

    return 0;

}