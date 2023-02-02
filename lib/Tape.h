#ifndef YADRO_TEST_TASK_TAPE_H
#define YADRO_TEST_TASK_TAPE_H

#include <utility>

#include "stdexcept"
#include "fstream"
#include "iostream"
#include "cstdlib"
#include <filesystem>

#include "unistd.h"

template <typename T>
class Tape {
private:
    std::fstream file;
    std::fstream config;
    size_t size;
    size_t current;
    std::string fileName;
    int readDelay{};
    int writeDelay{};
    int moveDelay{};
    int moveNextDelay{};

    void Wait(int time);
public:
    explicit Tape();

    ~Tape();

    void SetConfig();

    void Write(T information);

    void Move(int steps);

    T Read();
};

template<typename T> void Tape<T>::Wait(int time) {
    sleep(time);
}

template<typename T> Tape<T>::Tape(){
    config.open("config.txt", std::fstream::in);
    if(config.fail()){
        config.open("config.txt", std::fstream::out | std::fstream::trunc);
        std::cout << "Write file name" << std::endl;
        std::cin >> fileName;
        config << fileName.insert(0,"tapes/") << " ";
        std::cout << "Write tape size"<< std::endl;
        std::cin >> size;
        config << size << " ";
        std::cout << "Write read delay"<< std::endl;
        std::cin >> readDelay;
        config << readDelay << " ";
        std::cout << "Write write delay"<< std::endl;
        std::cin >> writeDelay;
        config << writeDelay << " ";
        std::cout << "Write Move delay"<< std::endl;
        std::cin >> moveDelay;
        config << moveDelay << " ";
        std::cout << "Write Move to next delay"<< std::endl;
        std::cin >> moveNextDelay;
        config << moveNextDelay << " ";
        std::filesystem::create_directory("tmp");
        std::filesystem::create_directory("tapes");
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

template<typename T> Tape<T>::~Tape(){
    config.close();
    file.close();
}

template<typename T> void Tape<T>::SetConfig(){
    config.open("config.txt", std::fstream::out | std::fstream::trunc);
    config.clear();
    std::cout << "Current file name: " << fileName << std::endl;
    std::cout << "Write file name" << std::endl;
    std::cin >> fileName;
    config << fileName << " ";
    std::cout << "Current tape size: " << size << std::endl;
    std::cout << "Write tape size"<< std::endl;
    std::cin >> size;
    config << size << " ";
    std::cout << "Current read delay: " << readDelay << std::endl;
    std::cout << "Write read delay"<< std::endl;
    std::cin >> readDelay;
    config << readDelay << " ";
    std::cout << "Current write delay: " << writeDelay << std::endl;
    std::cout << "Write write delay"<< std::endl;
    std::cin >> writeDelay;
    config << writeDelay << " ";
    std::cout << "Current Move delay: " << moveDelay << std::endl;
    std::cout << "Write Move delay"<< std::endl;
    std::cin >> moveDelay;
    config << moveDelay << " ";
    std::cout << "Current Move to next delay: " << moveNextDelay << std::endl;
    std::cout << "Write Move to next delay"<< std::endl;
    std::cin >> moveNextDelay;
    config << moveNextDelay << " ";
    file.open(fileName, std::fstream::in | std::fstream::out);
    if (file.fail()){
        file.open(fileName, std::fstream::in | std::fstream::out | std::fstream::trunc);
    }
}

template<typename T> void Tape<T>::Write(T information){
    file.seekg(0);
    std::string tmp;
    for (int i = 0; i < current; ++i) {
        std::getline(file,tmp);
    }
    file.seekp(file.tellg());
    file << information << " ";
    Wait(writeDelay);
}

template<typename T> void Tape<T>::Move(int steps){
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

template<typename T> T Tape<T>::Read(){
    file.seekg(0);
    std::string tmp;
    for (int i = 0; i < current; ++i) {
        std::getline(file,tmp);
    }
    T output;
    file >> output;
    Wait(readDelay);
    return output;
}


#endif //YADRO_TEST_TASK_TAPE_H
