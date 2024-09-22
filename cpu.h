#ifndef _CPU_H_
#define _CPU_H_

#include<vector>
#include<string>
#include<iostream>
#include<sstream>
#include<unordered_map>

class CPU{
private:
    std::unordered_map<std::string, int> registers;
    int pc;
    std::vector<std::string> memory;

public:
    CPU(): pc(0){
        registers["A"]=0;
        registers["B"]=0;
        registers["C"]=0;
        registers["D"]=0;
    }

    void load_program(const std::vector<std::string>& program){
        memory = program;
    }

    std::string fetch(){
        if(pc<memory.size()){
            return memory[pc++];
        }
        return "HALT";
    }

    void decode_and_execute(const std::string& instruction){
        std::istringstream iss(instruction);
        std::string opcode;
        iss>> opcode;

        if (opcode=="MOV"){
            std::string reg;
            int value;
            iss>>reg>>value;
            registers[reg]=value;
        }else if(opcode =="ADD"){
            std::string reg1, reg2;
            iss>>reg1>>reg2;
            registers[reg1]+=registers[reg2];
        }else if(opcode=="SUB"){
            std::string reg1, reg2;
            iss>>reg1>>reg2;
            registers[reg1]-=registers[reg2];
        }else if(opcode=="PRINT"){
            std::string reg;
            iss>>reg;
            std::cout<<reg<<":"<<registers[reg]<<std::endl;
        }
    }
void run(){
    while(pc<memory.size()){
        std::string instruction= fetch();
        if(instruction=="HALT") break;
        decode_and_execute(instruction);
    }

}

};

#endif