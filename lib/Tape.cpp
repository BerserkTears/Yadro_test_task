//
// Created by Кирилл Куницын on 28.01.2023.
//

#include "Tape.h"


void Tape::Wait(int time) {
    sleep(time);
}

Tape::Tape(std::string configName){
    configName.insert(0,"cfg/");
    config.open(configName, std::fstream::in);
    if(config.fail()){
        throw std::invalid_argument("No such file");
    } else {
        config >> fileName;
        config >> size;
        config >> readDelay;
        config >> writeDelay;
        config >> moveDelay;
        config >> moveNextDelay;
    }
    file.open(fileName, std::fstream::in | std::fstream::out);
    if (file.fail()){
        file.open(fileName, std::fstream::in | std::fstream::out | std::fstream::trunc);
        for (int i = 0; i < size - 1; ++i) {
            file << "            \r\n";
        }
        file << "            ";
    }
    current = 0;
}

Tape::Tape(std::string configN, std::string fileN, size_t size1, int readD, int writeD, int moveD, int moveNextD){
    configN.insert(0,"cfg/");
    std::filesystem::create_directory("cfg");
    fileN.insert(0,"tapes/");
    config.open(configN, std::fstream::out | std::fstream::trunc);
    fileName = fileN;
    config << fileName << " ";
    size = size1;
    config << size << " ";
    readDelay = readD;
    config << readDelay << " ";
    writeDelay = writeD;
    config << writeDelay << " ";
    moveDelay = moveD;
    config << moveDelay << " ";
    moveNextDelay = moveNextD;
    config << moveNextDelay << " ";
    std::filesystem::create_directory("tmp");
    std::filesystem::create_directory("tapes");
    file.open(fileName, std::fstream::in | std::fstream::out);
    if (file.fail()){
        file.open(fileName, std::fstream::in | std::fstream::out | std::fstream::trunc);
        for (int i = 0; i < size - 1; ++i) {
            file << "            \r\n";
        }
        file << "            ";
    }
    current = 0;
}

Tape::~Tape(){
    config.close();
    file.close();
}

void Tape::SetConfig(std::string configName){
    configName.insert(0,"cfg/");
    config.open(configName, std::fstream::in);
    if(config.fail()){
        throw std::invalid_argument("No such file");
    } else {
        config >> fileName;
        config >> size;
        config >> readDelay;
        config >> writeDelay;
        config >> moveDelay;
        config >> moveNextDelay;
    }
    file.open(fileName, std::fstream::in | std::fstream::out);
    if (file.fail()){
        file.open(fileName, std::fstream::in | std::fstream::out | std::fstream::trunc);
        for (int i = 0; i < size - 1; ++i) {
            file << "            \r\n";
        }
        file << "            ";
    }
    current = 0;
}

void Tape::SetConfig(std::string configN, std::string fileN, size_t size1, int readD, int writeD, int moveD, int moveNextD){
    configN.insert(0,"cfg/");
    std::filesystem::create_directory("cfg");
    fileN.insert(0,"tapes/");
    config.open(configN, std::fstream::out | std::fstream::trunc);
    fileName = fileN;
    config << fileName << " ";
    size = size1;
    config << size << " ";
    readDelay = readD;
    config << readDelay << " ";
    writeDelay = writeD;
    config << writeDelay << " ";
    moveDelay = moveD;
    config << moveDelay << " ";
    moveNextDelay = moveNextD;
    config << moveNextDelay << " ";
    std::filesystem::create_directory("tmp");
    std::filesystem::create_directory("tapes");
    current = 0;
}
void Tape::Write(int information){
    file.seekg(0);
    std::string tmp;
    for (int i = 0; i < current; ++i) {
        std::getline(file,tmp);
    }
    file.seekp(file.tellg());
    file << information << " ";
    Wait(writeDelay);
}

void Tape::Move(int steps){
    current += steps;
    if (current > size - 1)
        throw std::out_of_range("Out of range of Tape");
    if (current < 0)
        throw std::out_of_range("Out of range of Tape");
    if (steps == 1 || steps == -1)
        Wait(moveNextDelay);
    else
        Wait(moveDelay);
}

int Tape::Read(){
    file.seekg(0);
    std::string tmp;
    for (int i = 0; i < current; ++i) {
        std::getline(file,tmp);
    }
    int output;
    file >> output;
    Wait(readDelay);
    return output;
}